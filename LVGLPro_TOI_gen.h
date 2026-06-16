/**
 * @file LVGLPro_TOI_gen.h
 */

#ifndef LVGLPRO_TOI_GEN_H
#define LVGLPRO_TOI_GEN_H

#ifndef UI_SUBJECT_STRING_LENGTH
#define UI_SUBJECT_STRING_LENGTH 256
#endif

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

/**********************
 * GLOBAL VARIABLES
 **********************/

/*-------------------
 * Permanent screens
 *------------------*/

extern lv_obj_t * screen_1;

/*----------------
 * Global styles
 *----------------*/

extern lv_style_t style_light_mode;
extern lv_style_t style_dark_mode;

/*----------------
 * Fonts
 *----------------*/

extern lv_font_t * font_large;

extern lv_font_t * font_medium;

extern lv_font_t * font_small;

/*----------------
 * Images
 *----------------*/

extern const void * symbol_plus;
extern const void * symbol_minus;

/*----------------
 * Subjects
 *----------------*/

extern lv_subject_t room1_temperature;
extern lv_subject_t is_dark_mode;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/*----------------
 * Event Callbacks
 *----------------*/

/**
 * Initialize the component library
 */

void LVGLPro_TOI_init_gen(const char * asset_path);

/**********************
 *      MACROS
 **********************/

/**********************
 *   POST INCLUDES
 **********************/

/*Include all the widgets, components and screens of this library*/
#include "components/temperature_label_gen.h"
#include "components/temperature_setting_gen.h"
#include "screens/screen_1_gen.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LVGLPRO_TOI_GEN_H*/