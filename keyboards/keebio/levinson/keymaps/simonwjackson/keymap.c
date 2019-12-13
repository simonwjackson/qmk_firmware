#include QMK_KEYBOARD_H

#define KC_TILDA LSFT(KC_GRAVE)
#define KC_CARRET LSFT(KC_6)
#define KC_AT LSFT(KC_2)
#define KC_AMP LSFT(KC_7)
#define KC_STAB LSFT(KC_TAB)
#define KC_HASH LSFT(KC_3)
#define KC_STAR LSFT(KC_8)
#define TD_DASH TD(CT_DASH)

// Combos
enum combos { 
  JK_TAB
};

const uint16_t PROGMEM jk_combo[] = {KC_K, KC_J, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [JK_TAB] = COMBO(jk_combo, KC_ESC)
};

// Init FN
void matrix_init_user(void) {
  if(get_unicode_input_mode() != UC_LNX) {
    set_unicode_input_mode(UC_LNX);
  }
  else if(get_unicode_input_mode() != UC_OSX) {
     set_unicode_input_mode(UC_OSX);
  }
}

enum custom_keycodes {
  /* wrapper */ 
  SIM_BRACKETS = SAFE_RANGE,
  SIM_PARENS,
  SIM_BRACES,
  SIM_ANGLES,
  SIM_BRACKETS_SPC,
  SIM_PARENS_SPC,
  SIM_BRACES_SPC,
  SIM_ANGLES_SPC,
  SIM_HTML_CLOSE,
  /* programming */
  SIM_FARR,
  SIM_SARR,
  SIM_ARR_FN,
  SIM_CONST,
  SIM_GIT_PUSH,
  SIM_GIT_REBASE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // send_unicode_hex_string("0028 3063 25D5 203F 25D5 0029 3063"); 
  
    // Wrappers
    case SIM_BRACKETS:
      if (record->event.pressed) {
        // when keycode SIM_PARENS is pressed
        SEND_STRING("[]" SS_TAP(X_LEFT));
      } else {
        // when keycode SIM_PARENS is released
      }
      break;

    case SIM_BRACKETS_SPC:
      if (record->event.pressed) {
        // when keycode SIM_PARENS is pressed
        SEND_STRING("[  ]" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
      } else {
        // when keycode SIM_PARENS is released
      }
      break;

    case SIM_PARENS:
      if (record->event.pressed) {
        // when keycode SIM_PARENS is pressed
        SEND_STRING("()" SS_TAP(X_LEFT));
      } else {
        // when keycode SIM_PARENS is released
      }
      break; 

    case SIM_PARENS_SPC:
      if (record->event.pressed) {
        // when keycode SIM_PARENS is pressed
        SEND_STRING("(  )" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
      } else {
        // when keycode SIM_PARENS is released
      }
      break; 

    case SIM_BRACES:
      if (record->event.pressed) {
        // when keycode SIM_PARENS is pressed
        SEND_STRING("{}" SS_TAP(X_LEFT));
      } else {
        // when keycode SIM_PARENS is released
      }
      break; 

    case SIM_BRACES_SPC:
      if (record->event.pressed) {
        // when keycode SIM_PARENS is pressed
        SEND_STRING("{  }" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
      } else {
        // when keycode SIM_PARENS is released
      }
      break; 

    case SIM_ANGLES:
      if (record->event.pressed) {
        // when keycode SIM_PARENS is pressed
        SEND_STRING("<>" SS_TAP(X_LEFT));
      } else {
        // when keycode SIM_PARENS is released
      }
      break; 

    case SIM_ANGLES_SPC:
      if (record->event.pressed) {
        // when keycode SIM_PARENS is pressed
        SEND_STRING("<  >" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
      } else {
        // when keycode SIM_PARENS is released
      }
      break; 

    case SIM_HTML_CLOSE:
      if (record->event.pressed) {
        // when keycode SIM_PARENS is pressed
        SEND_STRING("</>" SS_TAP(X_LEFT));
      } else {
        // when keycode SIM_PARENS is released
      }
      break; 

    /* Programming */

    case SIM_CONST:
        if(record->event.pressed){
          SEND_STRING("const ");
        }
        return false;
        break;

    case SIM_ARR_FN:
        if(record->event.pressed){
          SEND_STRING("() => {  }" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
        }
        return false;
        break;

    case SIM_SARR:
        if(record->event.pressed){
          SEND_STRING("->");
        }
        return false;
        break; 

    case SIM_FARR:
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
  CT_TICKS = 2,
  CT_COLN = 3,
  CT_MARK = 4,
  CT_DASH = 5
};

enum unicode_names {
    THUMBS_UP,
    POINT_UP,
    PARTY,
    SKULL,
    HUNDRED,
    SMILING,
    BEAMING,
    THINKING,
    GASPING,
    DOUBT,
    WINK,
    ZIPPED,
    ROLLING,
    PENSIVE,
    GLASSES,
    ASTONISHED,
    DISAPPOINTED
};

const uint32_t PROGMEM unicode_map[] = {
    [THUMBS_UP] = 0x1F44D, // 👍
    [POINT_UP]  = 0x261D,  // ☝
    [PARTY]     = 0x1F389, // 🎉
    [SKULL]     = 0x2620,  // ☠
    [HUNDRED]   = 0x1F4AF, // 💯

    // /* Faces */ 
    [SMILING]  = 0x1F642, // 🙂
    [BEAMING]   = 0x1F601, // 😁
    [THINKING]  = 0x1F914, // 🤔
    [GASPING]   = 0x1F92D, // 🤭
    [DOUBT]     = 0x1F928, // 🤨
    [WINK]      = 0x1F609, // 😉
    [ZIPPED]    = 0x1F910, // 🤐
    [ROLLING]   = 0x1F644, // 🙄
    [PENSIVE]   = 0x1F614, // 😔
    [GLASSES]   = 0x1F60E, // 😎
    [ASTONISHED] = 0x1F632, // 😲
    [DISAPPOINTED] = 0x1F61E //😞 
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

qk_tap_dance_action_t tap_dance_actions[] = {
 [CT_PUNC] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_punctuation_finished, dance_punctuation_reset),
 [CT_MARK] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_marks_finished, dance_marks_reset),
 [CT_DASH] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_dash_finished, dance_dash_reset),
 [CT_SLSH] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_slash_finished, dance_slash_reset),
 [CT_TICKS] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_ticks_finished, dance_ticks_reset),
 [CT_COLN] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_colon_finished, dance_colon_reset),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Main / QWERTY
 * ,-------------------------------------------------     ,--------------------------------------------------.
 * |      |     |      |  L12  |  L4  |     L2      |     |           |       |       |      |       | Back  |
 * |------+-----+------+-------+------+-------------+     |-----------+-------+-------+------+-------+-------|
 * | C/E  |  L1 |  L11 |  L10  |  L13 |     L14     |     |           |       |       |      |  :;   | Enter |
 * |------+-----+------+-------+------+-------------+     |-----------+-------+-------+------+-------+-------|
 * |      |     |      |       |  L6  |             |     |           |       | Marks | Punc | Pipes | Ticks |
 * |------+-----+------+-------+------+-------------|     |-----------+-------+-------+------+-------+-------|
 * |      |     |      |  Meh  |  Alt |  Gui / Spc  |     | Sft / Spc |       |       |      |       |       |
 * `------------------------------------------------`     `--------------------------------------------------'
 */
	[0] = LAYOUT( 
		KC_TRNS, KC_Q, KC_W, LT(12, KC_E), LT(4, KC_R), LT(2, KC_T),
    /*****/ KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
		LCTL_T(KC_ESC), LT(1, KC_A), LT(11, KC_S), LT(10, KC_D), LT(13, KC_F), LT(14, KC_G),
    /*****/ KC_H, KC_J, KC_K, KC_L, TD(CT_COLN), KC_ENT,
    KC_TRNS, KC_Z, KC_X, KC_C, LT(6, KC_V), KC_B,
    /*****/ KC_N, KC_M, TD(CT_MARK), TD(CT_PUNC), TD(CT_SLSH), TD(CT_TICKS), 
		LT(5, KC_TRNS), KC_TRNS, KC_TRNS, MEH_T(KC_TRNS), LALT_T(KC_TRNS), LGUI_T(KC_SPC),
    /*****/  LSFT_T(KC_SPC), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),

/* Vimulation
 * ,------------------------------------------     ,---------------------------------------------.
 * |      |      |      |      |      |      |     |       |       |       |       |      |      |
 * |------+------+------+------+------+------+     --------+-------+-------+-------+------+------|
 * |      |      |  L3  |      |      |      |     |   ←   |   ↓   |   ↑   |   →   |      |      |
 * |------+------+------+------+------+------+     --------+-------+-------+-------+------+------|
 * |      |      |      |      |      |      |     |       |       |       |       |      |      |
 * |------+------+------+------+------+------+     --------+-------+-------+-------+------+------|
 * |      |      |      |      |      |      |     |       |       |       |       |      |      |
 * `------------------------------------------     `---------------------------------------------'
 */

	[1] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, MO(3), KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

/* Media
 * ,------------------------------------------     ,-----------------------------------------------------.
 * |      |      |      |      |      |      |     |      |  Bright  |   Dim    |          |      |      |
 * |------+------+------+------+------+------+     -------+----------+----------+----------+------+------|
 * |      |      |      |      |      |      |     |   ⇇  |    ⇥     |    ⇤    |     ⇉    |      |      |
 * |------+------+------+------+------+------+     -------+----------+----------+----------+------+------|
 * |      |      |      |      |      |      |     | Mute |   Vol +  |   Vol -  |   Mute   |      |      |
 * |------+------+------+------+------+------+     -------+----------+----------+----------+------+------|
 * |      |      |      |      |      |      |     |      |          |          |          |      |      |
 * `------------------------------------------     `-----------------------------------------------------'
 */
	[2] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_BRIU, KC_BRID, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_MRWD, KC_MNXT, KC_MPRV, KC_MFFD, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_MUTE, KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

/* Mouse
 * ,--------------------------------------------------------------,     ,---------------------------------------------------------------------.
 * |      |      |      |             |             |             |     |   Wheel L   |   Wheel D   |   Wheel U   |   Mouse R   |      |      |
 * |------+------+------+-------------+-------------+-------------+     --------------+-------------+-------------+-------------+------+------|
 * |      |      |      |   Speed 2   |   Speed 1   |   Speed 0   |     |   Mouse L   |   Mouse D   |   Mouse U   |   Mouse R   |      |      |
 * |------+------+------+-------------+-------------+-------------+     --------------+-------------+-------------+-------------+------+------|
 * |      |      |      |             |             |             |     |             |    Btn L    |    Btn M    |    Btn R    |      |      |
 * |------+------+------+-------------+-------------+-------------|     |-------------+-------------+-------------+-------------+------+------|
 * |      |      |      |             |             |             |     |             |             |             |             |      |      |
 * `--------------------------------------------------------------'     `---------------------------------------------------------------------'
 */
	[3] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_ACL2, KC_ACL1, KC_ACL0, /*****/ KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_BTN1, KC_BTN3, KC_BTN2, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

/* Tabbing
 * ,-----------------------------------------.     ,----------------------------------------------------------.
 * |      |      |      |      |      |      |     |   S + ~   |   ~   |   S + ~   |   ~   |           |      |
 * |------+------+------+------+------+------|     |-----------+-------+-----------+-------+-----------+------|
 * |      |      |      |      |      |      |     |  S + Tab  |  Tab  |  S + Tab  |  Tab  |           |      |
 * |------+------+------+------+------+------|     |-----------+-------+-----------+-------+-----------+------|
 * |      |      |      |      |      |      |     |           |       |           |       |           |      |
 * |------+------+------+------+------+------|     |-----------+-------+-----------+-------+-----------+------|
 * |      |      |      |      |      |      |     |           |       |           |       |           |      |
 * `-----------------------------------------|     |----------------------------------------------------------'
 */
	[4] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ LSFT(KC_TILD), KC_TILD, LSFT(KC_TILD), KC_TILD, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_STAB, KC_TAB, KC_STAB, KC_TAB, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

/* Function keys
 * ,-----------------------------------------|     ,---------------------------------------------.
 * |      |      |      |      |      |      |     |  F1  |  F5  |  F9   |  F13  |  F17  |  F21  |
 * |------+------+------+------+------+------|     |------+------+-------+-------+-------+-------|
 * |      |      |      |      |      |      |     |  F2  |  F6  |  F10  |  F14  |  F18  |  F22  |
 * |------+------+------+------+------+------|     |------+------+-------+-------+-------+-------|
 * |      |      |      |      |      |      |     |  F3  |  F7  |  F11  |  F15  |  F19  |  F23  |
 * |------+------+------+------+------+------+     |------+------+-------+-------+-------+-------|
 * |      |      |      |      |      |      |     |  F4  |  F8  |  F12  |  F16  |  F20  |  F24  |
 * `-----------------------------------------'     '---------------------------------------------'
 */

	[5] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_F1, KC_F5, KC_F9, KC_F13, KC_F17, KC_F21, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_F2, KC_F6, KC_F10, KC_F14, KC_F18, KC_F22, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_F3, KC_F7, KC_F11, KC_F15, KC_F19, KC_F23, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_F4, KC_F8, KC_F12, KC_F16, KC_F20, KC_F24
  ),

/* 
 * ,------------------------------------------     ,-----------------------------------------.
 * |      |      |      |      |      |      |     | cnst |      |      |      |      |      |
 * |------+------+------+------+------+------+     -------+------+------+------+------+------|
 * |      |      |      |      |      |      |     | jsfn |  =>  |  ->  |      |      |      |
 * |------+------+------+------+------+------+     -------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      | push | reba |      |      |      |
 * |------+------+------+------+------+------+     -------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * `------------------------------------------     `-----------------------------------------'
 */
	[6] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ SIM_CONST, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ SIM_ARR_FN, SIM_FARR, SIM_SARR, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, SIM_GIT_PUSH, SIM_GIT_REBASE, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

/* 
 * ,------------------------------------------     ,-----------------------------------------.
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------+     -------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------+     -------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------+     -------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * `------------------------------------------     `-----------------------------------------'
 */
	[7] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

/* 
 * ,------------------------------------------     ,-----------------------------------------.
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------+     -------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------+     -------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------+     -------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * `------------------------------------------     `-----------------------------------------'
 */
[8] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

/* 
 * ,------------------------------------------     ,-----------------------------------------.
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------+     -------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------+     -------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------+     -------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * `------------------------------------------     `-----------------------------------------'
 */
	[9] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

/* Numbers 
 * ,------------------------------------------     ,-----------------------------------------.
 * |      |      |      |      |      |      |     |  #  |  7  |  8  |  9  |  %  |     |     |
 * |------+------+------+------+------+------+     ------+-----+-----+-----+-----+-----+-----|
 * |      |      |      |      |      |      |     |  +  |  4  |  5  |  6  |  -_ |     |     |
 * |------+------+------+------+------+------+     ------+-----+-----+-----+-----+-----+-----|
 * |      |      |      |      |      |      |     |  *  |  1  |  2  |  3  |  /  |     |     |
 * |------+------+------+------+------+------+     ------+-----+-----+-----+-----+-----+-----|
 * |      |      |      |      |      |      |     |  =  |  .  |  0  |     |     |     |     |
 * `------------------------------------------     `----------------------------------------'
 */
  [10] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_HASH, KC_7, KC_8, KC_9, KC_PERCENT, KC_BSPC, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_PPLS, KC_4, KC_5, KC_6, TD_DASH, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_ASTR, KC_1, KC_2, KC_3, KC_SLSH, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_EQL, KC_DOT, KC_0, KC_NO, KC_NO, KC_TRNS
  ),

/* Symbols
 * ,------------------------------------------     ,-----------------------------------------.
 * |      |      |      |      |      |      |     |  ~  |  /  |  |  |  \  |     |     |     |
 * |------+------+------+------+------+------+     ------+-----+-----+-----+-----+-----+-----|
 * |      |      |      |      |      |      |     |  ^  |  @  |  &  |  $  |     |     |     |
 * |------+------+------+------+------+------+     ------+-----+-----+-----+-----+-----+-----|
 * |      |      |      |      |      |      |     |     |     |     |     |     |     |     |
 * |------+------+------+------+------+------+     ------+-----+-----+-----+-----+-----+-----|
 * |      |      |      |      |      |      |     |     |     |     |     |     |     |     |
 * `------------------------------------------     `----------------------------------------'
 */
	[11] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /* **** */ KC_TILDA, KC_SLASH, KC_PIPE, KC_BSLASH, KC_TRNS, KC_BSPC,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /* **** */ KC_CARRET, KC_AT, KC_AMP, KC_DOLLAR, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /* **** */ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /* **** */ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS 
  ),

/* Browser Nav
 * ,------------------------------------------     ,----------------------------------------------------.
 * |      |      |      |      |      |      |     |        |        |        |           |      |      |
 * |------+------+------+------+------+------+     ---------+--------+--------+-----------+------+------|
 * |      |      |      |      |      |      |     |  Back  |  PG D  |  PG U  |  Forward  |      |      |
 * |------+------+------+------+------+------+     ---------+--------+--------+-----------+------+------|
 * |      |      |      |      |      |      |     |        |        |        |           |      |      |
 * |------+------+------+------+------+------+     ---------+--------+--------+-----------+------+------|
 * |      |      |      |      |      |      |     |        |        |        |           |      |      |
 * `------------------------------------------     `----------------------------------------------------'
 */
	[12] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /* **** */ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /* **** */ 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /* **** */ KC_WBAK, KC_PGDOWN, KC_PGUP, KC_WFWD, KC_TRNS, KC_TRNS, /* **** */ 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /* **** */ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /* **** */ 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /* **** */ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS /* **** */ 
  ),

/* Wrappers
 * ,------------------------------------------     ,-------------------------------------------------.
 * |      |      |      |      |      |      |     |   [I]   |   [   |   ]   |  [ I ]  |      |      |
 * |------+------+------+------+------+------+     ----------+-------+-------+---------+------+------|
 * |      |      |      |      |      |      |     |   (I)   |   (   |   )   |  ( I )  |      |      |
 * |------+------+------+------+------+------+     ----------+-------+-------+---------+------+------|
 * |      |      |      |      |      |      |     |   {I}   |   {   |   }   |  { I }  |      |      |
 * |------+------+------+------+------+------+     ----------+-------+-------+---------+------+------|
 * |      |      |      |      |      |      |     |   <I>   |   <   |   >   |  < I >  |  </> |      |
 * `------------------------------------------     `-------------------------------------------------'
 */
	[13] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /* **** */ SIM_BRACKETS, KC_LBRACKET, KC_RBRACKET, SIM_BRACKETS_SPC, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /* **** */ SIM_PARENS, KC_LPRN, KC_RPRN, SIM_PARENS_SPC, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /* **** */ SIM_BRACES, KC_LCBR, KC_RCBR, SIM_BRACES_SPC, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /* **** */ SIM_ANGLES, KC_LT , KC_GT, SIM_ANGLES_SPC, SIM_HTML_CLOSE, KC_TRNS 
  ),

/* Emojis
 * ,------------------------------------------     ,--------------------------------------------.
 * |      |      |      |      |      |      |     |  😎  |  😉  |  🤨  |  🤭  |  😲  |  BKSP  |
 * |------+------+------+------+------+------+     -------+------+------+------+-------+--------|
 * |      |      |      |      |      |      |     |  😁  |  🙂  |  😔  |  😞  |  🙄  |   🤐   |
 * |------+------+------+------+------+------+     -------+------+------+-------+------+--------|
 * |      |      |      |      |      |      |     |  💯  |  👍  |  ☝️  |  🎉  |  ☠  |   🤔   |
 * |------+------+------+------+------+------+     -------+------+------+------+-------+--------|
 * |      |      |      |      |      |      |     |      |      |      |      |       |        |
 * `------------------------------------------     `--------------------------------------------'
 */

	[14] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      /* **** */ X(GLASSES), X(WINK), X(DOUBT), X(GASPING), X(ASTONISHED), KC_BSPC,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      /* **** */ X(BEAMING), X(SMILING), X(PENSIVE), X(DISAPPOINTED), X(ROLLING), X(ZIPPED),  
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      /* **** */ X(HUNDRED), X(THUMBS_UP), X(POINT_UP), X(PARTY), X(SKULL), X(THINKING),
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      /* **** */ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS 
  ),
};