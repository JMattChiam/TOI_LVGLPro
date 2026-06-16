/**
 * @file temperature_setting_gen.h
 */

#ifndef TEMPERATURE_SETTING_H
#define TEMPERATURE_SETTING_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
    #include "lvgl_private.h"
#else
    #include "lvgl/lvgl.h"
    #include "lvgl/lvgl_private.h"
#endif

#ifdef LV_USE_XML
    #include "lv_xml/lv_xml.h"
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

typedef enum {
    TEMPERATURE_SETTING_TIMELINE_TIMELINE_MODIFIED_VALUE = 0,
    _TEMPERATURE_SETTING_TIMELINE_CNT = 1
}temperature_setting_timeline_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

lv_obj_t * temperature_setting_create(lv_obj_t * parent);

/**
 * Get a timeline of a temperature_setting
 * @param obj          pointer to a temperature_setting component
 * @param timeline_id  ID of the the timeline
 * @return             pointer to the timeline or NULL if not found
 */
lv_anim_timeline_t * temperature_setting_get_timeline(lv_obj_t * obj, temperature_setting_timeline_t timeline_id);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*TEMPERATURE_SETTING_H*/