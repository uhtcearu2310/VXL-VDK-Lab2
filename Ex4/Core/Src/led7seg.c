/*
 * led7seg.c
 *
 *  Created on: Sep 27, 2026
 *      Author: admin
 */

#include "led7seg.h"

// Khởi tạo biến toàn cục cho bộ đệm 4 đèn LED 7 đoạn
int index_led = 0;
int led_buffer[MAX_LED] = {1, 2, 3, 0};

// Bảng mã bit cho LED 7 đoạn Anode chung (0: Sáng, 1: Tắt) từ số 0 đến 9
const uint8_t seg_code[10] = {
    0xC0, // 0
    0xF9, // 1
    0xA4, // 2
    0xB0, // 3
    0x99, // 4
    0x92, // 5
    0x82, // 6
    0xF8, // 7
    0x80, // 8
    0x90  // 9
};

// Hiển thị con số (0 - 9) ra các chân PB0 -> PB6
void display7SEG(int num) {
    if (num >= 0 && num <= 9) {
        HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, (seg_code[num] & 0x01) ? SEG_OFF : SEG_ON);
        HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, (seg_code[num] & 0x02) ? SEG_OFF : SEG_ON);
        HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, (seg_code[num] & 0x04) ? SEG_OFF : SEG_ON);
        HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, (seg_code[num] & 0x08) ? SEG_OFF : SEG_ON);
        HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, (seg_code[num] & 0x10) ? SEG_OFF : SEG_ON);
        HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, (seg_code[num] & 0x20) ? SEG_OFF : SEG_ON);
        HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, (seg_code[num] & 0x40) ? SEG_OFF : SEG_ON);
    }
}

// Bật đúng 1 bóng LED 7 đoạn tại vị trí index (0..3), tắt các bóng còn lại
void enable7SEG(int index) {
    HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, (index == 0) ? EN_ON : EN_OFF);
    HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, (index == 1) ? EN_ON : EN_OFF);
    HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, (index == 2) ? EN_ON : EN_OFF);
    HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, (index == 3) ? EN_ON : EN_OFF);
}

// Hàm chuẩn theo khung yêu cầu của Exercise 3
void update7SEG(int index) {
    switch (index) {
        case 0:
            enable7SEG(0);
            display7SEG(led_buffer[0]);
            break;
        case 1:
            enable7SEG(1);
            display7SEG(led_buffer[1]);
            break;
        case 2:
            enable7SEG(2);
            display7SEG(led_buffer[2]);
            break;
        case 3:
            enable7SEG(3);
            display7SEG(led_buffer[3]);
            break;
        default:
            break;
    }
}

// Hàm chuẩn cho Exercise 5: Tách hàng chục và hàng đơn vị của Giờ - Phút
void updateClockBuffer(int hour, int minute) {
    led_buffer[0] = hour / 10;   // Chữ số hàng chục của Giờ
    led_buffer[1] = hour % 10;   // Chữ số hàng đơn vị của Giờ
    led_buffer[2] = minute / 10; // Chữ số hàng chục của Phút
    led_buffer[3] = minute % 10; // Chữ số hàng đơn vị của Phút
}
