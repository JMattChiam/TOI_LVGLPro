/**
 * @file screen_1_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "screen_1_gen.h"
#include "../LVGLPro_TOI.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * screen_1_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    static bool style_inited = false;

    if (!style_inited) {

        style_inited = true;
    }

    if (screen_1 == NULL) screen_1 = lv_obj_create(NULL);
    lv_obj_t * lv_obj_0 = screen_1;
    lv_obj_set_name_static(lv_obj_0, "screen_1_#");

    lv_obj_bind_style(lv_obj_0, &style_dark_mode, 0, &is_dark_mode, 1);
    lv_obj_bind_style(lv_obj_0, &style_light_mode, 0, &is_dark_mode, 0);
    lv_obj_t * temperature_setting_room1 = temperature_setting_create(lv_obj_0);
    lv_obj_set_name(temperature_setting_room1, "temperature_setting_room1");
    lv_obj_set_align(temperature_setting_room1, LV_ALIGN_CENTER);

    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
    lv_label_set_text(lv_label_0, "Room 1");
    lv_obj_set_align(lv_label_0, LV_ALIGN_TOP_MID);
    lv_obj_set_y(lv_label_0, 20);
    lv_obj_set_style_text_font(lv_label_0, font_large, 0);

    lv_obj_t * lv_button_0 = lv_button_create(lv_obj_0);
    lv_obj_set_align(lv_button_0, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_y(lv_button_0, -50);
    lv_obj_t * lv_label_1 = lv_label_create(lv_button_0);
    lv_label_set_text(lv_label_1, "Toggle style");

    lv_obj_add_subject_toggle_event(lv_button_0, &is_dark_mode, LV_EVENT_CLICKED);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

