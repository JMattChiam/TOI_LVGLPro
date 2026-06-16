/**
 * @file temperature_label_gen.h
 */

#ifndef TEMPERATURE_LABEL_H
#define TEMPERATURE_LABEL_H

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
    TEMPERATURE_LABEL_TIMELINE_TIMELINE_VALUE_MODIFIED = 0,
    _TEMPERATURE_LABEL_TIMELINE_CNT = 1
}temperature_label_timeline_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

lv_obj_t * temperature_label_create(lv_obj_t * parent);

/**
 * Get a timeline of a temperature_label
 * @param obj          pointer to a temperature_label component
 * @param timeline_id  ID of the the timeline
 * @return             pointer to the timeline or NULL if not found
 */
lv_anim_timeline_t * temperature_label_get_timeline(lv_obj_t * obj, temperature_label_timeline_t timeline_id);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*TEMPERATURE_LABEL_H*/