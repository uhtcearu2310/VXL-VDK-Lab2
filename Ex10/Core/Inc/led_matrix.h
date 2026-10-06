/*
 * led_matrix.h
 *
 *  Created on: Sep 29, 2026
 *      Author: admin
 */

#ifndef INC_LED_MATRIX_H_
#define INC_LED_MATRIX_H_

#include "main.h"

// Mức logic Active-Low cho cả Hàng (ROW) và Cột (ENM)
#define MATRIX_ON   GPIO_PIN_RESET
#define MATRIX_OFF  GPIO_PIN_SET

#define MAX_LED_MATRIX 8

extern int index_led_matrix;
extern uint8_t matrix_buffer[MAX_LED_MATRIX];

// Các hàm điều khiển cho Exercise 9
void displayLEDMatrix(uint8_t data);
void enableLEDMatrix(int index);
void updateLEDMatrix(int index);

// Hàm dịch chuyển chữ (Animation) cho Exercise 10
void shiftLeftLEDMatrix(void);

#endif /* INC_LED_MATRIX_H_ */
