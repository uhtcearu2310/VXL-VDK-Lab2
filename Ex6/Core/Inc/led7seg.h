/*
 * led7seg.h
 *
 *  Created on: Sep 27, 2026
 *      Author: admin
 */

#ifndef INC_LED7SEG_H_
#define INC_LED7SEG_H_

#include "main.h"

// Định nghĩa mức logic cho mạch Anode chung & Transistor PNP (Active-Low)
#define SEG_ON      GPIO_PIN_RESET
#define SEG_OFF     GPIO_PIN_SET

#define EN_ON       GPIO_PIN_RESET
#define EN_OFF      GPIO_PIN_SET

// Hằng số và biến toàn cục dùng từ Exercise 3 trở đi
#define MAX_LED     4
extern int index_led;
extern int led_buffer[MAX_LED];

// 1. Hàm hiển thị 1 chữ số (0-9) lên đường dữ liệu SEG0..SEG6 (Dùng từ Ex 1)
void display7SEG(int num);

// 2. Hàm chọn bật 1 trong 4 đèn LED 7 đoạn (0, 1, 2, hoặc 3)
void enable7SEG(int index);

// 3. Hàm quét LED theo bộ đệm led_buffer (Dùng từ Ex 3 -> Ex 10)
void update7SEG(int index);

// 4. Hàm tách chữ số Giờ & Phút đưa vào led_buffer (Dùng từ Ex 5 -> Ex 10)
void updateClockBuffer(int hour, int minute);

#endif /* INC_LED7SEG_H_ */
