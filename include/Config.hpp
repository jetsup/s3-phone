#ifndef CONFIG_HPP_
#define CONFIG_HPP_

#define S3PHONE_MODEL_NAME "s3phone"

// IO
#define S3_PHONE_ANALOG_RESOLUTION 12

// GSM
#define GSM_RX 4
#define GSM_TX 5
#define GSM_BAUD 9600

// Display (ILI9341) - Touch (XPT2046)
#define TFT_CS 15
#define TFT_RST 16
#define TFT_DC 17
#define TFT_MISO 9
#define TFT_MOSI 18
#define TFT_CLK 8
#define TFT_LED 3
#define TOUCH_CLK TFT_CLK
#define TOUCH_CS 10
#define TOUCH_DIN TFT_MOSI
#define TOUCH_DO TFT_MISO

#define CALIBRATION_DATA {282, 433, 252, 3865, 3815, 438, 3833, 3878}

#define TFT_WIDTH 240
#define TFT_HEIGHT 320
#define TFT_DRAW_BUF_SIZE (TFT_WIDTH * TFT_HEIGHT / 10 * (LV_COLOR_DEPTH / 8))

// NTP and Internet
#define S3_NTP_SERVER "pool.ntp.org"
#define S3INTERNET_PING_ADDRESS "www.google.com"

// Connectivity Bluetooth
// https://www.uuidgenerator.net/
#define SERVICE_UUID "7668d2f7-0a48-40f4-ad1d-beff839e6bf0"
#define CHARACTERISTIC_UUID "98f9284b-6dbe-42f1-a3d6-319d964b76f2"

// WIFI
#define S3WIFI_RECONNECT_TIMEOUT (10 * 1000)  // ms

// File System
#define FILESYSTEM_FORMAT_ON_FAIL 1

#define FS_SETTINGS_DISPLAY_FILEPATH "/system/settings/display.json"
#define FS_SETTINGS_THEMES_FILEPATH "/system/settings/themes.json"
#define FS_SETTINGS_CONNECTIVITY_FILEPATH "/system/settings/connectivity.json"
#define FS_SETTINGS_NETWORK_INTERNET_FILEPATH "/system/settings/networking.json"
#define FS_SETTINGS_NETWORK_WIFI_CREDENTIALS "/system/credentials/wifi.json"

#define FS_VAR_SETTINGS_DISPLAY_BRIGHTNESS "brightness"
#define FS_DEF_SETTINGS_DISPLAY_BRIGHTNESS "120"
#define FS_VAR_SETTINGS_DISPLAY_TIMEOUT "timeout"
#define FS_DEF_SETTINGS_DISPLAY_TIMEOUT "15"

#define FS_VAR_SETTINGS_THEMES_THEME_DARK "dark"
#define FS_DEF_SETTINGS_THEMES_THEME_DARK "0"
#define FS_VAR_SETTINGS_THEMES_WALLPAPER "wallpaper"
#define FS_DEF_SETTINGS_THEMES_WALLPAPER "1"
#define FS_VAR_SETTINGS_THEMES_FONT_SMALL "sfont"
#define FS_DEF_SETTINGS_THEMES_FONT_SMALL "8"
#define FS_VAR_SETTINGS_THEMES_FONT_MEDIUM "mfont"
#define FS_DEF_SETTINGS_THEMES_FONT_MEDIUM "14"
#define FS_VAR_SETTINGS_THEMES_FONT_LARGE "lfont"
#define FS_DEF_SETTINGS_THEMES_FONT_LARGE "18"

#define FS_VAR_SETTINGS_CONNECTIVITY_BLE "ble"
#define FS_DEF_SETTINGS_CONNECTIVITY_BLE "0"

#define FS_VAR_SETTINGS_NETWORKING_HOTSPOT_NAME "hotspot-name"
#define FS_DEF_SETTINGS_NETWORKING_HOTSPOT_NAME "s3phone"
#define FS_VAR_SETTINGS_NETWORKING_WIFI_STATE "wifi-state"
#define FS_DEF_SETTINGS_NETWORKING_WIFI_STATE "0"

// SQLite
#define S3_SQLITE_DB_FILE "/system/db/s3phone.db"
// System database for system settings and configurations
#define S3_SQLITE_DB_SYSTEM_FILEPATH "/system/db/system.db"

#endif  // CONFIG_HPP_
