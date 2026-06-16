/**
 * @file temperature_setting_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "temperature_setting_gen.h"
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

static lv_anim_timeline_t * timeline_timeline_modified_value_create(lv_obj_t * obj);
static void free_timeline_event_cb(lv_event_t * e);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * temperature_setting_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_temp_setting_dark;
    static lv_style_t style_temp_setting_light;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_temp_setting_dark);
        lv_style_set_text_color(&style_temp_setting_dark, lv_color_hex(0xFFFFFF));

        lv_style_init(&style_temp_setting_light);
        lv_style_set_text_color(&style_temp_setting_light, lv_color_hex(0x000000));

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_name_static(lv_obj_0, "temperature_setting_#");
    lv_obj_set_width(lv_obj_0, 250);
    lv_obj_set_height(lv_obj_0, 200);
    lv_obj_set_style_bg_opa(lv_obj_0, 0, 0);
    lv_obj_set_style_border_opa(lv_obj_0, 0, 0);

    lv_obj_bind_style(lv_obj_0, &style_temp_setting_dark, 0, &is_dark_mode, 1);
    lv_obj_bind_style(lv_obj_0, &style_temp_setting_light, 0, &is_dark_mode, 0);
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
    lv_label_set_text(lv_label_0, "Temperature");
    lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);
    lv_obj_set_y(lv_label_0, -35);
    lv_obj_set_x(lv_label_0, 0);
    lv_obj_set_style_text_font(lv_label_0, font_medium, 0);

    lv_obj_t * temperature_label = temperature_label_create(lv_obj_0);
    lv_obj_set_name(temperature_label, "temperature_label");
    lv_label_bind_text(temperature_label, &room1_temperature, NULL);
    lv_obj_set_align(temperature_label, LV_ALIGN_CENTER);
    lv_obj_set_y(temperature_label, -10);
    lv_obj_set_style_text_font(temperature_label, font_medium, 0);

    lv_obj_t * lv_button_0 = lv_button_create(lv_obj_0);
    lv_obj_set_width(lv_button_0, 40);
    lv_obj_set_height(lv_button_0, 40);
    lv_obj_set_style_radius(lv_button_0, 20, 0);
    lv_obj_set_align(lv_button_0, LV_ALIGN_CENTER);
    lv_obj_set_x(lv_button_0, -50);
    lv_obj_set_y(lv_button_0, 40);
    lv_subject_increment_dsc_t * subject_increment_event_0 = lv_obj_add_subject_increment_event(lv_button_0, &room1_temperature, LV_EVENT_CLICKED, -1);
    lv_obj_set_subject_increment_event_max_value(lv_button_0, subject_increment_event_0, 30);
    lv_obj_set_subject_increment_event_min_value(lv_button_0, subject_increment_event_0, 16);
    lv_obj_t * lv_image_0 = lv_image_create(lv_button_0);
    lv_image_set_src(lv_image_0, symbol_minus);
    lv_obj_set_align(lv_image_0, LV_ALIGN_CENTER);

    lv_obj_t * lv_button_1 = lv_button_create(lv_obj_0);
    lv_obj_set_width(lv_button_1, 40);
    lv_obj_set_height(lv_button_1, 40);
    lv_obj_set_style_radius(lv_button_1, 20, 0);
    lv_obj_set_align(lv_button_1, LV_ALIGN_CENTER);
    lv_obj_set_x(lv_button_1, 50);
    lv_obj_set_y(lv_button_1, 40);
    lv_subject_increment_dsc_t * subject_increment_event_1 = lv_obj_add_subject_increment_event(lv_button_1, &room1_temperature, LV_EVENT_CLICKED, 1);
    lv_obj_set_subject_increment_event_max_value(lv_button_1, subject_increment_event_1, 30);
    lv_obj_set_subject_increment_event_min_value(lv_button_1, subject_increment_event_1, 16);
    lv_obj_t * lv_image_1 = lv_image_create(lv_button_1);
    lv_image_set_src(lv_image_1, symbol_plus);
    lv_obj_set_align(lv_image_1, LV_ALIGN_CENTER);


    /* create animation timeline(s) */
    lv_anim_timeline_t ** at_array = lv_malloc(sizeof(lv_anim_timeline_t *) * _TEMPERATURE_SETTING_TIMELINE_CNT);
    at_array[TEMPERATURE_SETTING_TIMELINE_TIMELINE_MODIFIED_VALUE] = timeline_timeline_modified_value_create(lv_obj_0);
    lv_obj_set_user_data(lv_obj_0, at_array);
    lv_obj_add_event_cb(lv_obj_0, free_timeline_event_cb, LV_EVENT_DELETE, at_array);

    lv_obj_add_play_timeline_event(lv_button_0, LV_EVENT_CLICKED, temperature_label_get_timeline(temperature_label, TEMPERATURE_LABEL_TIMELINE_TIMELINE_VALUE_MODIFIED), 0, false);
    lv_obj_add_play_timeline_event(lv_button_1, LV_EVENT_CLICKED, temperature_label_get_timeline(temperature_label, TEMPERATURE_LABEL_TIMELINE_TIMELINE_VALUE_MODIFIED), 0, false);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

lv_anim_timeline_t * temperature_setting_get_timeline(lv_obj_t * obj, temperature_setting_timeline_t timeline_id)
{
    if (timeline_id >= _TEMPERATURE_SETTING_TIMELINE_CNT) {
        LV_LOG_WARN("temperature_setting has no timeline with %d ID", timeline_id);
        return NULL;
    }

    lv_anim_timeline_t ** at_array = lv_obj_get_user_data(obj);
    return at_array[timeline_id];
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/* Helper function to execute animations */
static void int_anim_exec_cb(lv_anim_t * a, int32_t v)
{
    uint32_t data = (lv_uintptr_t)lv_anim_get_user_data(a);
    lv_style_prop_t prop = data >> 24;
    lv_style_selector_t selector = data & 0x00ffffff;

    lv_style_value_t style_value;
    style_value.num = v;
    lv_obj_set_local_style_prop(a->var, prop, style_value, selector);
}

static lv_anim_timeline_t * timeline_timeline_modified_value_create(lv_obj_t * obj)
{
    lv_anim_timeline_t * at = lv_anim_timeline_create();
    lv_anim_timeline_t * at_to_merge = NULL;

    lv_anim_t a;
    uint32_t selector_and_prop;



    return at;
}

static void free_timeline_event_cb(lv_event_t * e)
{
    lv_anim_timeline_t ** at_array = lv_event_get_user_data(e);
    uint32_t i;
    for(i = 0; i < _TEMPERATURE_SETTING_TIMELINE_CNT; i++) {
        lv_anim_timeline_delete(at_array[i]);
    }
    lv_free(at_array);
}

