#include "jj40.h"
#include "action_layer.h"

#define _QWE 0
#define _SFT 1
#define _ARR 2

#ifdef KEYMAP
#undef KEYMAP
#endif
#define KEYMAP KEYMAP_MIT

#define ______ KC_TRNS

enum jj40_keycodes
{
	CC_ARR = SAFE_RANGE,
	CC_NOHL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWE] = KEYMAP( \
	KC_LBRC	,	KC_Q	,	KC_W	,	KC_E	,	KC_R	,	KC_T	,	KC_Y	,	KC_U	,	KC_I	,	KC_O	,	KC_P	,	KC_RBRC	,\
	KC_LCTL	,	KC_A	,	KC_S	,	KC_D	,	KC_F	,	KC_G	,	KC_H	,	KC_J	,	KC_K	,	KC_L	,	KC_SCLN	,	KC_QUOT	,\
	KC_LSFT	,	KC_NO	,	KC_Z	,	KC_X	,	KC_C	,	KC_V	,	KC_B	,	KC_N	,	KC_M	,	KC_COMM	,	KC_DOT	,	KC_SLSH	,\
	KC_LCTL	,	KC_LALT	,	KC_TAB	,	KC_ESC	,	TT(_SFT),	KC_SPC	,	TT(_ARR),	KC_BSPC	,	KC_ENT	,	KC_NO	,	KC_LGUI	),

[_SFT] = KEYMAP( \
	KC_UNDS	,	KC_EXLM	,	KC_AT	,	KC_HASH	,	KC_DLR	,	KC_PERC	,	KC_CIRC	,	KC_AMPR	,	KC_ASTR	,	KC_LPRN	,	KC_RPRN	,	KC_PLUS	,\
	KC_MINS	,	KC_1	,	KC_2	,	KC_3	,	KC_4	,	KC_5	,	KC_6	,	KC_7	,	KC_8	,	KC_9	,	KC_0	,	KC_EQL	,\
	_______	,	KC_GRV	,	KC_LBRC	,	KC_RBRC	,	KC_SLSH	,	KC_BSLS	,	KC_QUES	,	KC_PIPE	,	KC_LCBR	,	KC_RCBR	,	KC_TILD	,	KC_NO	,\
	_______	,	_______	,	_______	,	_______	,	_______	,	_______	,	CC_ARR	,	_______	,	_______	,	TG(_SFT),	_______	),

[_ARR] = KEYMAP( \
	KC_F1	,	KC_F2	,	KC_F3	,	KC_F4	,	KC_F5	,	KC_F6	,	KC_F7	,	KC_F8	,	KC_F9	,	KC_F10	,	KC_F11	,	KC_F12	,\
	KC_PSCR	,	KC_NO	,	KC_HOME	,	KC_PGDN	,	KC_PGUP	,	KC_END	,	KC_LEFT	,	KC_DOWN	,	KC_UP	,	KC_RGHT	,	KC_NO	,	KC_PAUS	,\
	_______	,	KC_WBAK	,	KC_WFWD	,	KC_MPRV	,	RGB_VAD	,	KC_VOLD	,	KC_VOLU	,	RGB_VAI	,	KC_MNXT	,	KC_MUTE	,	RGB_TOG	,	KC_INS	,\
	_______	,	_______	,	_______	,	_______	,	CC_NOHL	,	_______	,	_______	,	KC_DEL	,	_______	,	TG(_ARR),	_______	)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
	if (record->event.pressed)
	{
		switch(keycode)
		{
		case CC_ARR:
			SEND_STRING("->");
			return false;
		case CC_NOHL:
			SEND_STRING(":nohl");
			return false;
		}
	}

	return true;
}

uint32_t layer_state_set_user(uint32_t state)
{
	switch(biton32(state))
	{
	default:
	case _QWE:
		rgblight_sethsv_white();
		break;
	case _SFT:
		rgblight_sethsv_gold();
		break;
	case _ARR:
		rgblight_sethsv_azure();
		break;
	}
	return state;
}

void matrix_scan_user(void) { };	

