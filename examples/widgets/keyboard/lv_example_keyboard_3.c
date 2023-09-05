#include "../../lv_examples.h"
#if LV_USE_KEYBOARD && LV_BUILD_EXAMPLES

#define LV_KB_BTN(width) LV_BTNMATRIX_CTRL_POPOVER | width

// lower case
static const char * const german_kb_map_lc[] =
{
   "q", "w", "e", "r", "t", "z", "u", "i", "o", "p", "ü", LV_SYMBOL_BACKSPACE, "\n",
   "a", "s", "d", "f", "g", "h", "j", "k", "l", "ö", "ä", LV_SYMBOL_NEW_LINE, "\n",
   "ABC", "y", "x", "c", "v", "b", "n", "m", ".", ",", "ß", "\n",
   "!#1", LV_SYMBOL_KEYBOARD, LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, LV_SYMBOL_OK, ""
};

static const lv_btnmatrix_ctrl_t german_kb_ctrl_lc_map[] = {
    LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_BTNMATRIX_CTRL_CHECKED | 7,
    LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_BTNMATRIX_CTRL_CHECKED | 7,
    LV_KEYBOARD_CTRL_BTN_FLAGS | 2, LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1),
    LV_KEYBOARD_CTRL_BTN_FLAGS | 2, LV_BTNMATRIX_CTRL_CHECKED | 2, LV_BTNMATRIX_CTRL_CHECKED | 2, 8, LV_BTNMATRIX_CTRL_CHECKED | 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 2
};

// upper case
static const char * const german_kb_map_uc[] =
{
   "Q", "W", "E", "R", "T", "Z", "U", "I", "O", "P", "Ü", LV_SYMBOL_BACKSPACE, "\n",
   "A", "S", "D", "F", "G", "H", "J", "K", "L", "Ö", "Ä", LV_SYMBOL_NEW_LINE, "\n",
   "abc", "Y", "X", "C", "V", "B", "N", "M", ".", "*", ":", "\n",
   "!#1", LV_SYMBOL_KEYBOARD, LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, LV_SYMBOL_OK, ""
};

static const lv_btnmatrix_ctrl_t german_kb_ctrl_uc_map[] = {
    LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_BTNMATRIX_CTRL_CHECKED | 7,
    LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_BTNMATRIX_CTRL_CHECKED | 7,
    LV_KEYBOARD_CTRL_BTN_FLAGS | 2, LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1),
    LV_KEYBOARD_CTRL_BTN_FLAGS | 2, LV_BTNMATRIX_CTRL_CHECKED | 2, LV_BTNMATRIX_CTRL_CHECKED | 2, 8, LV_BTNMATRIX_CTRL_CHECKED | 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 2
};

// special 1/2
static const char * const german_kb_map_spec1[] =
{
  "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", LV_SYMBOL_BACKSPACE, "\n",
  "+", "-", "/", "*", "=", "%", "!", "?", "#", "<", ">", LV_SYMBOL_NEW_LINE, "\n",
  "1/2", "\\", "@", "$", "(", ")", "{", "}", "[", "]", ";", "\"", "'", "\n",
   "abc", LV_SYMBOL_KEYBOARD, LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, LV_SYMBOL_OK, ""
};

static const lv_btnmatrix_ctrl_t german_kb_ctrl_spec1_map[] = {
    LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_BTNMATRIX_CTRL_CHECKED | 7,
    LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_BTNMATRIX_CTRL_CHECKED | 7,
    LV_KEYBOARD_CTRL_BTN_FLAGS | 2, LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1),
    LV_KEYBOARD_CTRL_BTN_FLAGS | 2, LV_BTNMATRIX_CTRL_CHECKED | 2, LV_BTNMATRIX_CTRL_CHECKED | 2, 8, LV_BTNMATRIX_CTRL_CHECKED | 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 2
};

// special 2/2
static const char * const german_kb_map_spec2[] =
{
  "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", LV_SYMBOL_BACKSPACE, "\n",
  "+", "-", "/", "*", "=", "%", "!", "?", "#", "<", ">", LV_SYMBOL_NEW_LINE, "\n",
  "2/2", "\\", "@", "$", "(", ")", "{", "}", "[", "]", ";", "\"", "'", "\n",
   "abc", LV_SYMBOL_KEYBOARD, LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, LV_SYMBOL_OK, ""
};

static const lv_btnmatrix_ctrl_t german_kb_ctrl_spec2_map[] = {
    LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_KB_BTN(4), LV_BTNMATRIX_CTRL_CHECKED | 7,
    LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_KB_BTN(3), LV_BTNMATRIX_CTRL_CHECKED | 7,
    LV_KEYBOARD_CTRL_BTN_FLAGS | 2, LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1),
    LV_KEYBOARD_CTRL_BTN_FLAGS | 2, LV_BTNMATRIX_CTRL_CHECKED | 2, LV_BTNMATRIX_CTRL_CHECKED | 2, 8, LV_BTNMATRIX_CTRL_CHECKED | 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 2
};

static void ta_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    lv_obj_t * kb = lv_event_get_user_data(e);
    if(code == LV_EVENT_FOCUSED) {
        lv_keyboard_set_textarea(kb, ta);
        lv_obj_clear_flag(kb, LV_OBJ_FLAG_HIDDEN);
    }

    else if(code == LV_EVENT_DEFOCUSED) {
        lv_keyboard_set_textarea(kb, NULL);
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
    }
}

static void kb_event_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    lv_event_code_t code = lv_event_get_code(e);

    if(code == LV_EVENT_VALUE_CHANGED ) {
       lv_keyboard_t * keyboard = (lv_keyboard_t *)obj;
       uint16_t btn_id   = lv_btnmatrix_get_selected_btn(obj);
       if(btn_id == LV_BTNMATRIX_BTN_NONE) return;

       const char * txt = lv_btnmatrix_get_btn_text(obj, lv_btnmatrix_get_selected_btn(obj));
       if(txt == NULL) return;

       printf("Button % s pressed\r\n", txt);
       if(strcmp(txt, "ABC") == 0) {
           lv_keyboard_set_mode( obj, LV_KEYBOARD_MODE_USER_1 );
           return;
       }
       else if(strcmp(txt, "abc") == 0) {
           lv_keyboard_set_mode( obj, LV_KEYBOARD_MODE_USER_2 );
           return;
       }
       else if(strcmp(txt, "2/2") == 0 || strcmp(txt, "!#1") == 0 ) {
           lv_keyboard_set_mode( obj, LV_KEYBOARD_MODE_USER_3 );
           return;
       }
       else if(strcmp(txt, "1/2") == 0) {
           lv_keyboard_set_mode( obj, LV_KEYBOARD_MODE_USER_4 );
           return;
       }
   }

   lv_keyboard_def_event_cb( e );
}

LV_FONT_DECLARE( font_montserrat_ger_16 )
lv_style_t my_style;

void lv_example_keyboard_3(void)
{
    /*Create a keyboard to use it with an of the text areas*/
    lv_obj_t * kb = lv_keyboard_create(lv_scr_act());
    lv_keyboard_set_map( kb, LV_KEYBOARD_MODE_USER_1, (const char *)german_kb_map_uc, german_kb_ctrl_uc_map );
    lv_keyboard_set_map( kb, LV_KEYBOARD_MODE_USER_2, (const char *)german_kb_map_lc, german_kb_ctrl_lc_map );
    lv_keyboard_set_map( kb, LV_KEYBOARD_MODE_USER_3, (const char *)german_kb_map_spec1, german_kb_ctrl_spec1_map );
    lv_keyboard_set_map( kb, LV_KEYBOARD_MODE_USER_4, (const char *)german_kb_map_spec2, german_kb_ctrl_spec2_map );
    lv_keyboard_set_mode( kb, LV_KEYBOARD_MODE_USER_1 );
    lv_obj_remove_event_cb( kb, lv_keyboard_def_event_cb );
    lv_obj_add_event_cb(kb, kb_event_cb, LV_EVENT_VALUE_CHANGED, NULL);

    // extend font with german umlaut
    lv_font_t* ff = lv_obj_get_style_text_font( kb, 0 );
    lv_font_t* f = &font_montserrat_ger_16;
    f->fallback = ff;
    lv_style_init( &my_style );
    lv_style_set_text_font(&my_style, f );
    lv_obj_add_style( kb, &my_style, 0 );

    /*Create a text area. The keyboard will write here*/
    lv_obj_t * ta;
    ta = lv_textarea_create(lv_scr_act());
    lv_obj_align(ta, LV_ALIGN_TOP_MID, 0, 10);
    lv_obj_set_size(ta, lv_pct(90), 80);
    lv_obj_add_style( ta,  &my_style, 0 );

    lv_obj_add_event_cb(ta, ta_event_cb, LV_EVENT_ALL, kb);
    lv_keyboard_set_textarea(kb, ta);
}
#endif
