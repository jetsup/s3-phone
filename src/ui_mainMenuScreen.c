// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 9.1.0
// Project name: s3-phone

#include "ui.h"

void ui_mainMenuScreen_screen_init(void)
{
    ui_mainMenuScreen = lv_obj_create(NULL);
    lv_obj_remove_flag(ui_mainMenuScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_set_style_border_color(ui_mainMenuScreen, lv_color_hex(0x000000), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_mainMenuScreen, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    ui_mainMenuPanel = lv_obj_create(ui_mainMenuScreen);
    lv_obj_set_width(ui_mainMenuPanel, 239);
    lv_obj_set_height(ui_mainMenuPanel, 319);
    lv_obj_set_align(ui_mainMenuPanel, LV_ALIGN_CENTER);
    lv_obj_remove_flag(ui_mainMenuPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_mainMenuPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_mainMenuPanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_mainMenuPanel, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui_mainMenuPanel, &ui_img_nature_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_menuMainContainer = lv_obj_create(ui_mainMenuPanel);
    lv_obj_remove_style_all(ui_menuMainContainer);
    lv_obj_set_width(ui_menuMainContainer, 239);
    lv_obj_set_height(ui_menuMainContainer, 319);
    lv_obj_set_align(ui_menuMainContainer, LV_ALIGN_CENTER);
    lv_obj_remove_flag(ui_menuMainContainer, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_menuMainContainer, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_menuMainContainer, 12, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_border_color(ui_menuMainContainer, lv_color_hex(0x000000), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_menuMainContainer, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    ui_imbContacts = lv_imagebutton_create(ui_menuMainContainer);
    lv_imagebutton_set_src(ui_imbContacts, LV_IMAGEBUTTON_STATE_RELEASED, NULL, &ui_img_phone_png, NULL);
    lv_obj_set_width(ui_imbContacts, 60);
    lv_obj_set_height(ui_imbContacts, 60);
    lv_obj_set_x(ui_imbContacts, -75);
    lv_obj_set_y(ui_imbContacts, -115);
    lv_obj_set_align(ui_imbContacts, LV_ALIGN_CENTER);

    ui_imbMessages = lv_imagebutton_create(ui_menuMainContainer);
    lv_imagebutton_set_src(ui_imbMessages, LV_IMAGEBUTTON_STATE_RELEASED, NULL, &ui_img_email_png, NULL);
    lv_obj_set_width(ui_imbMessages, 60);
    lv_obj_set_height(ui_imbMessages, 60);
    lv_obj_set_x(ui_imbMessages, 4);
    lv_obj_set_y(ui_imbMessages, -115);
    lv_obj_set_align(ui_imbMessages, LV_ALIGN_CENTER);

    ui_imbCallHistory = lv_imagebutton_create(ui_menuMainContainer);
    lv_imagebutton_set_src(ui_imbCallHistory, LV_IMAGEBUTTON_STATE_RELEASED, NULL, &ui_img_617275014, NULL);
    lv_obj_set_width(ui_imbCallHistory, 60);
    lv_obj_set_height(ui_imbCallHistory, 60);
    lv_obj_set_x(ui_imbCallHistory, 80);
    lv_obj_set_y(ui_imbCallHistory, -115);
    lv_obj_set_align(ui_imbCallHistory, LV_ALIGN_CENTER);

    ui_imbSettings = lv_imagebutton_create(ui_menuMainContainer);
    lv_imagebutton_set_src(ui_imbSettings, LV_IMAGEBUTTON_STATE_RELEASED, NULL, &ui_img_settings_png, NULL);
    lv_obj_set_width(ui_imbSettings, 60);
    lv_obj_set_height(ui_imbSettings, 60);
    lv_obj_set_x(ui_imbSettings, -75);
    lv_obj_set_y(ui_imbSettings, -45);
    lv_obj_set_align(ui_imbSettings, LV_ALIGN_CENTER);

    ui_imbMultimedia = lv_imagebutton_create(ui_menuMainContainer);
    lv_imagebutton_set_src(ui_imbMultimedia, LV_IMAGEBUTTON_STATE_RELEASED, NULL, &ui_img_multimedia_png, NULL);
    lv_obj_set_width(ui_imbMultimedia, 60);
    lv_obj_set_height(ui_imbMultimedia, 60);
    lv_obj_set_x(ui_imbMultimedia, 4);
    lv_obj_set_y(ui_imbMultimedia, -45);
    lv_obj_set_align(ui_imbMultimedia, LV_ALIGN_CENTER);

    ui_imbExtra = lv_imagebutton_create(ui_menuMainContainer);
    lv_imagebutton_set_src(ui_imbExtra, LV_IMAGEBUTTON_STATE_RELEASED, NULL, &ui_img_target_png, NULL);
    lv_obj_set_width(ui_imbExtra, 60);
    lv_obj_set_height(ui_imbExtra, 60);
    lv_obj_set_x(ui_imbExtra, 80);
    lv_obj_set_y(ui_imbExtra, -45);
    lv_obj_set_align(ui_imbExtra, LV_ALIGN_CENTER);

    ui_imbGames = lv_imagebutton_create(ui_menuMainContainer);
    lv_imagebutton_set_src(ui_imbGames, LV_IMAGEBUTTON_STATE_RELEASED, NULL, &ui_img_335818912, NULL);
    lv_obj_set_width(ui_imbGames, 60);
    lv_obj_set_height(ui_imbGames, 60);
    lv_obj_set_x(ui_imbGames, -75);
    lv_obj_set_y(ui_imbGames, 25);
    lv_obj_set_align(ui_imbGames, LV_ALIGN_CENTER);

    ui_imbMyZone = lv_imagebutton_create(ui_menuMainContainer);
    lv_imagebutton_set_src(ui_imbMyZone, LV_IMAGEBUTTON_STATE_RELEASED, NULL, &ui_img_target_png, NULL);
    lv_obj_set_width(ui_imbMyZone, 60);
    lv_obj_set_height(ui_imbMyZone, 60);
    lv_obj_set_x(ui_imbMyZone, 4);
    lv_obj_set_y(ui_imbMyZone, 25);
    lv_obj_set_align(ui_imbMyZone, LV_ALIGN_CENTER);

    ui_imbAbout = lv_imagebutton_create(ui_menuMainContainer);
    lv_imagebutton_set_src(ui_imbAbout, LV_IMAGEBUTTON_STATE_RELEASED, NULL, &ui_img_info_png, NULL);
    lv_obj_set_width(ui_imbAbout, 60);
    lv_obj_set_height(ui_imbAbout, 60);
    lv_obj_set_x(ui_imbAbout, 80);
    lv_obj_set_y(ui_imbAbout, 25);
    lv_obj_set_align(ui_imbAbout, LV_ALIGN_CENTER);

    ui_bottomBar = lv_obj_create(ui_mainMenuPanel);
    lv_obj_remove_style_all(ui_bottomBar);
    lv_obj_set_width(ui_bottomBar, 239);
    lv_obj_set_height(ui_bottomBar, 20);
    lv_obj_set_x(ui_bottomBar, 0);
    lv_obj_set_y(ui_bottomBar, 145);
    lv_obj_set_align(ui_bottomBar, LV_ALIGN_CENTER);
    lv_obj_remove_flag(ui_bottomBar, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_lblMainMenuBack = lv_label_create(ui_bottomBar);
    lv_obj_set_width(ui_lblMainMenuBack, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_lblMainMenuBack, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_lblMainMenuBack, 95);
    lv_obj_set_y(ui_lblMainMenuBack, 0);
    lv_obj_set_align(ui_lblMainMenuBack, LV_ALIGN_CENTER);
    lv_label_set_text(ui_lblMainMenuBack, "Back");
    lv_obj_add_flag(ui_lblMainMenuBack, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_set_style_text_color(ui_lblMainMenuBack, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_lblMainMenuBack, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_lblMainMenuBack, ui_event_lblMainMenuBack, LV_EVENT_ALL, NULL);

}