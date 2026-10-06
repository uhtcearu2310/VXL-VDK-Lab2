/*
 * led_matrix.c
 *
 *  Created on: Sep 29, 2026
 *      Author: admin
 */

#include "led_matrix.h"

int index_led_matrix = 0;

// Bộ đệm 8 cột tạo thành hình chữ "A"
uint8_t matrix_buffer[MAX_LED_MATRIX] = {
		0x00, 0xFC, 0x12, 0x11, 0x11, 0x12, 0xFC, 0x00
};

// Xuất dữ liệu 8 bit của 1 cột ra 8 chân hàng (ROW0 -> ROW7)
void displayLEDMatrix(uint8_t data) {
    HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, (data & 0x01) ? MATRIX_ON : MATRIX_OFF);
    HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, (data & 0x02) ? MATRIX_ON : MATRIX_OFF);
    HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, (data & 0x04) ? MATRIX_ON : MATRIX_OFF);
    HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, (data & 0x08) ? MATRIX_ON : MATRIX_OFF);
    HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, (data & 0x10) ? MATRIX_ON : MATRIX_OFF);
    HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, (data & 0x20) ? MATRIX_ON : MATRIX_OFF);
    HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, (data & 0x40) ? MATRIX_ON : MATRIX_OFF);
    HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, (data & 0x80) ? MATRIX_ON : MATRIX_OFF);
}

// Bật đúng 1 cột tại vị trí index (0..7), tắt 7 cột còn lại
void enableLEDMatrix(int index) {
    HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, (index == 0) ? MATRIX_ON : MATRIX_OFF);
    HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, (index == 1) ? MATRIX_ON : MATRIX_OFF);
    HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, (index == 2) ? MATRIX_ON : MATRIX_OFF);
    HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, (index == 3) ? MATRIX_ON : MATRIX_OFF);
    HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, (index == 4) ? MATRIX_ON : MATRIX_OFF);
    HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, (index == 5) ? MATRIX_ON : MATRIX_OFF);
    HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, (index == 6) ? MATRIX_ON : MATRIX_OFF);
    HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, (index == 7) ? MATRIX_ON : MATRIX_OFF);
}

// Hàm chuẩn của Exercise 9
void updateLEDMatrix(int index) {
    switch (index) {
        case 0:
            enableLEDMatrix(0);
            displayLEDMatrix(matrix_buffer[0]);
            break;
        case 1:
            enableLEDMatrix(1);
            displayLEDMatrix(matrix_buffer[1]);
            break;
        case 2:
            enableLEDMatrix(2);
            displayLEDMatrix(matrix_buffer[2]);
            break;
        case 3:
            enableLEDMatrix(3);
            displayLEDMatrix(matrix_buffer[3]);
            break;
        case 4:
            enableLEDMatrix(4);
            displayLEDMatrix(matrix_buffer[4]);
            break;
        case 5:
            enableLEDMatrix(5);
            displayLEDMatrix(matrix_buffer[5]);
            break;
        case 6:
            enableLEDMatrix(6);
            displayLEDMatrix(matrix_buffer[6]);
            break;
        case 7:
            enableLEDMatrix(7);
            displayLEDMatrix(matrix_buffer[7]);
            break;
        default:
            break;
    }
}

// Hàm dùng cho Exercise 10: Dịch vòng tròn các cột từ phải sang trái
void shiftLeftLEDMatrix(void) {
    uint8_t temp = matrix_buffer[0]; // Cất giữ cột đầu tiên (bên trái cùng)
    for (int i = 0; i < MAX_LED_MATRIX - 1; i++) {
        matrix_buffer[i] = matrix_buffer[i + 1]; // Dịch các cột sau lên trước 1 nấc
    }
    matrix_buffer[MAX_LED_MATRIX - 1] = temp; // Đưa cột đầu tiên về cuối (bên phải cùng)
}
