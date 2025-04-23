#include QMK_KEYBOARD_H
#include "keymap_german.h"

enum layer_number {
  _QWERTZ = 0,
  _SPECIALS,
  _KEYPAD,
  _MISC,
  _ADJUST
};

enum unicode_names {
    IRONY,
    lowerZ,
    upperZ,
    lowerY,
    upperY,
    EKA,
    EKZ,
    PRGRPH,
    GRVLFT,
    ZRKMFLX,
    FRGZCHN,
    KLNR,
    GRSR,
    ET,
    SLSH,
    KA,
    KZ,
    GRV,
    HASH,
    TLD,
    MAL,
    PLUS,
    UNDERLINE,
    GKA,
    GKZ,
    SENKRECHTELINE,
    APOSTROPH,
    AT,
    EQ,
    BS

};

const uint32_t PROGMEM unicode_map[] = {
    [IRONY]  = 0x2E2E,  // ⸮
    [EKA] = 0x005B, //[
    [EKZ] = 0x005D, //]
    [PRGRPH] = 0x00A7, //§
    [GRVLFT] = 0x00B4, //´
    [ZRKMFLX] = 0x005E, //^
    [FRGZCHN] = 0x003F, //?
    [KLNR] = 0x003C, //<
    [GRSR] = 0x003E, //>
    [ET] = 0x0026, //&
    [SLSH] = 0x002F, ///
    [KA] = 0x0028, //(
    [KZ] = 0x0029, //)
    [GRV] = 0x0060, //`
    [HASH] = 0x0023, //#
    [TLD] = 0x007E, //~
    [MAL] = 0x002A, //*
    [PLUS] = 0x002B, //+
    [UNDERLINE] = 0x005F, //_
    [GKA] = 0x007B, //{
    [GKZ] = 0x007D, //}
    [SENKRECHTELINE] = 0x007C, //|
    [APOSTROPH] = 0x0027, //'
    [AT] = 0x0040, //@
    [EQ] = 0x003D, //=
    [BS] = 0x005C, //HIER KÖNNTE EIN BACKSLASH STEHEN 
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Z  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LCTRL |   Y  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | 3    |BackSP| /Space  /       \Enter \   | 1    |2     | GUI  |
 *                   |      |      |      |/       /         \      \  |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_QWERTZ] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     DE_Z,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LCTRL, DE_Y,   KC_X,    KC_C,    KC_V,    KC_B, TG(4),  XXXXXXX,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                        KC_LALT, MO(2), KC_BSPC, KC_SPC, KC_ENT, MO(1), MO(2), KC_LGUI
),

/* Specials
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  ^   |  ?   |  '   |  <   |  >   |  @   |                    |   =  |  +   |   [  |   ]  |  *   |   ~  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  !   |  "   |  §   |  $   |  %   |-------.    ,-------|  &   |  /   |   (  |   )  |  `   |   #  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |  ²   |  ³   |      |  €   |-------|    |-------|  BS  |   _  |   {  |   }  |  ´   |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | 3    | DEL  | /Space  /       \Enter \   | 1    |2     | GUI  |
 *                   |      |      |      |/       /         \      \  |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_SPECIALS] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,            KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11, KC_F12,
  DE_CIRC, S(DE_SS), S(DE_HASH),  DE_LABK,  S(DE_LABK),  DE_AT,          DE_EQL, DE_PLUS, ALGR(DE_8), ALGR(DE_9), S(DE_PLUS), ALGR(DE_PLUS),
  _______, DE_EXLM  , S(DE_2), S(DE_3), KC_DLR, KC_PERC,        S(DE_6), S(DE_7), S(DE_8), S(DE_9), S(DE_ACUT), DE_HASH,
  _______, X(IRONY), DE_SUP2, DE_SUP3, XXXXXXX, DE_EURO, XXXXXXX, XXXXXXX, DE_BSLS, S(DE_MINS), ALGR(DE_7), ALGR(DE_0), DE_ACUT, ALGR(DE_LABK),
                             _______, _______, KC_DEL, _______, _______, _______, _______, _______
),

/* Key Pad
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |  Num |  /   |  *   |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  up  |      |      |      |                    |   0  |  7   |  8   |  9   |  -   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | left | down | right|      |      |-------.    ,-------|   ,  |  4   |  5   |  6   |  +   |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |  1   |  2   |  3   | Enter|      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | 3    |BackSP| /Space  /       \Enter \   | 1    |2     | GUI  |
 *                   |      |      |      |/       /         \      \  |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_KEYPAD] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, KC_NUM,  KC_PSLS, KC_PAST, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX,                    KC_KP_0, KC_KP_7, KC_KP_8, KC_KP_9, KC_PMNS, XXXXXXX,
  _______, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX,                    KC_PDOT, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, KC_KP_1, KC_KP_2, KC_KP_3, KC_PENT, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, KC_KP_0, KC_PDOT
),

/* Misc&Mouse
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  up  |      |      |      |                    |      | WHLe | WHUp | WHRi |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | left | down | right|      |      |-------.    ,-------|      | Click| WHCl |LClick| M4   | M5   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      | DEL  |-------|    |-------|      |      | WHDo |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | 3    |BackSP| /Space  /       \Enter \   | 1    |2     | GUI  |
 *                   |      |      |      |/       /         \      \  |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

  [_MISC] = LAYOUT(
 KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_WH_L, KC_WH_U, KC_WH_R, XXXXXXX, XXXXXXX,
  _______, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX,                  XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_D, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  ),

  [_ADJUST] = LAYOUT(
    RGB_TOG,    RGB_MOD,    RGB_HUI,    RGB_SAI,    RGB_VAI,    RGB_SPI,                          RGB_VAD,    RGB_VAI,    RGB_SPD,    RGB_SPI,    _______,    _______,
    _______,    RGB_RMOD,    RGB_HUD,    RGB_SAD,    RGB_VAD,    RGB_SPD,                         RGB_M_P,    RGB_M_B,    RGB_M_R,    RGB_M_SW,    RGB_M_SN,    RGB_M_K,
    _______,    _______,    _______,    _______,    _______,    _______,                          RGB_M_X,    RGB_M_G,    RGB_M_T,    _______,    _______,    _______,
    _______,    _______,   _______,    _______,    _______,    _______,   _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
                          _______,    _______,    _______,    _______,                    _______,    _______,    _______,    _______
  )
};