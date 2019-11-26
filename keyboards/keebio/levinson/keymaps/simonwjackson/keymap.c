#include QMK_KEYBOARD_H

// void eeconfig_init_user(void) {
//     set_unicode_input_mode(UC_OSX);
// }

enum custom_keycodes {
  SIM_BRACKETS = SAFE_RANGE,
  SIM_PARENS,
  SIM_BRACES,
  SIM_ANGLES
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SIM_BRACKETS:
      if (record->event.pressed) {
        // when keycode SIM_PARENS is pressed
        SEND_STRING("[]" SS_TAP(X_LEFT));
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
    case SIM_BRACES:
      if (record->event.pressed) {
        // when keycode SIM_PARENS is pressed
        SEND_STRING("{}" SS_TAP(X_LEFT));
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
  }

  return true;
};

//Tap Dance Declarations
enum {
  CT_OPEN = 0,
  CT_CLOSE = 1,
  CT_PUNC = 2,
  CT_SLSH = 3,
  CT_TICKS = 4,
  CT_COLN = 5
};

enum unicode_names {
    BANG,
    IRONY,
    SNEK
};

const uint32_t PROGMEM unicode_map[] = {
    [BANG]  = 0x203D,  // ‽
    [IRONY] = 0x2E2E,  // ⸮
    [SNEK]  = 0x1F40D, // 🐍
};

void dance_open_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_LBRACKET); 
	}
  else if (state->count == 2) {
    register_code (KC_RSFT);
    register_code (KC_9);
  }
  else if (state->count == 3) {
    register_code (KC_RSFT);
    register_code (KC_LBRACKET); 
  } 
	else {
    register_code (KC_RSFT);
    register_code (KC_COMMA); 
  }
}

void dance_open_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_LBRACKET); 
	}
  else if (state->count == 2) {
    unregister_code (KC_RSFT);
    unregister_code (KC_9);
  }
  else if (state->count == 3) {
    unregister_code (KC_RSFT);
    unregister_code (KC_LBRACKET); 
  } 
	else {
    unregister_code (KC_RSFT);
    unregister_code (KC_COMMA); 
  }
}

void dance_close_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_RBRACKET); 
	}
  else if (state->count == 2) {
    register_code (KC_RSFT);
    register_code (KC_0);
  }
  else if (state->count == 3) {
    register_code (KC_RSFT);
    register_code (KC_RBRACKET); 
  } 
	else {
    register_code (KC_RSFT);
    register_code (KC_DOT); 
  }
}

void dance_close_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_RBRACKET); 
	}
  else if (state->count == 2) {
    unregister_code (KC_RSFT);
    unregister_code (KC_0);
  }
  else if (state->count == 3) {
    unregister_code (KC_RSFT);
    unregister_code (KC_RBRACKET); 
  } 
	else {
    unregister_code (KC_RSFT);
    unregister_code (KC_DOT); 
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

// All tap dance functions would go here. Only showing this one.
qk_tap_dance_action_t tap_dance_actions[] = {
 [CT_OPEN] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_open_finished, dance_open_reset),
 [CT_CLOSE] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_close_finished, dance_close_reset),
 [CT_PUNC] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_punctuation_finished, dance_punctuation_reset),
 [CT_SLSH] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_slash_finished, dance_slash_reset),
 [CT_TICKS] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_ticks_finished, dance_ticks_reset),
 [CT_COLN] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_colon_finished, dance_colon_reset),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT( 
		LT(1,KC_TRNS), KC_Q, KC_W, KC_E, KC_R, KC_T,                              /*****/ KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
		LCTL_T(KC_ESC), LT(13,KC_A), LT(12,KC_S), LT(11,KC_D), LT(10,KC_F), KC_G, /*****/ KC_H, KC_J, KC_K, KC_L, TD(CT_COLN), KC_ENT,
    LT(2, KC_TRNS), KC_Z, KC_X, KC_C, KC_V, KC_B,                             /*****/ KC_N, KC_M, TD(CT_OPEN), TD(CT_PUNC), TD(CT_SLSH), TD(CT_TICKS), 
		LT(3, KC_TRNS), KC_TRNS, LCAG_T(KC_TRNS), MEH_T(KC_TRNS), LALT_T(KC_TRNS), LGUI_T(KC_SPC), /*****/  LSFT_T(KC_SPC), KC_TRNS, LT(4,KC_LBRC), LT(5,KC_RBRC), LT(6,KC_BSLS), LT(7,KC_RPRN)
	),

	[1] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

	[2] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_BRID, KC_BRIU, KC_TRNS, LSFT(KC_TAB), KC_DEL, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_VOLD, KC_VOLU, KC_DEL, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TAB, LGUI(LCTL(KC_LEFT)), LGUI(LCTL(KC_RIGHT)), KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

	[3] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_BTN1, KC_BTN3, KC_BTN2, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_ACL2, KC_ACL1, KC_ACL0, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

	[4] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

	[5] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

	[6] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

	[7] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

	[8] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

	[9] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_7, KC_8, KC_9, KC_TRNS, KC_BSPC, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_4, KC_5, KC_6, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_1, KC_2, KC_3, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_0, KC_TRNS, KC_TRNS, KC_TRNS
  ),

	// Numbers
  [10] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_7, KC_8, KC_9, KC_TRNS, KC_BSPC, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_4, KC_5, KC_6, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_1, KC_2, KC_3, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /*****/ KC_TRNS, KC_TRNS, KC_0, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  // Symbols
	[11] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /* **** */ KC_TRNS, KC_TRNS, LSFT(KC_6), LSFT(KC_4), KC_TRNS, KC_BSPC,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /* **** */ LSFT(KC_2), LSFT(KC_8), KC_PPLS, KC_PMNS, KC_SLSH, LSFT(KC_7), 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /* **** */ KC_TRNS, LSFT(KC_3), KC_EQL, LSFT(KC_MINS), LSFT(KC_5), KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /* **** */ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS 
  ),

  // Wrappers
	[12] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /* **** */ KC_TRNS, KC_LBRC, LSFT(KC_9), LSFT(KC_LBRC), LSFT(KC_COMM), KC_BSPC, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /* **** */ KC_TRNS, SIM_BRACKETS, SIM_PARENS, SIM_BRACES, SIM_ANGLES, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /* **** */ KC_TRNS, KC_RBRC, LSFT(KC_0), LSFT(KC_RBRC), LSFT(KC_DOT), KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /* **** */ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  //  Punctuation
	[13] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /* **** */ KC_TRNS, KC_SLSH, LSFT(KC_BSLS), KC_BSLS, KC_TRNS, KC_BSPC,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /* **** */ KC_TRNS, KC_DOT, KC_COMM, LSFT(KC_SLSH), LSFT(KC_1), KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /* **** */ KC_TRNS, KC_QUOTE, LSFT(KC_QUOTE), KC_GRV, LSFT(KC_GRV), KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /* **** */ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
};