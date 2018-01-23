#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

#define LEADER_TIMEOUT 600
#define AUTO_SHIFT_TIMEOUT 145
#define PREVENT_STUCK_MODIFIERS
#define PERMISSIVE_HOLD
//#define TAPPING_TERM 100


#define KEYMAP_JD45V2( \
	K01, K02, K03, K04, K05, K06, K07, K08, K09, K10, K11, K12, K13, \
	K14, K15, K16, K17, K18, K19, K20, K21, K22, K23, K24, K25, \
	K26, K27, K28, K29, K30, K31, K32, K33, K34, K35, K36, K37, \
	K38, K39, K40, K41, K42, K43, K44, K45, K46, K47 \
) { \
	{ K01, K02, K03, K04, K05, K06, K07, K08, K09, K10, K11, K12, K13 }, \
	{ K14, K15, K16, K17, K18, K19, K20, K21, K22, K23, K24, K25, KC_NO    }, \
	{ K26, K27, K28, K29, K30, K31, K32, K33, K34, K35, K36, K37, KC_NO    }, \
	{ K38, K39, K40, K41, K42, KC_NO,    K43, KC_NO,    K44, K45, K46, K47, KC_NO    }  \
}

#endif
