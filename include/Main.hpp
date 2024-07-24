#pragma once

#include <Arduino.h>
#include <lvgl.h>

#include <Display.hpp>
#include <FileSystem.hpp>
#include <GSM.hpp>
#include <Helpers.hpp>

#include "ui.h"
#include "ui_contacts.h"

int contactsCount = 0;
String names[] = {"George Ngigi", "John", "Joe", "Brandon"};
String numbers[] = {"0714430347", "0788965432", "0709765432", "0787653434"};
char *cStrNames[] = {};
char *cStrNumbers[] = {};

char *cNames[] = {};
char *cNumbers[] = {};
int cCount = 0;

GSM gsm(GSM_RX, GSM_TX, GSM_BAUD);
static Display display(TFT_CLK, TFT_MOSI, TFT_MISO, TFT_CS, TFT_DC, TFT_RST,
                       TFT_LED, TOUCH_CS, TOUCH_CLK, TOUCH_DIN, TOUCH_DO);
S3Time s3Time("2024-11-01 14:40:56", 3);
FileSystem fileSystem(LittleFS);

unsigned int lastTickMillis = 0;

void *drawBuffer;
const unsigned int lvBufferSize = TFT_DRAW_BUF_SIZE;
uint8_t lvBuffer[lvBufferSize * 2];
uint8_t lvBuffer2[lvBufferSize * 2];
static lv_display_t *lv_display;

/* Display flushing*/
void lv_flush_cb(lv_display_t *disp, const lv_area_t *area,
                 unsigned char *data);

/* Read the touchpad*/
void my_touchpad_read(lv_indev_t *indev_driver, lv_indev_data_t *data);
