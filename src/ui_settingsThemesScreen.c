#include "ui.h"

void ui_settingsThemesScreen_screen_init(void) {
  ui_settingsThemesScreen = lv_obj_create(NULL);
  lv_obj_remove_flag(ui_settingsThemesScreen,
                     LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  int yOffset = UI_ALIGN_TOP_LEFT_Y_OFFSET;

  ui_panelSettingsTheme = lv_obj_create(ui_settingsThemesScreen);
  lv_obj_set_width(ui_panelSettingsTheme, 240);
  lv_obj_set_height(ui_panelSettingsTheme, 320);
  lv_obj_remove_flag(ui_panelSettingsTheme, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_bg_image_src(ui_panelSettingsTheme, screenWallpaperImg,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_image_opa(ui_panelSettingsTheme, 100,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_color(ui_panelSettingsTheme, lv_color_hex(0x000000),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_opa(ui_panelSettingsTheme, 0,
                              LV_PART_MAIN | LV_STATE_DEFAULT);

  // Theme switch
  lv_obj_t *lblTheme = lv_label_create(ui_panelSettingsTheme);
  lv_obj_set_align(lblTheme, LV_ALIGN_TOP_LEFT);
  lv_obj_set_y(lblTheme, yOffset);
  lv_label_set_text(lblTheme, "Theme and UX");
  lv_obj_set_align(lblTheme, LV_ALIGN_TOP_MID);
  lv_obj_set_style_text_font(lblTheme, &lv_font_montserrat_18,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  yOffset += 25;

  lblTheme = lv_label_create(ui_panelSettingsTheme);
  lv_obj_set_align(lblTheme, LV_ALIGN_TOP_LEFT);
  lv_obj_set_x(lblTheme, UI_ALIGN_TOP_LEFT_X_OFFSET + 5);
  lv_obj_set_y(lblTheme, yOffset);
  lv_label_set_text(lblTheme, "Dark Theme");
  lv_obj_set_style_text_font(lblTheme, &lv_font_montserrat_14,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_switchTheme = lv_switch_create(ui_panelSettingsTheme);
  lv_obj_set_height(ui_switchTheme, 20);
  lv_obj_align_to(
      ui_switchTheme, lblTheme, LV_ALIGN_LEFT_MID,
      240 -
          (UI_ALIGN_TOP_LEFT_X_OFFSET +
           lv_text_get_width("Dark Theme", 10, &lv_font_montserrat_14, 0) +
           lv_obj_get_width(ui_switchTheme)) +
          10,
      0);
  if (darkThemeSelected) {
    lv_obj_add_state(ui_switchTheme, LV_STATE_CHECKED);
  }
  lv_obj_add_event_cb(ui_switchTheme, ui_event_switch_cb,
                      LV_EVENT_VALUE_CHANGED, "theme switch");

  yOffset += 25;

  // Wallpaper select
  lv_obj_t *lblWallpaper = lv_label_create(ui_panelSettingsTheme);
  lv_obj_set_align(lblWallpaper, LV_ALIGN_TOP_LEFT);
  lv_obj_set_x(lblWallpaper, UI_ALIGN_TOP_LEFT_X_OFFSET + 5);
  lv_obj_set_y(lblWallpaper, yOffset);
  lv_label_set_text(lblWallpaper, "Wallpaper");
  lv_obj_set_style_text_font(lblWallpaper, &lv_font_montserrat_14,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  yOffset += 20;

  lv_obj_t *ui_lblSelectedWallpaper = lv_label_create(ui_panelSettingsTheme);
  lv_obj_align_to(ui_lblSelectedWallpaper, lblWallpaper, LV_ALIGN_OUT_RIGHT_MID,
                  30, 0);
  lv_label_set_text(ui_lblSelectedWallpaper, selectedWallpaper);
  lv_obj_set_style_text_font(ui_lblSelectedWallpaper, &lv_font_montserrat_14,
                             LV_PART_MAIN | LV_STATE_DEFAULT);

  const char *wallpaperTags[5] = {"wallpaper-select 1", "wallpaper-select 2",
                                  "wallpaper-select 3", "wallpaper-select 4",
                                  "wallpaper-select 5"};

  for (int i = 1; i <= 5; i++) {
    char wallpaperName[19];
    lv_utils_getResourceName(i, wallpaperName);

    lv_obj_t *lblWallpaperImgName = lv_label_create(ui_panelSettingsTheme);
    lv_obj_set_x(lblWallpaperImgName, 10);
    lv_obj_set_y(lblWallpaperImgName, yOffset);
    lv_obj_set_align(lblWallpaperImgName, LV_ALIGN_TOP_LEFT);
    lv_label_set_text(lblWallpaperImgName, wallpaperName);
    lv_obj_set_style_text_font(lblWallpaperImgName, &lv_font_montserrat_16,
                               LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(lblWallpaperImgName, LV_OBJ_FLAG_CLICKABLE);  /// Flags

    if (screenWallpaperID == i) {
      lv_obj_set_style_text_color(lblWallpaperImgName, lv_color_hex(0x40FF40),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    // TODO: construct the tags from within the loop

    lv_obj_add_event_cb(lblWallpaperImgName, ui_event_label_cb,
                        LV_EVENT_CLICKED, wallpaperTags[i - 1]);

    yOffset += 25;
  }

  // Screen saver

  ui_add_bottom_bar(ui_panelSettingsTheme, 0xFFFFFF, 10);
}
