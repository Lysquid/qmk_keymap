#include "oneshot.h"
#include "action_util.h"

void update_oneshot(
    oneshot_state *state,
    uint16_t mod,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record
) {
    if (keycode == trigger) {
        if (record->event.pressed) {
            // Trigger keydown
            if (*state == oc_up_unqueued || *state == oc_up_queued) {
                register_code(mod);
            }
            *state = oc_down_unused;
        } else {
            // Trigger keyup
            switch (*state) {
            case oc_down_unused:
                // If we didn't use the mod while trigger was held, queue it.
                *state = oc_up_queued;
                unregister_code(mod);
                break;
            case oc_down_used:
                // If we did use the mod while trigger was held, unregister it.
                *state = oc_up_unqueued;
                unregister_code(mod);
                break;
            default:
                break;
            }
        }
    } else {
        if (record->event.pressed) {
            if (is_oneshot_cancel_key(keycode) && *state != oc_up_unqueued) {
                // Cancel oneshot on designated cancel keydown.
                *state = oc_up_unqueued;
                unregister_code(mod);
            }
            if (!is_oneshot_ignored_key(keycode)) {
                // On non-ignored keydown, consider the oneshot used.
                switch (*state) {
                case oc_down_unused:
                    *state = oc_down_used;
                    break;
                case oc_up_queued:
                    *state = oc_up_unqueued;
                    set_oneshot_mods(get_oneshot_mods() | MOD_BIT(mod));
                    break;
                default:
                    break;
                }
            }
        }
    }
}
