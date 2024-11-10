#ifndef CALCULATOR_H
#define CALCULATOR_H

// Khai báo biến toàn cục để sử dụng trong các hàm
extern int num1;  // Khai báo biến extern cho số thứ nhất
extern int num2;  // Khai báo biến extern cho số thứ hai

// Khai báo các hàm tính toán
int add();       // Hàm cộng
int subtract();  // Hàm trừ
int multiply();  // Hàm nhân
int divide();    // Hàm chia (có kiểm tra chia cho 0)

#endif
