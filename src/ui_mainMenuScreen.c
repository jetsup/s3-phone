#include "ui.h"
#include "ui_utils.h"

void ui_mainMenuScreen_screen_init(void) {
  ui_mainMenuScreen = lv_obj_create(NULL);
  lv_obj_remove_flag(ui_mainMenuScreen, LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_panelMainMenu = lv_obj_create(ui_mainMenuScreen);
  lv_obj_set_width(ui_panelMainMenu, 240);
  lv_obj_set_height(ui_panelMainMenu, 320);
  lv_obj_set_align(ui_panelMainMenu, LV_ALIGN_CENTER);
  lv_obj_remove_flag(ui_panelMainMenu, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_radius(ui_panelMainMenu, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui_panelMainMenu, lv_color_hex(0xFFFFFF),
                            LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_panelMainMenu, 100,
                          LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_image_src(ui_panelMainMenu, screenWallpaperImg,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_image_opa(ui_panelMainMenu, 100,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_color(ui_panelMainMenu, lv_color_hex(0x000000),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_opa(ui_panelMainMenu, 0,
                              LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_menuMainContainer = lv_obj_create(ui_panelMainMenu);
  lv_obj_remove_style_all(ui_menuMainContainer);
  lv_obj_set_width(ui_menuMainContainer, 240);
  lv_obj_set_height(ui_menuMainContainer, 320);
  lv_obj_set_x(ui_menuMainContainer, 1);
  lv_obj_set_y(ui_menuMainContainer, 0);
  lv_obj_set_align(ui_menuMainContainer, LV_ALIGN_CENTER);
  lv_obj_remove_flag(ui_menuMainContainer, LV_OBJ_FLAG_CLICKABLE);  /// Flags
  lv_obj_set_style_bg_color(ui_menuMainContainer, lv_color_hex(0xFF0000),
                            LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_menuMainContainer, 12,
                          LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_set_style_border_color(ui_menuMainContainer, lv_color_hex(0x000000),
                                LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
  lv_obj_set_style_border_opa(ui_menuMainContainer, 255,
                              LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

  ui_menuPhoneContainer = lv_obj_create(ui_menuMainContainer);
  lv_obj_remove_style_all(ui_menuPhoneContainer);
  lv_obj_set_width(ui_menuPhoneContainer, 50);
  lv_obj_set_height(ui_menuPhoneContainer, 50);
  lv_obj_set_x(ui_menuPhoneContainer, 5);
  lv_obj_set_y(ui_menuPhoneContainer, 10);
  lv_obj_remove_flag(ui_menuPhoneContainer,
                     LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_imbPhone = lv_imagebutton_create(ui_menuPhoneContainer);
  lv_imagebutton_set_src(ui_imbPhone, LV_IMAGEBUTTON_STATE_RELEASED, NULL,
                         &ui_img_openphone40_png, NULL);
  lv_obj_set_width(ui_imbPhone, 40);
  lv_obj_set_height(ui_imbPhone, 40);
  lv_obj_set_align(ui_imbPhone, LV_ALIGN_TOP_MID);

  ui_lblMenuPhone = lv_label_create(ui_menuPhoneContainer);
  lv_obj_set_width(ui_lblMenuPhone, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_lblMenuPhone, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_lblMenuPhone, LV_ALIGN_BOTTOM_MID);
  lv_label_set_text(ui_lblMenuPhone, "Phone");
  lv_obj_set_style_text_font(ui_lblMenuPhone, &lv_font_montserrat_10,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_menuMessagesContainer = lv_obj_create(ui_menuMainContainer);
  lv_obj_remove_style_all(ui_menuMessagesContainer);
  lv_obj_set_width(ui_menuMessagesContainer, 50);
  lv_obj_set_height(ui_menuMessagesContainer, 50);
  lv_obj_set_x(ui_menuMessagesContainer, 60);
  lv_obj_set_y(ui_menuMessagesContainer, 10);
  lv_obj_remove_flag(ui_menuMessagesContainer,
                     LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_imbMessages = lv_imagebutton_create(ui_menuMessagesContainer);
  lv_imagebutton_set_src(ui_imbMessages, LV_IMAGEBUTTON_STATE_RELEASED, NULL,
                         &ui_img_messages40_png, NULL);
  lv_obj_set_width(ui_imbMessages, 40);
  lv_obj_set_height(ui_imbMessages, 40);
  lv_obj_set_align(ui_imbMessages, LV_ALIGN_TOP_MID);

  ui_lblMenuMessages = lv_label_create(ui_menuMessagesContainer);
  lv_obj_set_width(ui_lblMenuMessages, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_lblMenuMessages, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_lblMenuMessages, LV_ALIGN_BOTTOM_MID);
  lv_label_set_text(ui_lblMenuMessages, "Messages");
  lv_obj_set_style_text_font(ui_lblMenuMessages, &lv_font_montserrat_10,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_menuMultimediaContainer = lv_obj_create(ui_menuMainContainer);
  lv_obj_remove_style_all(ui_menuMultimediaContainer);
  lv_obj_set_width(ui_menuMultimediaContainer, 50);
  lv_obj_set_height(ui_menuMultimediaContainer, 50);
  lv_obj_set_x(ui_menuMultimediaContainer, 120);
  lv_obj_set_y(ui_menuMultimediaContainer, 10);
  lv_obj_remove_flag(ui_menuMultimediaContainer,
                     LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_imbMultimedia = lv_imagebutton_create(ui_menuMultimediaContainer);
  lv_imagebutton_set_src(ui_imbMultimedia, LV_IMAGEBUTTON_STATE_RELEASED, NULL,
                         &ui_img_multimedia40_png, NULL);
  lv_obj_set_width(ui_imbMultimedia, 40);
  lv_obj_set_height(ui_imbMultimedia, 40);
  lv_obj_set_align(ui_imbMultimedia, LV_ALIGN_TOP_MID);

  ui_lblMenuMultimedia = lv_label_create(ui_menuMultimediaContainer);
  lv_obj_set_width(ui_lblMenuMultimedia, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_lblMenuMultimedia, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_lblMenuMultimedia, LV_ALIGN_BOTTOM_MID);
  lv_label_set_text(ui_lblMenuMultimedia, "Media");
  lv_obj_set_style_text_font(ui_lblMenuMultimedia, &lv_font_montserrat_10,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_menuExtraContainer = lv_obj_create(ui_menuMainContainer);
  lv_obj_remove_style_all(ui_menuExtraContainer);
  lv_obj_set_width(ui_menuExtraContainer, 50);
  lv_obj_set_height(ui_menuExtraContainer, 50);
  lv_obj_set_x(ui_menuExtraContainer, 180);
  lv_obj_set_y(ui_menuExtraContainer, 10);
  lv_obj_remove_flag(ui_menuExtraContainer,
                     LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_imbExtra = lv_imagebutton_create(ui_menuExtraContainer);
  lv_imagebutton_set_src(ui_imbExtra, LV_IMAGEBUTTON_STATE_RELEASED, NULL,
                         &ui_img_extra40_png, NULL);
  lv_obj_set_width(ui_imbExtra, 40);
  lv_obj_set_height(ui_imbExtra, 40);
  lv_obj_set_align(ui_imbExtra, LV_ALIGN_TOP_MID);

  ui_lblMenuExtra = lv_label_create(ui_menuExtraContainer);
  lv_obj_set_width(ui_lblMenuExtra, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_lblMenuExtra, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_lblMenuExtra, LV_ALIGN_BOTTOM_MID);
  lv_label_set_text(ui_lblMenuExtra, "Extra");
  lv_obj_set_style_text_font(ui_lblMenuExtra, &lv_font_montserrat_10,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_menuGamesContainer = lv_obj_create(ui_menuMainContainer);
  lv_obj_remove_style_all(ui_menuGamesContainer);
  lv_obj_set_width(ui_menuGamesContainer, 50);
  lv_obj_set_height(ui_menuGamesContainer, 50);
  lv_obj_set_x(ui_menuGamesContainer, 5);
  lv_obj_set_y(ui_menuGamesContainer, 65);
  lv_obj_remove_flag(ui_menuGamesContainer,
                     LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_imbGames = lv_imagebutton_create(ui_menuGamesContainer);
  lv_imagebutton_set_src(ui_imbGames, LV_IMAGEBUTTON_STATE_RELEASED, NULL,
                         &ui_img_games40_png, NULL);
  lv_obj_set_width(ui_imbGames, 40);
  lv_obj_set_height(ui_imbGames, 40);
  lv_obj_set_align(ui_imbGames, LV_ALIGN_TOP_MID);

  ui_lblMenuGames = lv_label_create(ui_menuGamesContainer);
  lv_obj_set_width(ui_lblMenuGames, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_lblMenuGames, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_lblMenuGames, LV_ALIGN_BOTTOM_MID);
  lv_label_set_text(ui_lblMenuGames, "Games");
  lv_obj_set_style_text_font(ui_lblMenuGames, &lv_font_montserrat_10,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_menuMyZoneContainer = lv_obj_create(ui_menuMainContainer);
  lv_obj_remove_style_all(ui_menuMyZoneContainer);
  lv_obj_set_width(ui_menuMyZoneContainer, 50);
  lv_obj_set_height(ui_menuMyZoneContainer, 50);
  lv_obj_set_x(ui_menuMyZoneContainer, 60);
  lv_obj_set_y(ui_menuMyZoneContainer, 65);
  lv_obj_remove_flag(ui_menuMyZoneContainer,
                     LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_imbMyZone = lv_imagebutton_create(ui_menuMyZoneContainer);
  lv_imagebutton_set_src(ui_imbMyZone, LV_IMAGEBUTTON_STATE_RELEASED, NULL,
                         &ui_img_dropzone40_png, NULL);
  lv_obj_set_width(ui_imbMyZone, 40);
  lv_obj_set_height(ui_imbMyZone, 40);
  lv_obj_set_align(ui_imbMyZone, LV_ALIGN_TOP_MID);

  ui_lblMenuMyZone = lv_label_create(ui_menuMyZoneContainer);
  lv_obj_set_width(ui_lblMenuMyZone, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_lblMenuMyZone, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_lblMenuMyZone, LV_ALIGN_BOTTOM_MID);
  lv_label_set_text(ui_lblMenuMyZone, "My Zone");
  lv_obj_set_style_text_font(ui_lblMenuMyZone, &lv_font_montserrat_10,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_menuAboutContainer = lv_obj_create(ui_menuMainContainer);
  lv_obj_remove_style_all(ui_menuAboutContainer);
  lv_obj_set_width(ui_menuAboutContainer, 50);
  lv_obj_set_height(ui_menuAboutContainer, 50);
  lv_obj_set_x(ui_menuAboutContainer, 120);
  lv_obj_set_y(ui_menuAboutContainer, 65);
  lv_obj_remove_flag(ui_menuAboutContainer,
                     LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_imbAbout = lv_imagebutton_create(ui_menuAboutContainer);
  lv_imagebutton_set_src(ui_imbAbout, LV_IMAGEBUTTON_STATE_RELEASED, NULL,
                         &ui_img_about40_png, NULL);
  lv_obj_set_width(ui_imbAbout, 40);
  lv_obj_set_height(ui_imbAbout, 40);
  lv_obj_set_align(ui_imbAbout, LV_ALIGN_TOP_MID);

  ui_lblMenuAbout = lv_label_create(ui_menuAboutContainer);
  lv_obj_set_width(ui_lblMenuAbout, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_lblMenuAbout, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_lblMenuAbout, LV_ALIGN_BOTTOM_MID);
  lv_label_set_text(ui_lblMenuAbout, "About");
  lv_obj_set_style_text_font(ui_lblMenuAbout, &lv_font_montserrat_10,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_menuToolsContainer = lv_obj_create(ui_menuMainContainer);
  lv_obj_remove_style_all(ui_menuToolsContainer);
  lv_obj_set_width(ui_menuToolsContainer, 50);
  lv_obj_set_height(ui_menuToolsContainer, 50);
  lv_obj_set_x(ui_menuToolsContainer, 180);
  lv_obj_set_y(ui_menuToolsContainer, 65);
  lv_obj_remove_flag(ui_menuToolsContainer,
                     LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_imbTools = lv_imagebutton_create(ui_menuToolsContainer);
  lv_imagebutton_set_src(ui_imbTools, LV_IMAGEBUTTON_STATE_RELEASED, NULL,
                         &ui_img_tools40_png, NULL);
  lv_obj_set_width(ui_imbTools, 40);
  lv_obj_set_height(ui_imbTools, 40);
  lv_obj_set_align(ui_imbTools, LV_ALIGN_TOP_MID);

  ui_lblMenuTools = lv_label_create(ui_menuToolsContainer);
  lv_obj_set_width(ui_lblMenuTools, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_lblMenuTools, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_lblMenuTools, LV_ALIGN_BOTTOM_MID);
  lv_label_set_text(ui_lblMenuTools, "Tools");
  lv_obj_set_style_text_font(ui_lblMenuTools, &lv_font_montserrat_10,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_menuSettingsContainer = lv_obj_create(ui_menuMainContainer);
  lv_obj_remove_style_all(ui_menuSettingsContainer);
  lv_obj_set_width(ui_menuSettingsContainer, 50);
  lv_obj_set_height(ui_menuSettingsContainer, 50);
  lv_obj_set_x(ui_menuSettingsContainer, 5);
  lv_obj_set_y(ui_menuSettingsContainer, 120);
  lv_obj_remove_flag(ui_menuSettingsContainer,
                     LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_imbSettings = lv_imagebutton_create(ui_menuSettingsContainer);
  lv_imagebutton_set_src(ui_imbSettings, LV_IMAGEBUTTON_STATE_RELEASED, NULL,
                         &ui_img_settings40_png, NULL);
  lv_obj_set_width(ui_imbSettings, 40);
  lv_obj_set_height(ui_imbSettings, 40);
  lv_obj_set_align(ui_imbSettings, LV_ALIGN_TOP_MID);

  ui_lblMenuSettings = lv_label_create(ui_menuSettingsContainer);
  lv_obj_set_width(ui_lblMenuSettings, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_lblMenuSettings, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_lblMenuSettings, LV_ALIGN_BOTTOM_MID);
  lv_label_set_text(ui_lblMenuSettings, "Settings");
  lv_obj_set_style_text_font(ui_lblMenuSettings, &lv_font_montserrat_10,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_menuClockContainer = lv_obj_create(ui_menuMainContainer);
  lv_obj_remove_style_all(ui_menuClockContainer);
  lv_obj_set_width(ui_menuClockContainer, 50);
  lv_obj_set_height(ui_menuClockContainer, 50);
  lv_obj_set_x(ui_menuClockContainer, 60);
  lv_obj_set_y(ui_menuClockContainer, 120);
  lv_obj_remove_flag(ui_menuClockContainer,
                     LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_imbClock = lv_imagebutton_create(ui_menuClockContainer);
  lv_imagebutton_set_src(ui_imbClock, LV_IMAGEBUTTON_STATE_RELEASED, NULL,
                         &ui_img_clock40_png, NULL);
  lv_obj_set_width(ui_imbClock, 40);
  lv_obj_set_height(ui_imbClock, 40);
  lv_obj_set_align(ui_imbClock, LV_ALIGN_TOP_MID);

  ui_lblMenuSettings1 = lv_label_create(ui_menuClockContainer);
  lv_obj_set_width(ui_lblMenuSettings1, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_lblMenuSettings1, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_lblMenuSettings1, LV_ALIGN_BOTTOM_MID);
  lv_label_set_text(ui_lblMenuSettings1, "Time");
  lv_obj_set_style_text_font(ui_lblMenuSettings1, &lv_font_montserrat_10,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_menuCalculatorContainer = lv_obj_create(ui_menuMainContainer);
  lv_obj_remove_style_all(ui_menuCalculatorContainer);
  lv_obj_set_width(ui_menuCalculatorContainer, 50);
  lv_obj_set_height(ui_menuCalculatorContainer, 50);
  lv_obj_set_x(ui_menuCalculatorContainer, 120);
  lv_obj_set_y(ui_menuCalculatorContainer, 120);
  lv_obj_remove_flag(ui_menuCalculatorContainer,
                     LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_imbCalculator = lv_imagebutton_create(ui_menuCalculatorContainer);
  lv_imagebutton_set_src(ui_imbCalculator, LV_IMAGEBUTTON_STATE_RELEASED, NULL,
                         &ui_img_calculator40_png, NULL);
  lv_obj_set_width(ui_imbCalculator, 40);
  lv_obj_set_height(ui_imbCalculator, 40);
  lv_obj_set_align(ui_imbCalculator, LV_ALIGN_TOP_MID);

  ui_lblMenuCalculator = lv_label_create(ui_menuCalculatorContainer);
  lv_obj_set_width(ui_lblMenuCalculator, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_lblMenuCalculator, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_lblMenuCalculator, LV_ALIGN_BOTTOM_MID);
  lv_label_set_text(ui_lblMenuCalculator, "Calculator");
  lv_obj_set_style_text_font(ui_lblMenuCalculator, &lv_font_montserrat_10,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_menuCalendarContainer = lv_obj_create(ui_menuMainContainer);
  lv_obj_remove_style_all(ui_menuCalendarContainer);
  lv_obj_set_width(ui_menuCalendarContainer, 50);
  lv_obj_set_height(ui_menuCalendarContainer, 50);
  lv_obj_set_x(ui_menuCalendarContainer, 180);
  lv_obj_set_y(ui_menuCalendarContainer, 120);
  lv_obj_remove_flag(ui_menuCalendarContainer,
                     LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_imbCalendar = lv_imagebutton_create(ui_menuCalendarContainer);
  lv_imagebutton_set_src(ui_imbCalendar, LV_IMAGEBUTTON_STATE_RELEASED, NULL,
                         &ui_img_calendar40_png, NULL);
  lv_obj_set_width(ui_imbCalendar, 40);
  lv_obj_set_height(ui_imbCalendar, 40);
  lv_obj_set_align(ui_imbCalendar, LV_ALIGN_TOP_MID);

  ui_lblMenuCalendar = lv_label_create(ui_menuCalendarContainer);
  lv_obj_set_width(ui_lblMenuCalendar, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_lblMenuCalendar, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_lblMenuCalendar, LV_ALIGN_BOTTOM_MID);
  lv_label_set_text(ui_lblMenuCalendar, "Calendar");
  lv_obj_set_style_text_font(ui_lblMenuCalendar, &lv_font_montserrat_10,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_menuFilesContainer = lv_obj_create(ui_menuMainContainer);
  lv_obj_remove_style_all(ui_menuFilesContainer);
  lv_obj_set_width(ui_menuFilesContainer, 50);
  lv_obj_set_height(ui_menuFilesContainer, 50);
  lv_obj_set_x(ui_menuFilesContainer, 5);
  lv_obj_set_y(ui_menuFilesContainer, 175);
  lv_obj_remove_flag(ui_menuFilesContainer,
                     LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_imbFiles = lv_imagebutton_create(ui_menuFilesContainer);
  lv_imagebutton_set_src(ui_imbFiles, LV_IMAGEBUTTON_STATE_RELEASED, NULL,
                         &ui_img_folder40_png, NULL);
  lv_obj_set_width(ui_imbFiles, 40);
  lv_obj_set_height(ui_imbFiles, 40);
  lv_obj_set_align(ui_imbFiles, LV_ALIGN_TOP_MID);

  ui_lblMenuFiles = lv_label_create(ui_menuFilesContainer);
  lv_obj_set_width(ui_lblMenuFiles, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_lblMenuFiles, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_lblMenuFiles, LV_ALIGN_BOTTOM_MID);
  lv_label_set_text(ui_lblMenuFiles, "Files");
  lv_obj_set_style_text_font(ui_lblMenuFiles, &lv_font_montserrat_10,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_menuTodoContainer = lv_obj_create(ui_menuMainContainer);
  lv_obj_remove_style_all(ui_menuTodoContainer);
  lv_obj_set_width(ui_menuTodoContainer, 50);
  lv_obj_set_height(ui_menuTodoContainer, 50);
  lv_obj_set_x(ui_menuTodoContainer, 60);
  lv_obj_set_y(ui_menuTodoContainer, 175);
  lv_obj_remove_flag(ui_menuTodoContainer,
                     LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_imbTodo = lv_imagebutton_create(ui_menuTodoContainer);
  lv_imagebutton_set_src(ui_imbTodo, LV_IMAGEBUTTON_STATE_RELEASED, NULL,
                         &ui_img_todo40_png, NULL);
  lv_obj_set_width(ui_imbTodo, 40);
  lv_obj_set_height(ui_imbTodo, 40);
  lv_obj_set_align(ui_imbTodo, LV_ALIGN_TOP_MID);

  ui_lblMenuTodo = lv_label_create(ui_menuTodoContainer);
  lv_obj_set_width(ui_lblMenuTodo, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_lblMenuTodo, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_lblMenuTodo, LV_ALIGN_BOTTOM_MID);
  lv_label_set_text(ui_lblMenuTodo, "TODO");
  lv_obj_set_style_text_font(ui_lblMenuTodo, &lv_font_montserrat_10,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_menuSTKContainer = lv_obj_create(ui_menuMainContainer);
  lv_obj_remove_style_all(ui_menuSTKContainer);
  lv_obj_set_width(ui_menuSTKContainer, 50);
  lv_obj_set_height(ui_menuSTKContainer, 50);
  lv_obj_set_x(ui_menuSTKContainer, 120);
  lv_obj_set_y(ui_menuSTKContainer, 175);
  lv_obj_remove_flag(ui_menuSTKContainer,
                     LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_imbSTK = lv_imagebutton_create(ui_menuSTKContainer);
  lv_imagebutton_set_src(ui_imbSTK, LV_IMAGEBUTTON_STATE_RELEASED, NULL,
                         &ui_img_stk40_png, NULL);
  lv_obj_set_width(ui_imbSTK, 40);
  lv_obj_set_height(ui_imbSTK, 40);
  lv_obj_set_align(ui_imbSTK, LV_ALIGN_TOP_MID);

  ui_lblMenuSTK = lv_label_create(ui_menuSTKContainer);
  lv_obj_set_width(ui_lblMenuSTK, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_lblMenuSTK, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_lblMenuSTK, LV_ALIGN_BOTTOM_MID);
  lv_label_set_text(ui_lblMenuSTK, "STK");
  lv_obj_set_style_text_font(ui_lblMenuSTK, &lv_font_montserrat_10,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_menuContactsContainer = lv_obj_create(ui_menuMainContainer);
  lv_obj_remove_style_all(ui_menuContactsContainer);
  lv_obj_set_width(ui_menuContactsContainer, 50);
  lv_obj_set_height(ui_menuContactsContainer, 50);
  lv_obj_set_x(ui_menuContactsContainer, 180);
  lv_obj_set_y(ui_menuContactsContainer, 175);
  lv_obj_remove_flag(ui_menuContactsContainer,
                     LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_imbMenuContacts = lv_imagebutton_create(ui_menuContactsContainer);
  lv_imagebutton_set_src(ui_imbMenuContacts, LV_IMAGEBUTTON_STATE_RELEASED,
                         NULL, &ui_img_usergroup40_png, NULL);
  lv_obj_set_width(ui_imbMenuContacts, 40);
  lv_obj_set_height(ui_imbMenuContacts, 40);
  lv_obj_set_align(ui_imbMenuContacts, LV_ALIGN_TOP_MID);

  ui_lblMenuContacts = lv_label_create(ui_menuContactsContainer);
  lv_obj_set_width(ui_lblMenuContacts, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_lblMenuContacts, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_lblMenuContacts, LV_ALIGN_BOTTOM_MID);
  lv_label_set_text(ui_lblMenuContacts, "Contacts");
  lv_obj_set_style_text_font(ui_lblMenuContacts, &lv_font_montserrat_10,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_menuGalleryContainer = lv_obj_create(ui_menuMainContainer);
  lv_obj_remove_style_all(ui_menuGalleryContainer);
  lv_obj_set_width(ui_menuGalleryContainer, 50);
  lv_obj_set_height(ui_menuGalleryContainer, 50);
  lv_obj_set_x(ui_menuGalleryContainer, 5);
  lv_obj_set_y(ui_menuGalleryContainer, 230);
  lv_obj_remove_flag(ui_menuGalleryContainer,
                     LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_imbGallery = lv_imagebutton_create(ui_menuGalleryContainer);
  lv_imagebutton_set_src(ui_imbGallery, LV_IMAGEBUTTON_STATE_RELEASED, NULL,
                         &ui_img_gallery40_png, NULL);
  lv_obj_set_width(ui_imbGallery, 40);
  lv_obj_set_height(ui_imbGallery, 40);
  lv_obj_set_align(ui_imbGallery, LV_ALIGN_TOP_MID);

  ui_lblMenuGallery = lv_label_create(ui_menuGalleryContainer);
  lv_obj_set_width(ui_lblMenuGallery, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_lblMenuGallery, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_lblMenuGallery, LV_ALIGN_BOTTOM_MID);
  lv_label_set_text(ui_lblMenuGallery, "Gallery");
  lv_obj_set_style_text_font(ui_lblMenuGallery, &lv_font_montserrat_10,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_menuMusicContainer = lv_obj_create(ui_menuMainContainer);
  lv_obj_remove_style_all(ui_menuMusicContainer);
  lv_obj_set_width(ui_menuMusicContainer, 50);
  lv_obj_set_height(ui_menuMusicContainer, 50);
  lv_obj_set_x(ui_menuMusicContainer, 60);
  lv_obj_set_y(ui_menuMusicContainer, 230);
  lv_obj_remove_flag(ui_menuMusicContainer,
                     LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_imbMusic = lv_imagebutton_create(ui_menuMusicContainer);
  lv_imagebutton_set_src(ui_imbMusic, LV_IMAGEBUTTON_STATE_RELEASED, NULL,
                         &ui_img_music40_png, NULL);
  lv_obj_set_width(ui_imbMusic, 40);
  lv_obj_set_height(ui_imbMusic, 40);
  lv_obj_set_align(ui_imbMusic, LV_ALIGN_TOP_MID);

  ui_lblMenuMusic = lv_label_create(ui_menuMusicContainer);
  lv_obj_set_width(ui_lblMenuMusic, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_lblMenuMusic, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_lblMenuMusic, LV_ALIGN_BOTTOM_MID);
  lv_label_set_text(ui_lblMenuMusic, "Music");
  lv_obj_set_style_text_font(ui_lblMenuMusic, &lv_font_montserrat_10,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_menuRadioContainer = lv_obj_create(ui_menuMainContainer);
  lv_obj_remove_style_all(ui_menuRadioContainer);
  lv_obj_set_width(ui_menuRadioContainer, 50);
  lv_obj_set_height(ui_menuRadioContainer, 50);
  lv_obj_set_x(ui_menuRadioContainer, 120);
  lv_obj_set_y(ui_menuRadioContainer, 230);
  lv_obj_remove_flag(ui_menuRadioContainer,
                     LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_imbRadio = lv_imagebutton_create(ui_menuRadioContainer);
  lv_imagebutton_set_src(ui_imbRadio, LV_IMAGEBUTTON_STATE_RELEASED, NULL,
                         &ui_img_radio40_png, NULL);
  lv_obj_set_width(ui_imbRadio, 40);
  lv_obj_set_height(ui_imbRadio, 40);
  lv_obj_set_align(ui_imbRadio, LV_ALIGN_TOP_MID);

  ui_lblMenuRadio = lv_label_create(ui_menuRadioContainer);
  lv_obj_set_width(ui_lblMenuRadio, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_lblMenuRadio, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_lblMenuRadio, LV_ALIGN_BOTTOM_MID);
  lv_label_set_text(ui_lblMenuRadio, "Radio");
  lv_obj_set_style_text_font(ui_lblMenuRadio, &lv_font_montserrat_10,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_menuVideosContainer = lv_obj_create(ui_menuMainContainer);
  lv_obj_remove_style_all(ui_menuVideosContainer);
  lv_obj_set_width(ui_menuVideosContainer, 50);
  lv_obj_set_height(ui_menuVideosContainer, 50);
  lv_obj_set_x(ui_menuVideosContainer, 180);
  lv_obj_set_y(ui_menuVideosContainer, 230);
  lv_obj_remove_flag(ui_menuVideosContainer,
                     LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_imbVideos = lv_imagebutton_create(ui_menuVideosContainer);
  lv_imagebutton_set_src(ui_imbVideos, LV_IMAGEBUTTON_STATE_RELEASED, NULL,
                         &ui_img_video40_png, NULL);
  lv_obj_set_width(ui_imbVideos, 40);
  lv_obj_set_height(ui_imbVideos, 40);
  lv_obj_set_align(ui_imbVideos, LV_ALIGN_TOP_MID);

  ui_lblMenuVideos = lv_label_create(ui_menuVideosContainer);
  lv_obj_set_width(ui_lblMenuVideos, LV_SIZE_CONTENT);   /// 1
  lv_obj_set_height(ui_lblMenuVideos, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_align(ui_lblMenuVideos, LV_ALIGN_BOTTOM_MID);
  lv_label_set_text(ui_lblMenuVideos, "Videos");
  lv_obj_set_style_text_font(ui_lblMenuVideos, &lv_font_montserrat_10,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  // Add the navigation bar
  ui_add_bottom_bar(ui_mainMenuScreen, 0xFFFFFF, -5);

  // Register events callbacks
  lv_obj_add_event_cb(ui_imbPhone, ui_event_imagebutton_cb, LV_EVENT_ALL,
                      "phone");
  lv_obj_add_event_cb(ui_imbMessages, ui_event_imagebutton_cb, LV_EVENT_ALL,
                      "messages");
  lv_obj_add_event_cb(ui_imbMultimedia, ui_event_imagebutton_cb, LV_EVENT_ALL,
                      "multimedia");
  lv_obj_add_event_cb(ui_imbExtra, ui_event_imagebutton_cb, LV_EVENT_ALL,
                      "extra");
  lv_obj_add_event_cb(ui_imbGames, ui_event_imagebutton_cb, LV_EVENT_ALL,
                      "games");
  lv_obj_add_event_cb(ui_imbMyZone, ui_event_imagebutton_cb, LV_EVENT_ALL,
                      "my-zone");
  lv_obj_add_event_cb(ui_imbAbout, ui_event_imagebutton_cb, LV_EVENT_ALL,
                      "about");
  lv_obj_add_event_cb(ui_imbTools, ui_event_imagebutton_cb, LV_EVENT_ALL,
                      "tools");
  lv_obj_add_event_cb(ui_imbSettings, ui_event_imagebutton_cb, LV_EVENT_ALL,
                      "settings");
  lv_obj_add_event_cb(ui_imbClock, ui_event_imagebutton_cb, LV_EVENT_ALL,
                      "clock");
  lv_obj_add_event_cb(ui_imbCalculator, ui_event_imagebutton_cb, LV_EVENT_ALL,
                      "calculator");
  lv_obj_add_event_cb(ui_imbCalendar, ui_event_imagebutton_cb, LV_EVENT_ALL,
                      "calendar");
  lv_obj_add_event_cb(ui_imbFiles, ui_event_imagebutton_cb, LV_EVENT_ALL,
                      "files");
  lv_obj_add_event_cb(ui_imbTodo, ui_event_imagebutton_cb, LV_EVENT_ALL,
                      "todo");
  lv_obj_add_event_cb(ui_imbSTK, ui_event_imagebutton_cb, LV_EVENT_ALL, "stk");
  lv_obj_add_event_cb(ui_imbMenuContacts, ui_event_imagebutton_cb, LV_EVENT_ALL,
                      "contacts");
  lv_obj_add_event_cb(ui_imbGallery, ui_event_imagebutton_cb, LV_EVENT_ALL,
                      "gallery");
  lv_obj_add_event_cb(ui_imbMusic, ui_event_imagebutton_cb, LV_EVENT_ALL,
                      "music");
  lv_obj_add_event_cb(ui_imbRadio, ui_event_imagebutton_cb, LV_EVENT_ALL,
                      "radio");
  lv_obj_add_event_cb(ui_imbVideos, ui_event_imagebutton_cb, LV_EVENT_ALL,
                      "video");
}
