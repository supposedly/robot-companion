#pragma once
#include "Common.h"

#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

#define Matrix Adafruit_8x16matrix

Matrix brows = Matrix();
Matrix mouth = Matrix();

// expresions of robot (more could be added)
enum class Expression {
  Happy,
  Dead,
  Sweat,
  Shiver,
  Sleep,
  AAAAA
};

Expression currentExpression;
int currentDisplayPriority;

static const uint8_t PROGMEM
    left_brow_happy[] =
        {B00000000,
         B00110000,
         B00010000,
         B00001000,
         B00001000,
         B00001000,
         B00010000,
         B00000000},
    right_brow_happy[] =
        {B00000000,
         B00010000,
         B00001000,
         B00001000,
         B00001000,
         B00010000,
         B00110000,
         B00000000},
    left_mouth_happy[] =
        {B00000000,
         B00010000,
         B00100000,
         B00100000,
         B00100000,
         B00100000,
         B00100000,
         B00100000},
    right_mouth_happy[] =
        {B00100000,
         B00100000,
         B00100000,
         B00100000,
         B00100000,
         B00100000,
         B00010000,
         B00000000},
    left_brow_dead[] =
        {B00000000,
         B11111111,
         B00010001,
         B00010001,
         B11101110,
         B00000000,
         B10000001,
         B11111111},
    right_brow_dead[] =
        {B11111111,
         B10000001,
         B00000000,
         B11111111,
         B00001001,
         B00001001,
         B00000110,
         B00000000},
    left_mouth_dead[] =
        {B01111000,
         B10001000,
         B10001000,
         B01111000,
         B00001000,
         B00001000,
         B00001000,
         B00001000},
    right_mouth_dead[] =
        {B00001000,
         B00001000,
         B00001000,
         B00001000,
         B00001000,
         B00011000,
         B00010000,
         B00100000},
    left_brow_sweat[] =
        {B00001100,
         B00010010,
         B00010001,
         B00010010,
         B00001100,
         B00000000,
         B00000000,
         B00000000},
    right_brow_sweat[] =
        {B00000000,
         B00000000,
         B00110000,
         B01001000,
         B01000100,
         B01001000,
         B00110000,
         B00000000},
    left_brow_sweat1[] =
        {B00110000,
         B01001000,
         B01000100,
         B01001000,
         B00110000,
         B00000000,
         B00000000,
         B00000000},
    right_brow_sweat1[] =
        {B00000000,
         B00000000,
         B11000000,
         B00100001,
         B00010001,
         B00100001,
         B11000000,
         B00000000},
    left_brow_sweat2[] =
        {B11000000,
         B00100001,
         B00010001,
         B00100001,
         B11000000,
         B00000000,
         B00000000,
         B00000000},
    right_brow_sweat2[] =
        {B00000000,
         B00000000,
         B00000011,
         B10000100,
         B01000100,
         B10000100,
         B00000011,
         B00000000},
    left_brow_sweat3[] =
        {B00000011,
         B10000100,
         B01000100,
         B10000100,
         B00000011,
         B00000000,
         B00000000,
         B00000000},
    right_brow_sweat3[] =
        {B00000000,
         B00000000,
         B00001100,
         B00010010,
         B00010001,
         B00010010,
         B00001100,
         B00000000},
    left_brow_sweat4[] =
        {B00001100,
         B00010010,
         B00010001,
         B00010010,
         B00001100,
         B00000000,
         B00000000,
         B00000000},
    right_brow_sweat4[] =
        {B00000000,
         B00000000,
         B00110000,
         B01001000,
         B01000100,
         B01001000,
         B00110000,
         B00000000},
    left_mouth_sweat[] =
        {B00000000,
         B00000000,
         B00001000,
         B00001000,
         B00001000,
         B01111000,
         B10001000,
         B10111000},
    right_mouth_sweat[] =
        {B10111000,
         B10001000,
         B01111000,
         B00001000,
         B00001000,
         B00001000,
         B00000000,
         B00000000},
    left_brow_shiver[] =
        {B00000000,
         B00010000,
         B00100000,
         B00010000,
         B00100000,
         B00010000,
         B00100000,
         B00000000},
    right_brow_shiver[] =
        {B00000000,
         B00010000,
         B00100000,
         B00010000,
         B00100000,
         B00010000,
         B00100000,
         B00000000},
    left_brow_shiver1[] =
        {B00000000,
         B00100000,
         B00010000,
         B00100000,
         B00010000,
         B00100000,
         B00010000,
         B00000000},
    right_brow_shiver1[] =
        {B00000000,
         B00100000,
         B00010000,
         B00100000,
         B00010000,
         B00100000,
         B00010000,
         B00000000},
    left_mouth_shiver[] =
        {B00000000,
         B00111100,
         B01001010,
         B01111110,
         B01010010,
         B01010010,
         B01111110,
         B01001010},
    right_mouth_shiver[] =
        {B01001010,
         B01111110,
         B01010010,
         B01001010,
         B01111110,
         B01010010,
         B00111100,
         B00000000},
    left_mouth_shiver1[] =
        {B00000000,
         B00111100,
         B01001010,
         B01010100,
         B01010010,
         B01111110,
         B00101000,
         B01111110},
    right_mouth_shiver1[] =
        {B01001000,
         B01010010,
         B01111110,
         B01001100,
         B01010010,
         B01000100,
         B00111100,
         B00000000},
    left_brow_sleep[] =
        {B01100001,
         B01010001,
         B01001001,
         B01000101,
         B01000011,
         B00000000,
         B01100010,
         B01010010},
    right_brow_sleep[] =
        {B01001010,
         B01000110,
         B00000000,
         B01100100,
         B01010100,
         B01001100,
         B00000000,
         B00000000},
    left_mouth_sleep[] =
        {B00000000,
         B00000000,
         B00000000,
         B00000000,
         B00111000,
         B01000100,
         B10000010,
         B10000010},
    right_mouth_sleep[] =
        {B10000010,
         B10000010,
         B01000100,
         B00111000,
         B00000000,
         B00000000,
         B00000000,
         B00000000},
    left_brow_bmp[] =
        {B00000000,
         B00000000,
         B00100000,
         B00100000,
         B00100000,
         B00100000,
         B01000000,
         B00000000},
    right_brow_bmp[] =
        {B00000000,
         B01000000,
         B00100000,
         B00100000,
         B00100000,
         B00100000,
         B00000000,
         B00000000},
    left_mouth_bmp[] =
        {B00000000,
         B00000000,
         B00000110,
         B00000100,
         B00000100,
         B00000100,
         B00000100,
         B00000100},
    right_mouth_bmp[] =
        {B00000100,
         B00000100,
         B00000100,
         B00000100,
         B00000100,
         B00000110,
         B00000000,
         B00000000};

void setupMatrix() {
    mouth.begin(0x70);
    brows.begin(0x71);

    brows.clear();
    brows.drawBitmap(0, 0, right_brow_bmp, 8, 8, LED_ON);
    brows.drawBitmap(0, 8, left_brow_bmp, 8, 8, LED_ON);
    brows.writeDisplay();
    if (false) {
        mouth.fillRect(0, 0, 8, 16, LED_ON);
        mouth.fillRect(3, 2, 3, 12, LED_OFF);
        mouth.fillRect(1, 2, 3, 3, LED_OFF);
        mouth.fillRect(1, 11, 3, 3, LED_OFF);
    } else if (false) {
        mouth.fillRect(0, 0, 8, 16, LED_ON);
        mouth.fillRect(1, 2, 3, 12, LED_OFF);
        mouth.fillRect(3, 2, 3, 3, LED_OFF);
        mouth.fillRect(3, 11, 3, 3, LED_OFF);
    } else {
        mouth.drawBitmap(0, 0, left_mouth_bmp, 8, 8, LED_ON);
        mouth.drawBitmap(0, 8, right_mouth_bmp, 8, 16, LED_ON);
        if (true) {
            mouth.drawPixel(6, 2, LED_OFF);
            mouth.drawPixel(6, 13, LED_OFF);
        }
    }
    mouth.writeDisplay();
}

void draw(const uint8_t *rightBrow, const uint8_t *leftBrow, const uint8_t *rightMouth, const uint8_t *leftMouth) {
    brows.clear();
    brows.drawBitmap(0, 0, leftBrow, 8, 8, LED_ON);
    brows.drawBitmap(0, 8, rightBrow, 8, 8, LED_ON);
    brows.writeDisplay();

    mouth.clear();
    mouth.drawBitmap(0, 0, leftMouth, 8, 8, LED_ON);
    mouth.drawBitmap(0, 8, rightMouth, 8, 8, LED_ON);
    mouth.writeDisplay();
}

#define ANIM_DELAY 50
int animIndex = 0;

bool SetDisplays(Priority priority, Expression expression) {
    if ((int)priority < currentDisplayPriority) {
        return false;
    }

    currentDisplayPriority = (int)priority;
    switch (expression) {
        case Expression::Happy: {
            draw(right_brow_happy, left_brow_happy, right_mouth_happy, left_mouth_happy);
            break;
        }
        case Expression::Dead: {
            draw(right_brow_dead, left_brow_dead, right_mouth_dead, left_mouth_dead);
            break;
        }
        case Expression::Sweat: {
            // draw(*(&right_brow_sweat + sweatIndex * 2), *(&left_brow_sweat + sweatIndex * 2), right_mouth_sweat, left_mouth_sweat);
            if (animIndex / ANIM_DELAY == 0) {
                draw(right_brow_sweat, left_brow_sweat, right_mouth_sweat, left_mouth_sweat);
            } else if (animIndex / ANIM_DELAY == 1) {
                draw(right_brow_sweat1, left_brow_sweat1, right_mouth_sweat, left_mouth_sweat);
            } else if (animIndex / ANIM_DELAY == 2) {
                draw(right_brow_sweat2, left_brow_sweat2, right_mouth_sweat, left_mouth_sweat);
            } else if (animIndex / ANIM_DELAY == 3) {
                draw(right_brow_sweat3, left_brow_sweat3, right_mouth_sweat, left_mouth_sweat);
            }
            break;
        }
        case Expression::Shiver: {
            if ((animIndex / ANIM_DELAY) % 2) {
                draw(right_brow_shiver, left_brow_shiver, right_mouth_shiver, left_mouth_shiver);
            } else {
                draw(right_brow_shiver1, left_brow_shiver1, right_mouth_shiver1, left_mouth_shiver1);
            }
            break;
        }
        case Expression::Sleep: {
            draw(right_brow_sleep, left_brow_sleep, right_mouth_sleep, left_mouth_sleep);
            break;
        }
        case Expression::AAAAA: {
            brows.clear();
            brows.drawBitmap(0, 0, left_brow_bmp, 8, 8, LED_ON);
            brows.drawBitmap(0, 8, right_brow_bmp, 8, 8, LED_ON);
            brows.writeDisplay();
            mouth.fillRect(0, 0, 8, 16, LED_ON);
            mouth.writeDisplay();
            break;
        }
    }
    animIndex = (animIndex + 1) % (4 * ANIM_DELAY);
    return true;
}

void ClearDisplayPriority(byte priority) {
    if (priority == currentDisplayPriority) {
        currentDisplayPriority = -1;
    }
}

void ClearDisplayPriority(Priority priority) {
    ClearDisplayPriority((byte) priority);
}
