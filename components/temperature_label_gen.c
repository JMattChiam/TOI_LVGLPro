/**
 * @file temperature_label_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "temperature_label_gen.h"
#include "../LVGLPro_TOI.h"

/*********************
 *      DEFINES
 *********************/

#define ANIMATION_DURATION 75

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

static lv_anim_timeline_t * timeline_timeline_value_modified_create(lv_obj_t * obj);
static void free_timeline_event_cb(lv_event_t * e);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * temperature_label_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    lv_obj_t * lv_label_0 = lv_label_create(parent);
    lv_obj_set_name_static(lv_label_0, "temperature_label_#");

    /* create animation timeline(s) */
    lv_anim_timeline_t ** at_array = lv_malloc(sizeof(lv_anim_timeline_t *) * _TEMPERATURE_LABEL_TIMELINE_CNT);
    at_array[TEMPERATURE_LABEL_TIMELINE_TIMELINE_VALUE_MODIFIED] = timeline_timeline_value_modified_create(lv_label_0);
    lv_obj_set_user_data(lv_label_0, at_array);
    lv_obj_add_event_cb(lv_label_0, free_timeline_event_cb, LV_EVENT_DELETE, at_array);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_label_0;
}

lv_anim_timeline_t * temperature_label_get_timeline(lv_obj_t * obj, temperature_label_timeline_t timeline_id)
{
    if (timeline_id >= _TEMPERATURE_LABEL_TIMELINE_CNT) {
        LV_LOG_WARN("temperature_label has no timeline with %d ID", timeline_id);
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

static lv_anim_timeline_t * timeline_timeline_value_modified_create(lv_obj_t * obj)
{
    lv_anim_timeline_t * at = lv_anim_timeline_create();
    lv_anim_timeline_t * at_to_merge = NULL;

    lv_anim_t a;
    uint32_t selector_and_prop;

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, obj);
    lv_anim_set_values(&a, 64, 256);
    lv_anim_set_duration(&a, ANIMATION_DURATION);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, ANIMATION_DURATION, &a);

    return at;
}

static void free_timeline_event_cb(lv_event_t * e)
{
    lv_anim_timeline_t ** at_array = lv_event_get_user_data(e);
    uint32_t i;
    for(i = 0; i < _TEMPERATURE_LABEL_TIMELINE_CNT; i++) {
        lv_anim_timeline_delete(at_array[i]);
    }
    lv_free(at_array);
}

