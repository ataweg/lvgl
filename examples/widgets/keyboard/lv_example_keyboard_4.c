// 2024-02-11 added by AWe

#include "../../lv_examples.h"
#if LV_USE_KEYBOARD && LV_BUILD_EXAMPLES

#include <stdio.h>
#include <string.h>

// uses localized keyboard (here german keyboard with umlauts),
// and font with umlaut glyphs to extend the default font

// lower case
static const char * const german_kb_map_lc[] =
{
   "q", "w", "e", "r", "t", "z", "u", "i", "o", "p", "ü", LV_SYMBOL_BACKSPACE, "\n",
   "a", "s", "d", "f", "g", "h", "j", "k", "l", "ö", "ä", LV_SYMBOL_NEW_LINE, "\n",
   "ABC", "y", "x", "c", "v", "b", "n", "m", ",", ".", "-", "\n",
   "!#1", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, LV_SYMBOL_OK, ""
};

static const lv_buttonmatrix_ctrl_t german_kb_ctrl_lc_map[] = {
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, LV_BUTTONMATRIX_CTRL_CHECKED | 7,
    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, LV_BUTTONMATRIX_CTRL_CHECKED | 7,
    LV_KEYBOARD_CTRL_BUTTON_FLAGS | 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    LV_KEYBOARD_CTRL_BUTTON_FLAGS | 2, LV_BUTTONMATRIX_CTRL_CHECKED | 2, 8, LV_BUTTONMATRIX_CTRL_CHECKED | 2, LV_KEYBOARD_CTRL_BUTTON_FLAGS | 2
};

// upper case
static const char * const german_kb_map_uc[] =
{
   "Q", "W", "E", "R", "T", "Z", "U", "I", "O", "P", "Ü", LV_SYMBOL_BACKSPACE, "\n",
   "A", "S", "D", "F", "G", "H", "J", "K", "L", "Ö", "Ä", LV_SYMBOL_NEW_LINE, "\n",
   "abc", "Y", "X", "C", "V", "B", "N", "M", ";", ":", "_", "\n",
   "!#1", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, LV_SYMBOL_OK, ""
};

static const lv_buttonmatrix_ctrl_t german_kb_ctrl_uc_map[] = {
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, LV_BUTTONMATRIX_CTRL_CHECKED | 7,
    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, LV_BUTTONMATRIX_CTRL_CHECKED | 7,
    LV_KEYBOARD_CTRL_BUTTON_FLAGS | 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    LV_KEYBOARD_CTRL_BUTTON_FLAGS | 2, LV_BUTTONMATRIX_CTRL_CHECKED | 2, 8, LV_BUTTONMATRIX_CTRL_CHECKED | 2, LV_KEYBOARD_CTRL_BUTTON_FLAGS | 2
};

// special 1/2
static const char * const german_kb_map_spec1[] =
{
  "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "ß", LV_SYMBOL_BACKSPACE, "\n",
  "!", "\"", "@", "$", "%", "&", "/", "(", ")", "=", "?", LV_SYMBOL_NEW_LINE, "\n",
  "2/2", "<", ">", "|", "{", "[", "]", "}", "*", "+", "-", "\n",
  //  ` ´  * + ~ # '    , . - ; : _
   "abc", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, LV_SYMBOL_OK, ""
};

static const lv_buttonmatrix_ctrl_t german_kb_ctrl_spec1_map[] = {
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, LV_BUTTONMATRIX_CTRL_CHECKED | 7,
    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, LV_BUTTONMATRIX_CTRL_CHECKED | 7,
    LV_KEYBOARD_CTRL_BUTTON_FLAGS | 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    LV_KEYBOARD_CTRL_BUTTON_FLAGS | 2, LV_BUTTONMATRIX_CTRL_CHECKED | 2, 8, LV_BUTTONMATRIX_CTRL_CHECKED | 2, LV_KEYBOARD_CTRL_BUTTON_FLAGS | 2
};

// special 2/2
static const char * const german_kb_map_spec2[] =
{
  "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "ß", LV_SYMBOL_BACKSPACE, "\n",
  "^", "°", "§", "€", "~", "\\","/", "´", ".", "=", "#", LV_SYMBOL_NEW_LINE, "\n",
  "1/2", "µ", "²", "³", " ", "'", "`", ",", "*", "+", "-", "\n",
   "abc", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, LV_SYMBOL_OK, ""
};

static const lv_buttonmatrix_ctrl_t german_kb_ctrl_spec2_map[] = {
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, LV_BUTTONMATRIX_CTRL_CHECKED | 7,
    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, LV_BUTTONMATRIX_CTRL_CHECKED | 7,
    LV_KEYBOARD_CTRL_BUTTON_FLAGS | 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    LV_KEYBOARD_CTRL_BUTTON_FLAGS | 2, LV_BUTTONMATRIX_CTRL_CHECKED | 2, 8, LV_BUTTONMATRIX_CTRL_CHECKED | 2, LV_KEYBOARD_CTRL_BUTTON_FLAGS | 2
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
       uint16_t button_id   = lv_buttonmatrix_get_selected_button(obj);
       if(button_id == LV_BUTTONMATRIX_BUTTON_NONE) return;

       const char * txt = lv_buttonmatrix_get_button_text(obj, lv_buttonmatrix_get_selected_button(obj));
       if(txt == NULL) return;

       printf("Button %s pressed\r\n", txt);
       if(strcmp(txt, "ABC") == 0) {
           lv_keyboard_set_mode( obj, LV_KEYBOARD_MODE_TEXT_UPPER);
           return;
       }
       else if(strcmp(txt, "abc") == 0) {
           lv_keyboard_set_mode( obj, LV_KEYBOARD_MODE_TEXT_LOWER );
           return;
       }
       else if(strcmp(txt, "1/2") == 0 || strcmp(txt, "!#1") == 0 ) {
           lv_keyboard_set_mode( obj, LV_KEYBOARD_MODE_SPECIAL );
           return;
       }
       else if(strcmp(txt, "2/2") == 0) {
           lv_keyboard_set_mode( obj, LV_KEYBOARD_MODE_USER_1 );
           return;
       }
   }

   lv_keyboard_def_event_cb( e );
}

void remove_event(lv_obj_t* obj, lv_event_cb_t event_cb )
{
    lv_event_dsc_t* event_dsc = NULL;
    uint32_t event_cnt = lv_obj_get_event_count(obj);
    uint32_t i;
    for (i = 0; i < event_cnt; i++) {
        event_dsc = lv_obj_get_event_dsc(obj, i);
        if (lv_event_dsc_get_cb(event_dsc) == event_cb) {
            break;
        }
    }
    if (event_dsc) {
        lv_free(lv_event_dsc_get_user_data(event_dsc));
        lv_obj_remove_event(obj, i);
    }
}

// default font for the examples is lv_font_montserrat_14
LV_FONT_DECLARE( font_montserrat_ger_14 )
lv_style_t my_style;

void lv_example_keyboard_4(void)
{
    /*Create a keyboard to use it with an of the text areas*/
    lv_obj_t * kb = lv_keyboard_create(lv_scr_act());
    lv_keyboard_set_map( kb, LV_KEYBOARD_MODE_TEXT_LOWER, (const char **)german_kb_map_lc, german_kb_ctrl_lc_map );
    lv_keyboard_set_map( kb, LV_KEYBOARD_MODE_TEXT_UPPER, (const char **)german_kb_map_uc, german_kb_ctrl_uc_map );
    lv_keyboard_set_map( kb, LV_KEYBOARD_MODE_SPECIAL, (const char **)german_kb_map_spec1, german_kb_ctrl_spec1_map );
    lv_keyboard_set_map( kb, LV_KEYBOARD_MODE_USER_1, (const char **)german_kb_map_spec2, german_kb_ctrl_spec2_map );
    lv_keyboard_set_mode( kb, LV_KEYBOARD_MODE_TEXT_LOWER );
    remove_event(kb, lv_keyboard_def_event_cb);
    lv_obj_add_event_cb(kb, kb_event_cb, LV_EVENT_VALUE_CHANGED, NULL);

    // extend font with german umlaut
    lv_font_t* ff = (lv_font_t*)lv_obj_get_style_text_font( kb, 0 );
    lv_font_t* f = (lv_font_t*)&font_montserrat_ger_14;
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
