#include "clueboard.h"

enum {
  QWER = 0, // Qwerty
  TAR1,     // Tarmak 1
  TAR2,     // Tarmak 2
  TAR3,     // Tarmak 3
  TAR4,     // Tarmak 4
  COLM,     // Colemak
  DVOR,     // Dvorak
  CURS,     // Cursor Navigation
  CNFG      // Config
};

enum {
  M_ENTUP = SAFE_RANGE, // Open up a line above the cursor
  M_ENTDN,              // Open up a line below the cursor
  M_ENTCM,              // Open up a line below the cursor with a comma ,
  M_ENTBR,              // Open up a line below the cursor with a brace {
  M_DPIP,               // Double pipe || (or in many languages)
  M_DAMP,               // Double ampersand && (and in many languages)
  M_SFLK,               // Shift Lock
  M_NMTGL,              // Number Toggle
  M_BRSWP,              // Braces Toggle [] vs. {}
  MC_LBRC,
  MC_RBRC,
  M_CTRSF,
  M_ALTSF,
  DL_QWER,
  DL_TAR1,
  DL_TAR2,
  DL_TAR3,
  DL_TAR4,
  DL_COLM,
  DL_DVOR,
  DYNAMIC_MACRO_RANGE
};

#include "dynamic_macro.h"

#define TAP(key) \
  register_code(key); \
  unregister_code(key)

#define TAP_WITH_MOD(mod, key) \
  register_code(mod); \
  register_code(key); \
  unregister_code(key); \
  unregister_code(mod)

#define TAP_WITH_2MODS(mod1, mod2, key) \
  register_code(mod1); \
  register_code(mod2); \
  register_code(key); \
  unregister_code(key); \
  unregister_code(mod2); \
  unregister_code(mod1)

#define DYNM_R1 DYN_REC_START1
#define DYNM_P1 DYN_MACRO_PLAY1
#define DYNM_R2 DYN_REC_START2
#define DYNM_P2 DYN_MACRO_PLAY2
#define DYNM_ST DYN_REC_STOP

#define LT_CURS LT(CURS, KC_SPC)
#define LT_CNFG MO(CNFG)

#define BM_SGE MAGIC_SWAP_GRAVE_ESC
#define BM_UGE MAGIC_UNSWAP_GRAVE_ESC
#define BM_SBB MAGIC_SWAP_BACKSLASH_BACKSPACE
#define BM_UBB MAGIC_UNSWAP_BACKSLASH_BACKSPACE

#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define X       KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[QWER] = KEYMAP(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DELT, M_NMTGL,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          M_BRSWP,
  KC_LEAD, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, X,       KC_ENT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ESC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, M_SFLK,  KC_UP,
  M_CTRSF, KC_LGUI, KC_LCTL, KC_LALT, LT_CURS, LT_CURS,                   KC_RALT, KC_RCTL, KC_MENU, M_ALTSF, KC_LEFT, KC_DOWN, KC_RGHT),
[TAR1] = KEYMAP(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, KC_J,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
  _______, _______, _______, _______, _______, _______, _______, KC_N,    KC_E,    _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_K,    _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______),
[TAR2] = KEYMAP(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, KC_F,    _______, KC_G,    _______, _______, _______, _______, _______, _______, _______, _______,          _______,
  _______, _______, _______, _______, KC_T,    KC_J,    _______, KC_N,    KC_E,    _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_K,    _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______),
[TAR3] = KEYMAP(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, KC_F,    KC_J,    KC_G,    _______, _______, _______, _______, _______, _______, _______, _______,          _______,
  _______, _______, KC_R,    KC_S,    KC_T,    KC_D,    _______, KC_N,    KC_E,    _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_K,    _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______),
[TAR4] = KEYMAP(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, KC_F,    KC_P,    KC_G,    KC_J,    _______, _______, KC_Y,    KC_SCLN, _______, _______, _______,          _______,
  _______, _______, KC_R,    KC_S,    KC_T,    KC_D,    _______, KC_N,    KC_E,    _______, KC_O,    _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_K,    _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______),
[COLM] = KEYMAP(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______, _______, _______,          _______,
  _______, _______, KC_R,    KC_S,    KC_T,    KC_D,    _______, KC_N,    KC_E,    KC_I,    KC_O,    _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_K,    _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______),
[DVOR] = KEYMAP(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______,
  _______, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, KC_PLUS, KC_BSLS,          _______,
  _______, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS, _______, _______,
  _______, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_ESC,  KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______),
[CURS] = KEYMAP(
  KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F13,  KC_F14,  RESET,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_Y,    KC_HOME, KC_UP,   KC_END,  KC_COPY, MC_LBRC, MC_RBRC, XXXXXXX,          LT_CNFG,
  _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, KC_CUT,  XXXXXXX, XXXXXXX, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, KC_PASTE,XXXXXXX, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______),
[CNFG] = KEYMAP(
  BM_SGE,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BM_UBB,  BM_UBB,  XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BM_SBB,           XXXXXXX,
  XXXXXXX, DL_QWER, DL_TAR1, DL_TAR2, DL_TAR3, DL_TAR4, DL_COLM, DL_DVOR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_ASDN, KC_ASUP, KC_ASRP, XXXXXXX, XXXXXXX, BM_UGE,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, AG_NORM, _______, XXXXXXX,                   AG_SWAP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool shift_lock = false;
bool number_toggle = false;
bool brace_toggle = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t mods;

  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }

  if (record->event.pressed) {
    if (keycode == KC_ENT) {
      mods = get_mods();

      if (mods & (MOD_BIT(KC_LCTL)) && mods & (MOD_BIT(KC_LSFT))) {
        keycode = M_ENTCM;
      } else if (mods & (MOD_BIT(KC_LCTL)|MOD_BIT(KC_RCTL))) {
        keycode = M_ENTUP;
      } else if (mods & (MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))) {
        keycode = M_ENTDN;
      } else if (mods & (MOD_BIT(KC_LSFT)|MOD_BIT(KC_RSFT))) {
        keycode = M_ENTBR;
      }
    }

    switch (keycode) {
      case DL_QWER:
        persistent_default_layer_set(1UL<<QWER);
        return false;

      case DL_TAR1:
        persistent_default_layer_set(1UL<<TAR1);
        return false;

      case DL_TAR2:
        persistent_default_layer_set(1UL<<TAR2);
        return false;

      case DL_TAR3:
        persistent_default_layer_set(1UL<<TAR3);
        return false;

      case DL_TAR4:
        persistent_default_layer_set(1UL<<TAR4);
        return false;

      case DL_COLM:
        persistent_default_layer_set(1UL<<COLM);
        return false;

      case DL_DVOR:
        persistent_default_layer_set(1UL<<DVOR);
        return false;

      case M_CTRSF:
        register_code(KC_LCTL);
        register_code(KC_LSFT);
        return false;

      case M_ALTSF:
        register_code(KC_LALT);
        register_code(KC_LSFT);
        return false;

      case M_ENTUP:
        SEND_STRING(SS_TAP(X_HOME)"\n"SS_TAP(X_UP));
        return false;

      case M_ENTDN:
        SEND_STRING(SS_TAP(X_END)"\n");
        return false;

      case M_ENTCM:
        SEND_STRING(SS_TAP(X_END)" ,\n");
        return false;

      case M_ENTBR:
        SEND_STRING(SS_TAP(X_END)" {\n");
        return false;

      case M_DPIP:
        SEND_STRING("||");
        return false;

      case M_DAMP:
        SEND_STRING("&&");
        return false;

      case M_SFLK:
        shift_lock = !shift_lock;
        return false;

      case M_NMTGL:
        number_toggle = !number_toggle;
        return false;

      case M_BRSWP:
        brace_toggle = !brace_toggle;
        return false;

      case KC_1:
      case KC_2:
      case KC_3:
      case KC_4:
      case KC_5:
      case KC_6:
      case KC_7:
      case KC_8:
      case KC_9:
      case KC_0:
        if (number_toggle) {
          uint16_t mod_code = KC_NO;

          if (get_mods() & MOD_BIT(KC_LSFT)) {
            mod_code = KC_LSFT;
          } else if (get_mods() & MOD_BIT(KC_RSFT)) {
            mod_code = KC_RSFT;
          }

          if (mod_code != KC_NO) {
            unregister_code(mod_code);
            register_code(keycode);
            unregister_code(keycode);
            register_code(mod_code);
          } else {
            register_code(KC_LSFT);
            register_code(keycode);
            unregister_code(keycode);
            unregister_code(KC_LSFT);
          }

          return false;
        }

        return true;

      case KC_LBRC:
      case KC_RBRC:
      case KC_BSLS:
        if (brace_toggle) {
          uint16_t mod_code = KC_NO;

          if (get_mods() & MOD_BIT(KC_LSFT)) {
            mod_code = KC_LSFT;
          } else if (get_mods() & MOD_BIT(KC_RSFT)) {
            mod_code = KC_RSFT;
          }

          if (mod_code != KC_NO) {
            unregister_code(mod_code);
            register_code(keycode);
            unregister_code(keycode);
            register_code(mod_code);
          } else {
            register_code(KC_LSFT);
            register_code(keycode);
            unregister_code(keycode);
            unregister_code(KC_LSFT);
          }

          return false;
        }

        return true;

      case MC_LBRC:
        register_code(KC_LBRC);
        unregister_code(KC_LBRC);
        return false;

      case MC_RBRC:
        register_code(KC_RBRC);
        unregister_code(KC_RBRC);
        return false;

      default:
        if (shift_lock) {
          register_code(KC_LSFT);
        }
    }
  } else {
    switch (keycode) {
      case M_CTRSF:
        unregister_code(KC_LSFT);
        unregister_code(KC_LCTL);
        return false;

      case M_ALTSF:
        unregister_code(KC_LSFT);
        unregister_code(KC_LALT);
        return false;
    }

    if (shift_lock) {
      unregister_code(KC_LSFT);
    }
  }

	return true;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    //
    // F leader
    //

    // Find
    SEQ_TWO_KEYS(KC_F, KC_F) {
      TAP_WITH_MOD(KC_LCTL, KC_F);
    }

    // Find and Replace
    SEQ_TWO_KEYS(KC_F, KC_R) {
      TAP_WITH_MOD(KC_LCTL, KC_H);
    }

    // Find in Files
    SEQ_THREE_KEYS(KC_F, KC_I, KC_F) {
      TAP_WITH_2MODS(KC_LCTL, KC_LSFT, KC_F);
    }

    // Find and Replace in Files
    SEQ_THREE_KEYS(KC_F, KC_R, KC_F) {
      TAP_WITH_2MODS(KC_LCTL, KC_LSFT, KC_H);
    }

    // File Save
    SEQ_TWO_KEYS(KC_F, KC_S) {
      TAP_WITH_MOD(KC_LCTL, KC_S);
    }

    // File Open
    SEQ_TWO_KEYS(KC_F, KC_O) {
      TAP_WITH_MOD(KC_LCTL, KC_P);
    }
  }
}
