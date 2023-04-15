#include "quantum/keycodes.h"

// macOS shortcuts
#define Z_UND	G(KC_Z)
#define Z_CUT	G(KC_X)
#define Z_CPY	G(KC_C)
#define Z_PST	G(KC_V)
#define Z_LOCK	C(G(KC_Q))
#define Z_SLEEP	A(G(KC_PWR))
#define Z_SHUT	C(A(G(KC_PWR)))
#define Z_SSAVE	HYPR(KC_S)

// Tap hold macros
#define TH_M	LT(0,KC_M)
#define TH_COMM	LT(0,KC_COMM)
#define TH_DOT	LT(0,KC_DOT)
#define TH_SLSH	LT(0,KC_SLSH)
#define TH(k1,k2,k3,k4) LT(0,k1),LT(0,k2),LT(0,k3),LT(0,k4)

// Home row mod-tap macros
#define HRML(k1,k2,k3,k4) LGUI_T(k1),LALT_T(k2),LCTL_T(k3),LSFT_T(k4)
#define HRMR(k1,k2,k3,k4) RSFT_T(k1),RCTL_T(k2),LALT_T(k3),RGUI_T(k4)

// Navigation shortcuts
#define SA_UP S(A(KC_UP))
#define SA_DN S(A(KC_DOWN))

// Layers 
enum custom_layers { BSE, TGL, NUM, SYM, FNC };

// Default 3x5_2 split layout
#define _COLE \
/* ╭────────┬────────┬────────┬────────┬────────╮   ╭────────┬────────┬────────┬────────┬────────╮ */\
/* │  Q     │  W     │  F     │  P     │  B     │   │  J     │  L     │  U     │  Y     │ ' "    │ */\
	KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,    \
/* ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤ */\
/* │  A     │  R     │  S     │  T     │  G     │   │  M     │  N     │  E     │  I     │  O     │ */\
	KC_A,    KC_R,    KC_S,    KC_T,    KC_G,        KC_M,    KC_N,    KC_E,    KC_I,    KC_O,       \
/* ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤ */\
/* │  Z     │  X     │  C     │  D     │  V     │   │  K     │  H     │ , <    │ . >    │ / ?    │ */\
	KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,        KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,    \
/* ╰────────┴────────┴────────┼────────┼────────┤   ├────────┼────────┼────────┴────────┴────────╯ */\
              	  			   MO(SYM), KC_SPC,      KC_ENT,  MO(NUM)
/*                            ╰────────┴────G───╯   ╰────────┴────────╯ */
#define _QWER \
/* ╭────────┬────────┬────────┬────────┬────────╮   ╭────────┬────────┬────────┬────────┬────────╮ */\
/* │  Q     │  W     │  E     │  R     │  T     │   │  Y     │  U     │  I     │  O     │  P     │ */\
	KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,       \
/* ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤ */\
/* │  A     │  S     │  D     │  F     │  G     │   │  H     │  J     │  K     │  L     │ ' "    │ */\
	KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT,    \
/* ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤ */\
/* │  Z     │  X     │  C     │  V     │  B     │   │  N     │  M     │ , <    │ . >    │ / ?    │ */\
	KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    \
/* ╰────────┴────────┴────────┼────────┼────────┤   ├────────┼────────┼────────┴────────┴────────╯ */\
              	  			   MO(SYM), KC_SPC,      KC_ENT,  MO(NUM)
/*                            ╰────────┴────────╯   ╰────────┴────────╯ */
	
#define _GAME \
/* ╭────────┬────────┬────────┬────────┬────────╮   ╭────────┬────────┬────────┬────────┬────────╮ */\
/* │  Q     │  W     │  E     │  R     │  T     │   │  Y     │  U     │  I     │  O     │  P     │ */\
    KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,      \
/* ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤ */\
/* │  A     │  S     │  D     │  F     │  G     │   │  H     │  J     │  K     │  L     │ ' "    │ */\
    KC_LSFT,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,      \
/* ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤ */\
/* │  Z     │  X     │  C     │  V     │  B     │   │  N     │  M     │ , <    │ . >    │ / ?    │ */\
    KC_LCTL,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,    \
/* ╰────────┴────────┴────────┼────────┼────────┤   ├────────┼────────┼────────┴────────┴────────╯ */\
              	  			   MO(SYM), KC_SPC,      KC_ENT,  MO(NUM)
/*                            ╰────────┴────────╯   ╰────────┴────────╯ */
#define _NUMB \
/* ╭────────┬────────┬────────┬────────┬────────╮   ╭────────┬────────┬────────┬────────┬────────╮ */\
/* │ INSERT │  1     │  2     │  3     │ VOL UP │   │ HOME   │ PG DN  │ PG UP  │ END    │  :     │ */\
	KC_INS,  KC_1,    KC_2,    KC_3,    KC_VOLU,     KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_COLN,    \
/* ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤ */\
/* │ DELETE │  4     │  5     │  6     │ VOL DN │   │ LEFT   │ DOWN   │ UP     │ RIGHT  │  ;     │ */\
	KC_DEL,  KC_4,    KC_5,    KC_6,    KC_VOLD,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_SCLN,    \
/* ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤ */\
/* │ CAPS   │  7     │  8     │  9     │  0     │   │        │SHFTA DN│SHFTA UP│        │        │ */\
	KC_CAPS, KC_7,    KC_8,    KC_9,    KC_0,        _______,  SA_DN,   SA_UP,  _______, _______,    \
/* ╰────────┴────────┴────────┼────────┼────────┤   ├────────┼────────┼────────┴────────┴────────╯ */\
	                           MO(FNC), QK_GESC,     _______, _______
/*                            ╰────────┴────────╯   ╰────────┴────────╯ */
#define _SYMB \
/* ╭────────┬────────┬────────┬────────┬────────╮   ╭────────┬────────┬────────┬────────┬────────╮ */\
/* │        │  [     │  {     │  }     │        │   │  ^     │  (     │  )     │  ]     │  ~     │ */\
	_______, KC_LBRC, KC_LCBR, KC_RCBR, _______,     KC_CIRC, KC_LPRN, KC_RPRN, KC_RBRC, KC_TILD,    \
/* ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤ */\
/* │  !     │  @     │  #     │  $     │  %     │   │  *     │  -     │  =     │  \     │  `     │ */\
	KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,     KC_ASTR, KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,     \
/* ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤ */\
/* │        │        │        │        │        │   │  &     │  _     │  +     │  │     │        │ */\
	_______, _______, _______, _______, _______,     KC_AMPR, KC_UNDS, KC_PLUS, KC_PIPE, _______,    \
/* ╰────────┴────────┴────────┼────────┼────────┤   ├────────┼────────┼────────┴────────┴────────╯ */\
	                           _______, _______,     _______, MO(FNC)
/*                            ╰────────┴────────╯   ╰────────┴────────╯ */
#define _FUNC \
/* ╭────────┬────────┬────────┬────────┬────────╮   ╭────────┬────────┬────────┬────────┬────────╮ */\
/* │ BOOT   │  F1    │  F2    │  F3    │ F10    │   │        │ WH UP  │ WH DN  │        | TOGGLE │ */\
	QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F10,      _______, KC_WH_U, KC_WH_D, _______, TG(TGL),    \
/* ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤ */\
/* │        │  F4    │  F5    │  F6    │ F11    │   │ MS LFT │ MS DN  │ MS UP  │ MS RHT │        │ */\
	_______, KC_F4,   KC_F5,   KC_F6,   KC_F11,      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,    \
/* ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤ */\
/* │ LOCK   │  F7    │  F8    │  F9    │ F12    │   │        │ BTN 2  │ BTN 1  │        │ SSAVE  │ */\
	 Z_LOCK, KC_F7,   KC_F8,   KC_F9,   KC_F12,      _______, KC_BTN2, KC_BTN1, _______, Z_SSAVE,    \
/* ╰────────┴────────┴────────┼────────┼────────┤   ├────────┼────────┼────────┴────────┴────────╯ */\	
	                           _______, QK_RBT,      _______, _______
/*                            ╰────────┴────────╯   ╰────────┴────────╯ */

// Mod-tap wrapper
#define HRM(k) HR_MODTAP(k)
#define HR_MODTAP( \
	  l01, l02, l03, l04, l05,   r01, r02, r03, r04, r05, \
	  l06, l07, l08, l09, l10,   r06, r07, r08, r09, r10, \
	  l11, l12, l13, l14, l15,   r11, r12, r13, r14, r15, \
	                 l16, l17,   r16, r17                 \
) \
	  l01, l02, l03, l04, l05,   r01, r02, r03, r04, r05,       \
HRML(l06, l07, l08, l09), l10,   r06, HRMR(r07, r08, r09, r10), \
	  l11, l12, l13, l14, l15,   r11,   TH(r12, r13, r14, r15), \
	                 l16, l17,   r16, r17


// Layout aliases for json keymap
#define LAYOUT_34key_w(...) LAYOUT_split_3x5_2(__VA_ARGS__)
#define LAYOUT_crkbd_w(...) LAYOUT_split_3x6_3(__VA_ARGS__)
#define LAYOUT_58key_w(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_ortho_w(...) LAYOUT_ortho_4x12(__VA_ARGS__)


// Convert 3x5_2 to 42-key
#define C_42(k) CONV_42(k)
#define CONV_42( \
	     l01, l02, l03, l04, l05,   r01, r02, r03, r04, r05, \
	     l06, l07, l08, l09, l10,   r06, r07, r08, r09, r10, \
	     l11, l12, l13, l14, l15,   r11, r12, r13, r14, r15, \
	                    l16, l17,   r16, r17                 \
) \
KC_TAB,  l01, l02, l03, l04, l05,   r01, r02, r03, r04, r05, KC_BSPC, \
QK_GESC, l06, l07, l08, l09, l10,   r06, r07, r08, r09, r10, KC_SCLN, \
KC_LSFT, l11, l12, l13, l14, l15,   r11, r12, r13, r14, r15, KC_ENT,  \
	     RSA_T(KC_ESC), l16, l17,   r16, r17, RAG_T(KC_DEL)

// Convert 3x5_2 to 4x12
#define C_O(k) CONV_4x12(k)
#define CONV_4x12( \
	                      l01, l02, l03, l04, l05, r01, r02, r03, r04, r05, \
	                      l06, l07, l08, l09, l10, r06, r07, r08, r09, r10, \
	                      l11, l12, l13, l14, l15, r11, r12, r13, r14, r15, \
	                                     l16, l17, r16, r17                 \
) \
                 KC_TAB,  l01, l02, l03, l04, l05, r01, r02, r03, r04, r05, KC_BSPC, \
                 QK_GESC, l06, l07, l08, l09, l10, r06, r07, r08, r09, r10, KC_SCLN, \
                 KC_LSFT, l11, l12, l13, l14, l15, r11, r12, r13, r14, r15, KC_ENT,  \
KC_DEL, KC_VOLD, KC_VOLU, RSA_T(KC_ESC), l16, l17, r16, r17, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT

// Convert 3x5_2 to 58-key
#define C_58(k) CONV_58(k)
#define CONV_58( \
	     l01, l02, l03, l04, l05,   r01, r02, r03, r04, r05, \
	     l06, l07, l08, l09, l10,   r06, r07, r08, r09, r10, \
	     l11, l12, l13, l14, l15,   r11, r12, r13, r14, r15, \
	                    l16, l17,   r16, r17                 \
) \
QK_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_GRV , \
KC_TAB , l01    , l02    , l03    , l04    , l05    ,                   r01    , r02    , r03    , r04    , r05    , KC_MINS, \
KC_LCTL, l06    , l07    , l08    , l09    , l10    ,                   r06    , r07    , r08    , r09    , r10    , KC_QUOT, \
KC_LSFT, l11    , l12    , l13    , l14    , l15    , KC_LBRC, KC_RBRC, r11    , r12    , r13    , r14    , r15    , KC_RSFT, \
                           KC_LALT, KC_LGUI, l16    , l17    , r16    , r17    , KC_BSPC, KC_RGUI
