// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

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
#define _FUNC 6
#define _ADJUST 16

#define KC_SPFN LT(_SPCFN, KC_SPC) // press for space, hold for function layer (aka spacefn)
// use tap dancing to set caps lock
#define TD_ESC 0
#define HYPER MT(MOD_HYPR, KC_ENT)


enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  GAM3R,
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

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_T(KC_ENT) },
  {FUNC, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPFN,  KC_SPFN,  RAISE,   KC_RGUI, KC_RALT, KC_RCTL,  FUNC}
},

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC},
  {KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {FUNC , KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPFN,  KC_SPFN,  RAISE,   KC_RGUI, KC_RALT,   KC_RCTL, FUNC   }
},

/* GAM3R
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_GAM3R] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_T(KC_ENT) },
  {FUNC, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_RGUI, KC_RALT, KC_RCTL,  FUNC}
},


/* Lower - Sybmols
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,  KC_BSPC},
  {KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______},
  {_______, _______, KC_LCBR, KC_LBRC, KC_LPRN, KC_PIPE, KC_BSLS, KC_LPRN, KC_LBRC, KC_LCBR, _______, _______}, 
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},

/* Raise - Move
 * ,-----------------------------------------------------------------------------------.
 * | Esc  | PgUp | Cmd-L|  UP  | Cmd-R| Ctl-L| Ctl-R| Cmd-L|  UP  | Cmd-R| PgUp | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  | PgDn | Left |Down  | Right|      |      | Left |Down  | Right| PgDn | Del  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Caps |      |      |      |      | Above|Below |      |      |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  
  {KC_ESC, KC_PGUP,  LGUI(KC_LEFT), KC_UP, LGUI(KC_RGHT), LCTL(KC_LEFT), LCTL(KC_RGHT), LGUI(KC_LEFT), KC_UP, LGUI(KC_RGHT), KC_PGUP, _______ },
  {KC_DEL, KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_DEL },
  {_______, _______, _______, _______, _______, ABOVE  , BELOW  , KC_RPRN, KC_RBRC, KC_RCBR, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {RESET  , _______, _______, _______, RGBLED_TOGGLE, RGBLED_STEP_MODE, RGBLED_INCREASE_HUE, RGBLED_DECREASE_HUE, RGBLED_INCREASE_SAT, RGBLED_DECREASE_SAT, RGBLED_INCREASE_VAL, RGBLED_DECREASE_VAL},
  {_______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, GAM3R, _______,  _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {TOGRED , TOGGRN , _______, _______, _______, _______, _______, _______, _______, BL_TOGG, BL_DEC , BL_INC}
},

/* FUNC
 * ,-----------------------------------------------------------------------------------.
 * | Reset|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | Vol+ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F11 |  F12 |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |  F19 |  F20 | Vol- |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F21 |  F22 |  F23 |  F24 |      |      | Lock |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | Prev | Mute | Play | Next |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNC] = {
  {RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX, KC_7,  KC_8,  KC_9, KC_PLUS,  S(LALT(KC_VOLU))},
  {XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX, KC_4,  KC_5,  KC_6, KC_MINS,  S(LALT(KC_VOLD))},
  {KC_CAPS, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_0,    KC_1,  KC_2,  KC_3, KC_ASTR,  KC_MUTE},
  {_______, _______, _______, S(LCTL(KC_POWER)), KC_MPRV, KC_MPLY, KC_MPLY, KC_MNXT, HYPER , _______, _______, _______}
},


/* Space + FN layer
 * .-----------------------------------------------------------------------------------.
 * | `    | !    | @    | #    |     |   [   |   ]  |   {  |  }  |  (  |  )    | DEL   |
 * |------+------+------+------+-----+-------+------+------+-----+-----+-------+-------|
 * |      | $    | %    | ^    |PgUp |       | Left | Up   | Dn  | Rght|       |  '    |
 * |------+------+------+------+-----+-------+------+------+-----+-----+-------+-------|
 * |      | &    | *    |      |PgDn |       |      |      |     |     |       |       |
 * |------+------+------+------+-----+-------+------+------+-----+-----+-------+-------|
 * |      |      |      |      |     |       |      |      |     |     |       |       |
 * `-----------------------------------------------------------------------------------'
 * PS = Print Screen
 * PP = Play/Pause
 */

[_SPCFN] = {
  {KC_GRV , KC_EXLM, KC_AT  , KC_HASH,  _______, KC_LBRC, KC_RBRC, _______, KC_UP,   _______, _______, KC_DEL  },
  {_______, KC_DLR , KC_PERC, KC_CIRC, KC_PGUP,  KC_LCBR, KC_RCBR, KC_LEFT,   KC_DOWN, KC_RGHT, _______,  _______ },
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
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
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
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_colemak, false, 0);
        #endif
          rgblight_mode(3);
        persistant_default_layer_set(1UL<<_COLEMAK);
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
