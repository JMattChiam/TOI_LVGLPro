/**
 * @file LVGLPro_TOI_gen.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "LVGLPro_TOI_gen.h"

#if LV_USE_XML
#endif /* LV_USE_XML */

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/*----------------
 * Translations
 *----------------*/

/**********************
 *  GLOBAL VARIABLES
 **********************/

/*--------------------
 *  Permanent screens
 *-------------------*/

lv_obj_t * screen_1 = NULL;

/*----------------
 * Fonts
 *----------------*/

lv_font_t * font_large;
extern lv_font_t font_large_data;
lv_font_t * font_medium;
extern lv_font_t font_medium_data;
lv_font_t * font_small;
extern lv_font_t font_small_data;

/*----------------
 * Images
 *----------------*/

const void * symbol_plus;
extern const void * symbol_plus_data;
const void * symbol_minus;
extern const void * symbol_minus_data;

/*----------------
 * Global styles
 *----------------*/

lv_style_t style_light_mode;
lv_style_t style_dark_mode;

/*----------------
 * Subjects
 *----------------*/

lv_subject_t room1_temperature;
lv_subject_t is_dark_mode;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void LVGLPro_TOI_init_gen(const char * asset_path)
{
    char buf[256];


    /*----------------
     * Fonts
     *----------------*/

    /* get font 'font_large' from a C array */
    font_large = &font_large_data;
    /* get font 'font_medium' from a C array */
    font_medium = &font_medium_data;
    /* get font 'font_small' from a C array */
    font_small = &font_small_data;


    /*----------------
     * Images
     *----------------*/
    symbol_plus = &symbol_plus_data;
    symbol_minus = &symbol_minus_data;

    /*----------------
     * Global styles
     *----------------*/

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_light_mode);
        lv_style_set_bg_color(&style_light_mode, lv_color_hex(0xe4e4e4));
        lv_style_set_text_color(&style_light_mode, lv_color_hex(0x000000));

        lv_style_init(&style_dark_mode);
        lv_style_set_bg_color(&style_dark_mode, lv_color_hex(0x3f3c3c));
        lv_style_set_text_color(&style_dark_mode, lv_color_hex(0xFFFFFF));

        style_inited = true;
    }

    /*----------------
     * Subjects
     *----------------*/
    lv_subject_init_int(&room1_temperature, 20);
    lv_subject_init_int(&is_dark_mode, 0);

    /*----------------
     * Translations
     *----------------*/

#if LV_USE_XML
    /* Register widgets */

    /* Register fonts */
    lv_xml_register_font(NULL, "font_large", font_large);
    lv_xml_register_font(NULL, "font_medium", font_medium);
    lv_xml_register_font(NULL, "font_small", font_small);

    /* Register subjects */
    lv_xml_register_subject(NULL, "room1_temperature", &room1_temperature);
    lv_xml_register_subject(NULL, "is_dark_mode", &is_dark_mode);

    /* Register callbacks */
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if LV_USE_XML && !defined(LV_EDITOR_PREVIEW)
    /* Register images */
    lv_xml_register_image(NULL, "symbol_plus", symbol_plus);
    lv_xml_register_image(NULL, "symbol_minus", symbol_minus);
#endif

#if LV_USE_XML == 0
    /*--------------------
     *  Permanent screens
     *-------------------*/
    /* If XML is enabled it's assumed that the permanent screens are created
     * manaully from XML using lv_xml_create() */
    /* To allow screens to reference each other, create them all before calling the sceen create functions */
    screen_1 = lv_obj_create(NULL);

    screen_1_create();
#endif
}

/* Callbacks */

/**********************
 *   STATIC FUNCTIONS
 **********************/