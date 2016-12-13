/*
   Hand wired keymap
*/

#include "planck.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "eeconfig.h"
#include "led.h"
#ifdef BACKLIGHT_ENABLE
  #include "backlightconfig.h"
#endif

#include "quantum.h"
#include "process_unicode.h"


extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _WORKMAN 1
#define _GAM3R 2
#define _GAMUP 4
#define _SPCFN 6
#define _LOWER 8
#define _RAISE 10
#define _FUNC 11
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
#define CTLESC CTL_T(KC_ESC)
#define ENTSFT SFT_T(KC_ENT)
#define VOLUP  S(LALT(KC_VOLU))
#define VOLDN  S(LALT(KC_VOLD))
#define POWER S(LCTL(KC_POWER))

#define GRIN  0x1F600
#define COOL  0x1F60E
#define SKULL 0x1F480


enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  WORKMAN,
  GAM3R,
  GAMEUP,
  LOWER,
  RAISE,
  BACKLIT,
  EXT_PLV,
  TOGRED,
  FUNC,
  TOGGRN,
  BELOW,
  ABOVE,
  RGBLED_TOGGLE,
  RGBLED_STEP_MODE,
  RGBLED_INCREASE_HUE,
  RGBLED_DECREASE_HUE,
  RGBLED_INCREASE_SAT,
  RGBLED_DECREASE_SAT,
  RGBLED_INCREASE_VAL,
  RGBLED_DECREASE_VAL,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO


/*qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS)
  };*/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_QWERTY] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {CTLESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_T(KC_ENT) },
  {FUNC, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPFN,  KC_SPFN,  RAISE,   KC_RGUI, KC_RALT, KC_RCTL,  FUNC}
},


[_WORKMAN] = {
  {KC_TAB,  KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,    KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, KC_BSPC},
  {CTLESC,  KC_A,    KC_S,    KC_H,    KC_T,    KC_G,    KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH, SFT_T(KC_ENT) },
  {FUNC , KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPFN,  KC_SPFN,  RAISE,   KC_RGUI, KC_RALT,   KC_RCTL, FUNC   }
},


[_GAM3R] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {CTLESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_T(KC_ENT) },
  {GAMEUP, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_RGUI, KC_RALT, KC_RCTL,  FUNC}
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
  
  {KC_ESC, KC_PGUP,  LGUI(KC_LEFT), KC_UP, LGUI(KC_RGHT), LCTL(KC_LEFT), LCTL(KC_RGHT), LGUI(KC_LEFT), KC_UP, LGUI(KC_RGHT), KC_PGUP, _______ },
  {KC_DEL, KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, X(COOL), X(SKULL), X(GRIN), _______, _______ },
  {_______, _______, _______, _______, _______, ABOVE  , BELOW  , KC_RPRN, KC_RBRC, KC_RCBR, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

[_ADJUST] = {
  {RESET  , _______, _______, _______, RGBLED_TOGGLE, RGBLED_STEP_MODE, RGBLED_INCREASE_HUE, RGBLED_DECREASE_HUE, RGBLED_INCREASE_SAT, RGBLED_DECREASE_SAT, RGBLED_INCREASE_VAL, RGBLED_DECREASE_VAL},
  {_______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  WORKMAN, GAM3R, _______,  _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {TOGRED , TOGGRN , _______, _______, _______, _______, _______, _______, _______, BL_TOGG, BL_DEC , BL_INC}
},

[_FUNC] = {
  {RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX, KC_7,  KC_8,  KC_9, KC_PLUS,  S(LALT(KC_VOLU))},
  {XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX, KC_4,  KC_5,  KC_6, KC_MINS,  S(LALT(KC_VOLD))},
  {KC_CAPS, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_0,    KC_1,  KC_2,  KC_3, KC_ASTR,  KC_MUTE},
  {_______, _______, _______, S(LCTL(KC_POWER)), KC_MPRV, KC_MPLY, KC_MPLY, KC_MNXT, HYPER , _______, _______, _______}
},


[_SPCFN] = {
  {KC_TILD , KC_EXLM, KC_AT  , KC_PGUP,  _______, KC_LBRC, KC_RBRC, SRTLIN, KC_UP,  ENDLIN, KC_PGUP, KC_DEL  },
  {KC_GRV, KC_DLR , SPCLFT, KC_PGDN, SPCRGT,  KC_LCBR, KC_RCBR, KC_LEFT,   KC_DOWN, KC_RGHT, KC_PGDN,  _______ },
  {_______, KC_AMPR, KC_ASTR, _______, KC_PGDN,  KC_LPRN, KC_RPRN, _______, _______, _______, _______, _______ },
  {_______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______ }
}

};

#ifdef AUDIO_ENABLE
#define COIN \
E__NOTE(_A5  ),      \
HD_NOTE(_E6  ),

float tone_startup[][2]    = SONG(COIN);
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(WORKMAN_SOUND);
float tone_plover[][2]     = SONG(PLOVER_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif


void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_QWERTY);
        rgblight_mode(12);
      }
      return false;
      break;
    case WORKMAN:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_colemak, false, 0);
        #endif
          rgblight_mode(3);
        persistant_default_layer_set(1UL<<_WORKMAN);
      }
      return false;
      break;
    case GAM3R:
      if(record->event.pressed) {
        #ifdef AUDIO_ENABLE
        PLAY_NOTE_ARRAY(music_scale, false, 0);
        #endif
        rgblight_mode(15);
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
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
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
   case RGBLED_TOGGLE:
    //led operations
    if (record->event.pressed) {
      rgblight_toggle();
    }
    return false;
    break;
  case RGBLED_INCREASE_HUE:
    if (record->event.pressed) {
      rgblight_increase_hue();
    }
    return false;
    break;
  case RGBLED_DECREASE_HUE:
    if (record->event.pressed) {
      rgblight_decrease_hue();
    }
    return false;
    break;
  case RGBLED_INCREASE_SAT:
    if (record->event.pressed) {
      rgblight_increase_sat();
    }
    return false;
    break;
  case RGBLED_DECREASE_SAT:
    if (record->event.pressed) {
      rgblight_decrease_sat();
    }
    return false;
    break;
  case RGBLED_INCREASE_VAL:
    if (record->event.pressed) {
      rgblight_increase_val();
    }
    return false;
    break;
  case RGBLED_DECREASE_VAL:
    if (record->event.pressed) {
      rgblight_decrease_val();
    }
    return false;
    break;
  case RGBLED_STEP_MODE:
    if (record->event.pressed) {
      rgblight_step();
    }
    return false;
    break;


    }
  return true;
}

void matrix_init_user(void) {
    set_unicode_input_mode(UC_OSX);
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
    #ifdef BACKLIGHT_ENABLE
        backlight_init_ports();

    /* #define PULSE_WIDTH 0x40 */
    /*     /\* DDRB |= (1<<7); // Blue *\/ */
    /*     /\* PORTB &= ~(1<<7); *\/ */
    /*     DDRB |= (1<<6); // Red */
    /*     PORTB &= ~(1<<6); */

    /*     /\* DDRB |= (1<<5); // Green *\/ */
    /*     /\* PORTB &= ~(1<<5);  *\/ */
    /*     OCR1B = PULSE_WIDTH;	/\* Load Pulse width *\/ */
    /*     //        OCR1AH = 0; */
    /*     TCCR1A = 0x81;		/\* 8-bit, Non-Inverted PWM *\/ */
    /*     TCCR1B = 1;		/\* Start PWM *\/  */
    #endif
}


#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user()
{
    PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_NOTE_ARRAY(music_scale, false, 0);
}

#endif
