// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "eeconfig.h"
#include "led.h"
#include "process_unicode.h"
#include "emojis.h"
#include "quantum.h"


extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _GAM3R 2
#define _SPCFN 3
#define _LOWER 4
#define _RAISE 5
#define _GAMUP 8
#define _FUNC 10
#define _MOUS 12
#define _ADJUST 16

#define KC_SPFN LT(_SPCFN, KC_SPC) // press for space, hold for function layer (aka spacefn)
#define KC_BKFN LT(_SPCFN, KC_BSPC)
// use tap dancing to set caps lock
#define TD_ESC 0
#define HYPER MT(MOD_HYPR, KC_ENT)
#define KC_TABM LT(_MOUS, KC_TAB)
#define APPTOG LGUI(KC_TAB)
#define APPWIN LGUI(KC_GRV)
#define ENDLIN LGUI(KC_RGHT)
#define SRTLIN LGUI(KC_LEFT)
#define SPCRGT LCTL(KC_RGHT)
#define SPCLFT LCTL(KC_LEFT)
#define ENTSFT SFT_T(KC_ENT)
#define CTLESC CTL_T(KC_ESC)
#define VOLUP  S(LALT(KC_VOLU))
#define VOLDN  S(LALT(KC_VOLD))
#define POWER S(LCTL(KC_POWER))


enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  GAM3R,
  GAMEUP,
  LOWER,
  RAISE,
  FUNC,
  BELOW,
  ABOVE,
  TABM
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO


/*qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS)
  };*/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_QWERTY] = {
  {KC_TABM, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {CTLESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, ENTSFT },
  {FUNC, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPFN,  KC_SPFN,   RAISE,   KC_RGUI, KC_RALT, KC_RCTL, FUNC}
},


[_COLEMAK] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC},
  {KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, ENTSFT},
  {FUNC , KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPFN,  KC_SPFN,  RAISE,   KC_RGUI, KC_RALT,   KC_RCTL, FUNC }

},


[_GAM3R] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {CTLESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, ENTSFT },
  {GAMEUP,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,  KC_SPC, KC_SPC,   RAISE,   KC_RGUI, KC_RALT, KC_RCTL,  FUNC}
},

[_GAMUP] = {
    {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, _______, _______, _______, _______},
    {_______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, _______, _______, _______, _______},
    {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, _______, _______, _______, _______},
    {_______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, _______, _______, _______, _______, _______},
},


[_LOWER] = {
  {APPTOG,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,  KC_BSPC},
  {APPWIN,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______},
  {_______, _______, KC_LCBR, KC_LBRC, KC_LPRN, KC_PIPE, KC_BSLS, KC_LPRN, KC_LBRC, KC_LCBR, _______, _______}, 
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},

[_RAISE] = {
  {LGUI(LSFT(KC_4)), _______, _______, _______, LGUI(KC_R), _______, _______, _______, X(CRY), X(GRIN), X(COOL), X(SKULL)},
  {_______, LGUI(KC_A), LGUI(KC_S), LGUI(KC_D), _______, _______, _______, _______, X(THMUP), X(THMDN), X(VIC), X(CLAP)},
  {_______, _______, _______, LGUI(KC_C), LGUI(KC_V), _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

[_ADJUST] = {
  {RESET  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, GAM3R, _______,  _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }
},

[_FUNC] = {
  {RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX, KC_7,  KC_8,  KC_9, KC_PLUS,  VOLUP  },
  {XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX, KC_4,  KC_5,  KC_6, KC_MINS,  VOLDN  },
  {KC_CAPS, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_0,    KC_1,  KC_2,  KC_3, KC_ASTR,  KC_MUTE},
  {_______, KC_LSFT, _______, POWER , KC_MPRV, KC_MPLY, KC_MPLY, KC_MNXT, HYPER , _______, KC_RSFT, _______}
},


[_SPCFN] = {
  {KC_TILD, _______, _______, KC_PGUP, _______, KC_LBRC, KC_RBRC, SRTLIN , KC_UP  , ENDLIN , KC_PGUP, KC_DEL  },
  {KC_GRV,  _______, SPCLFT , KC_PGDN, SPCRGT , KC_LCBR, KC_RCBR, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______ },
  {_______, _______, _______, _______, _______, KC_LPRN, KC_RPRN, _______, _______, _______, _______, _______ },
  {BL_TOGG, BL_STEP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }
},

/* Mouse layer */
[_MOUS] = {
  {_______, KC_ACL2, KC_ACL1, KC_ACL0,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX },
  {_______, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX },
  {XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
  {XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, KC_BTN1, _______, _______, KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX }
}


};


void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
/*
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt){
  switch(id){
  }
}
*/
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        breathing_disable();
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_COLEMAK);
        breathing_disable();
      }
      return false;
      break;
    case GAM3R:
      if(record->event.pressed) {
        breathing_speed_set(3);
        breathing_enable();

        persistant_default_layer_set(1UL<<_GAM3R);
      }
      return false;
      break;
    case GAMEUP:
        if(record->event.pressed){
            layer_on(_GAMUP);
        } else {
            layer_off(_GAMUP);
        }
        return false;
        break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
   case FUNC:
      if (record->event.pressed) {
        layer_on(_FUNC);
      } else {
        layer_off(_FUNC);
      }
      return false;
      break;
  case BELOW:
    if (record->event.pressed) {
      register_code(KC_LGUI);
      register_code(KC_RGHT);
      unregister_code(KC_RGHT);
      unregister_code(KC_LGUI);
      register_code(KC_ENT);
      unregister_code(KC_ENT);
    }
    return false;
    break;
  case ABOVE:
    if (record->event.pressed) {
      register_code(KC_LGUI);
      register_code(KC_LEFT);
      unregister_code(KC_LEFT);
      unregister_code(KC_LGUI);
      register_code(KC_ENT);
      unregister_code(KC_ENT);
      register_code(KC_UP);
      unregister_code(KC_UP);
    }
    return false;
    break;
  }
  return true;
}

void matrix_init_user(void) {
  set_unicode_input_mode(UC_OSX);
}


