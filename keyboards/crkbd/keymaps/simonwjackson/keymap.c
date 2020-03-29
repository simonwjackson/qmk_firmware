#include QMK_KEYBOARD_H

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY     0
#define _NUMBER     1
#define _MOUSE      2
#define _DIRECTION  3
#define _PAGING     4
#define _TABBING    5
#define _FUNCTION   6
#define _SYMBOLS    7
#define _WORDS      8
#define _WRAPS      9
#define _MEDIA      10 

#define _ KC_NO
#define STAB LSFT(KC_TAB)
#define EOW LALT(KC_RIGHT)
#define SOW LALT(KC_LEFT)

#define SFT_SPC LSFT_T(KC_SPC)
#define ALT_SPC LALT_T(KC_SPC)
#define GUI_CTL MT(MOD_LGUI | MOD_LCTL, KC_ESC)
#define CTL_ESC LCTL_T(KC_ESC)
#define FNS_R   LT(_FUNCTION, KC_R)
#define DIR_A   LT(_DIRECTION, KC_A)
#define NUM_S   LT(_NUMBER, KC_S)
#define WRP_D   LT(_WRAPS, KC_D)
#define TAB_F   LT(_TABBING, KC_F)
#define MEDA_E  LT(_MEDIA, KC_E)

#define MO_PAGE MO(_PAGING)
#define MO_NUM  MO(_NUMBER)
#define MO_MOU  SIM_MOUSE
#define MO_TAB  MO(_TABBING) 
#define MO_WORD MO(_WORDS) 
#define S_FFA   SIM_PIPE
#define S_BFA   SIM_COMPOSE
#define S_SKNAR SIM_SKINNY_ARROW
#define S_FATAR SIM_FAT_ARROW
#define S_ARRFN SIM_ARROW_FN
#define S_BWAF  SIM_BW_AUTO_FILL

#define EZM_ge  LALT(KC_LEFT)
#define EZM_b   LCTL(KC_LEFT)
#define EZM_w   LCTL(KC_RIGHT)
#define EZM_e   LALT(KC_RIGHT)

#define EZM_gE  LCTL(LALT(LSFT(KC_LEFT)))
#define EZM_B   LCTL(LALT(KC_LEFT))
#define EZM_W   LCTL(LALT(KC_RIGHT))
#define EZM_E   LCTL(LALT(LSFT(KC_RIGHT)))

// Combos
enum combos { 
  LK_ESC,
  KJ_ENT,
  LH_SAV,
  DF_CTL
};

const uint16_t PROGMEM esc_combo[] =    {KC_L, KC_K, COMBO_END};
const uint16_t PROGMEM enter_combo[] =  {KC_K, KC_J, COMBO_END};
const uint16_t PROGMEM save_combo[] =   {KC_L, KC_H, COMBO_END};
const uint16_t PROGMEM os_ctrl_combo[] =   {KC_K, KC_M, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [LK_ESC] = COMBO(esc_combo, KC_ESC),
	[KJ_ENT] = COMBO(enter_combo, KC_ENT),
	[LH_SAV] = COMBO_ACTION(save_combo),
	[DF_CTL] = COMBO_ACTION(os_ctrl_combo),
};

void process_combo_event(uint8_t combo_index, bool pressed) {
	switch(combo_index) {
		case LH_SAV:
			if (pressed) {
				tap_code16(LCTL(KC_S));
			}
			break;
		case DF_CTL:
			if (pressed) {
				/* register_code16(OSM(MOD_LCTL)); */
				set_oneshot_mods(MOD_LCTL);

				/* tap_code16(KC_S); */
			}
			break;
  }
}

uint16_t get_tapping_term(uint16_t keycode) {
  switch (keycode) {
    case SFT_T(KC_SPC):
      return 900;
    /* case LT(1, KC_GRV): */
    /*   return 130; */
    default:
      return TAPPING_TERM;
  }
}

enum custom_keycodes {
  /* wrapper */ 
  SIM_HTML_CLOSE = SAFE_RANGE,
  /* programming */
  SIM_PIPE,
  SIM_COMPOSE,
  SIM_FAT_ARROW,
  SIM_SKINNY_ARROW,
  SIM_ARROW_FN,
  SIM_CONST,
  SIM_GIT_PUSH,
	SIM_GIT_REBASE,
	SIM_BW_AUTO_FILL, 
	SIM_MOUSE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // send_unicode_hex_string("0028 3063 25D5 203F 25D5 0029 3063"); 
    case SIM_MOUSE:
      if (record->event.pressed) {
				layer_on(_MOUSE);
				register_code(KC_ACL2);
      } else {
				unregister_code(KC_ACL2);
				layer_off(_MOUSE);
      }
      break; 
		
    case SIM_BW_AUTO_FILL:
      if (record->event.pressed) {
				tap_code16(LCTL(LSFT(KC_L)));
				wait_ms(200);
				tap_code16(KC_ENT);
      } else {
        // when keycode SIM_PARENS is released
      }
      break; 
  
    // Wrappers
    case SIM_HTML_CLOSE:
      if (record->event.pressed) {
        // when keycode SIM_PARENS is pressed
        SEND_STRING("</>" SS_TAP(X_LEFT));
      } else {
        // when keycode SIM_PARENS is released
      }
      break; 

    /* Programming */
    case SIM_COMPOSE:
        
			if(record->event.pressed){
          SEND_STRING("<| ");
        }
        return false;
        break;

    case SIM_PIPE:
        if(record->event.pressed){
          SEND_STRING("|> ");
        }
        return false;
        break;

    case SIM_ARROW_FN: if(record->event.pressed){
          SEND_STRING("() => {  }" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
        }
        return false;
        break;

		case SIM_SKINNY_ARROW:
        
				if(record->event.pressed){
          SEND_STRING("->");
        }
        return false;
        break; 

		case SIM_FAT_ARROW:
        if(record->event.pressed){
          SEND_STRING("=>");
        }
        return false;
        break; 

    case SIM_GIT_PUSH:
        if(record->event.pressed){ 
          SEND_STRING("git push --no-verify --set-upstream origin ");
        }
        return false;
        break; 

    case SIM_GIT_REBASE:
        
				if(record->event.pressed){ 
          SEND_STRING("git rebase --interactive upstream/develop ");
        }
        return false;
        break; 
  }

  
	return true;
};

//Tap Dance Declarations
enum {
  CT_PUNC = 0,
  CT_SLSH = 1,
  TCK = 2,
  CLN = 4,
  CT_MARK = 4,
  CT_DASH = 5,
  BR = 6,
  SBR = 7,
  SPA = 8,
  PAR = 9,
  BA = 10,
  SBA = 11,
  ANG = 12,
  SAN = 13,
};



void dance_dash_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_MINS); 
	}
	else {
    register_code (KC_RSFT);
    register_code (KC_MINS); 
  }
}

void dance_dash_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_MINS); 
	}
	else {
    unregister_code (KC_RSFT);
    unregister_code (KC_MINS); 
  }
}


void dance_punctuation_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_DOT); 
	}
  else if (state->count == 2) {
    register_code (KC_COMMA); 
  }
  else if (state->count == 3) {
    register_code (KC_RSFT);
    register_code (KC_SLASH); 
  } 
	else {
    register_code (KC_RSFT);
    register_code (KC_1);
  }
}

void dance_punctuation_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_DOT); 
	}
  else if (state->count == 2) {
    unregister_code (KC_COMMA); 
  }
  else if (state->count == 3) {
    unregister_code (KC_RSFT);
    unregister_code (KC_SLASH); 
  } 
	else {
    unregister_code (KC_RSFT);
    unregister_code (KC_1);
  }
}

void dance_marks_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_RSFT);
    register_code (KC_SLASH); 
  } 
	else {
    register_code (KC_RSFT);
    register_code (KC_1);
  }
}
void dance_marks_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_RSFT);
    unregister_code (KC_SLASH); 
  } 
	else {
    unregister_code (KC_RSFT);
    unregister_code (KC_1);
  }
}

void dance_slash_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_SLASH); 
	}
  else if (state->count == 2) {
    register_code (KC_RSFT);
    register_code (KC_BSLASH); 
  }
	else {
    register_code (KC_BSLASH); 
  }
} 

void dance_slash_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_SLASH); 
	}
  else if (state->count == 2) {
    unregister_code (KC_RSFT);
    unregister_code (KC_BSLASH); 
  }
	else {
    unregister_code (KC_BSLASH); 
  }
}

void dance_ticks_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_QUOTE); 
	}
  else if (state->count == 2) {
    register_code (KC_RSFT);
    register_code (KC_QUOTE); 
  }
  else if (state->count == 3) {
    register_code (KC_GRAVE); 
  } 
	else {
    register_code (KC_RSFT);
    register_code (KC_GRAVE); 
  }
}

void dance_ticks_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_QUOTE); 
	}
  else if (state->count == 2) {
    unregister_code (KC_RSFT);
    unregister_code (KC_QUOTE); 
  }
  else if (state->count == 3) {
    unregister_code (KC_GRAVE); 
  } 
	else {
    unregister_code (KC_RSFT);
    unregister_code (KC_GRAVE); 
  }
}

void dance_colon_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_RSFT);
    register_code (KC_SCLN);
  } else {
    register_code (KC_SCLN);
  }
}

void dance_colon_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_RSFT);
    unregister_code (KC_SCLN);
  } else {
    unregister_code (KC_SCLN);
  }
}

void dance_bracket (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    SEND_STRING("[");
  } else {
    SEND_STRING("]");
  }
	  
	reset_tap_dance(state);
}

void dance_brackets (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    SEND_STRING("[]" SS_TAP(X_LEFT));
  } else {
    SEND_STRING("[  ]" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
  }
	reset_tap_dance(state);
}

void dance_parens (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    SEND_STRING("()" SS_TAP(X_LEFT));
  } else {
    SEND_STRING("(  )" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
  }
	reset_tap_dance(state);
}

void dance_paren (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    SEND_STRING("(");
  } else {
    SEND_STRING(")");
  }
	reset_tap_dance(state);
}

void dance_braces (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    SEND_STRING("{}" SS_TAP(X_LEFT));
  } else {
    SEND_STRING("{  }" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
  }
	reset_tap_dance(state);
}

void dance_brace (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    SEND_STRING("{");
  } else {
    SEND_STRING("}");
  }
	reset_tap_dance(state);
}

void dance_angles (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    SEND_STRING("<>" SS_TAP(X_LEFT));
  } else if (state->count == 2) {
    SEND_STRING("<  >" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
  } else {
    SEND_STRING("</>" SS_TAP(X_LEFT));
  }
	reset_tap_dance(state);
}

void dance_angle (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    SEND_STRING("<");
  } else {
    SEND_STRING(">");
  }

	reset_tap_dance(state);
}

qk_tap_dance_action_t tap_dance_actions[] = {
 [CT_PUNC] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_punctuation_finished, dance_punctuation_reset),
 [CT_MARK] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_marks_finished, dance_marks_reset),
 [CT_DASH] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_dash_finished, dance_dash_reset),
 [CT_SLSH] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_slash_finished, dance_slash_reset),
 [TCK] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_ticks_finished, dance_ticks_reset),
 [CLN] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_colon_finished, dance_colon_reset),
 [BR] = ACTION_TAP_DANCE_FN (dance_bracket),
 [SBR] = ACTION_TAP_DANCE_FN (dance_brackets),
 [PAR] = ACTION_TAP_DANCE_FN (dance_paren),
 [SPA] = ACTION_TAP_DANCE_FN (dance_parens),
 [BA] = ACTION_TAP_DANCE_FN (dance_brace),
 [SBA] = ACTION_TAP_DANCE_FN (dance_braces),
 [ANG] = ACTION_TAP_DANCE_FN (dance_angle),
 [SAN] = ACTION_TAP_DANCE_FN (dance_angles),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
    /*----------------------------------------------------.                    ,----------------------------------------------------*/\
      KC_CAPS,  KC_Q  ,  KC_W  , MEDA_E ,  FNS_R ,  KC_T  ,                       KC_Y  ,  KC_U  ,  KC_I  ,  KC_O  ,  KC_P  , _______,\
    /*-------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+-------*/\
      MO_MOU ,  DIR_A ,  NUM_S ,  WRP_D ,  TAB_F ,  KC_G  ,                       KC_H  ,  KC_J  ,  KC_K  ,  KC_L  , TD(CLN), TD(TCK),\
    /*-------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+-------*/\
OSM(MOD_LCTL),  KC_Z  ,  KC_X  ,  KC_C  ,  KC_V  ,  KC_B  ,                       KC_N  ,  KC_M  , KC_COMM, KC_DOT , KC_SLSH, S_BWAF,\
    /*-------+--------+--------+--------+--------+--------|--------|  |--------+--------+--------+--------+--------+----------------*/\
                                          _______, GUI_CTL, ALT_SPC,    SFT_SPC, KC_RCTL, KC_RALT \
                                        /*`------------------------'  `-------------------------'*/

  ),

  [_NUMBER] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      KC_HASH,  KC_7  ,  KC_8  ,  KC_9  , KC_PERC, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, MO(_SYMBOLS), _______, _______,                      KC_PPLS,  KC_4  ,  KC_5  ,  KC_6  , KC_PMNS, KC_EQL ,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      KC_ASTR,  KC_1  ,  KC_2  ,  KC_3  , KC_SLSH, KC_COMM,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,     KC_SPC, KC_DOT ,  KC_0  \
                                      //`--------------------------'  `--------------------------'
    ),

  [_MOUSE] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      KC_DLR , KC_WH_D, KC_WH_U, KC_WH_R, _______, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_ACL1, KC_ACL0, _______, _______, _______,                      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    KC_BTN1, KC_BTN2, KC_BTN3 \
                                      //`--------------------------'  `--------------------------'
  ),

 [_DIRECTION] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
			_______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, MO_PAGE, MO_WORD, _______, _______,                      KC_LEFT, KC_DOWN,  KC_UP ,KC_RIGHT, _______, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ), 
  
 [_WORDS] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      EZM_gE ,  EZM_B ,  EZM_W ,  EZM_E , _______, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      EZM_ge ,  EZM_b  ,  EZM_w , EZM_e , _______, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ), 

  [_PAGING] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

  [_TABBING] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			_______, _______, _______, _______, _______, _______,                      KC_BSPC, KC_TAB ,  STAB  , KC_DEL , _______, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______\
                                      //`--------------------------'  `--------------------------'
  ),
	 
  [_SYMBOLS] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      KC_TILD, KC_SLSH, KC_PIPE, KC_BSLS, _______, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      KC_CIRC,  KC_AT , KC_AMPR, KC_DLR , KC_UNDS, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, KC_QUES, KC_EXLM, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

  [_FUNCTION] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                       KC_F1 ,  KC_F5 ,  KC_F9 , KC_F12 , KC_F16 , KC_F19,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, KC_F22 , KC_F23 , KC_F24 , _______,                       KC_F2 ,  KC_F6 ,  KC_F10, KC_F13 , KC_F17 , KC_F20,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                       KC_F3 ,  KC_F7 ,  KC_F11, KC_F15 , KC_F18 , KC_F21,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______,  KC_F4 ,  KC_F8 \
                                      //`--------------------------'  `--------------------------'
  ), 

  [_WRAPS] = LAYOUT( \
    /*----------------------------------------------------.                    ,----------------------------------------------------*/\
      _______, _______, _______, _______, _______, _______,                      _______, KC_LBRC, TD(SBR), KC_RBRC, _______, _______,\
    /*-------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+-------*/\
      _______, _______, _______, _______, _______, _______,                      S_SKNAR, KC_LPRN, TD(SPA), KC_RPRN, S_FATAR, _______,\
    /*-------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+-------*/\
      _______, _______, _______, _______, _______, _______,                      S_BFA  , KC_LCBR, TD(SBA), KC_RCBR, S_FFA  , _______,\
    /*-------+--------+--------+--------+--------+--------|--------|  |--------+--------+--------+--------+--------+----------------*/\
                                          _______, _______, _______,    TD(SAN), KC_LABK, KC_RABK\
                                        /*`------------------------'  `-------------------------'*/
			),  

  [_MEDIA] = LAYOUT( \
    /*----------------------------------------------------.                    ,----------------------------------------------------*/\
      _______, _______, _______, _______, _______, _______,                      KC_MNXT, KC_VOLD, KC_VOLU, KC_MPRV, _______, _______,\
    /*-------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+-------*/\
      _______, _______, _______, _______, _______, _______,                      KC_MRWD, KC_MPLY, KC_MUTE, KC_MFFD, _______, _______,\
    /*-------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+-------*/\
      _______, _______, _______, _______, _______, _______,                      KC_WAKE, KC_BRID, KC_BRIU, _______, _______, _______,\
    /*-------+--------+--------+--------+--------+--------|--------|  |--------+--------+--------+--------+--------+----------------*/\
                                          _______, _______, _______,    _______, _______, _______\
                                        /*`------------------------'  `-------------------------'*/
			)
};
