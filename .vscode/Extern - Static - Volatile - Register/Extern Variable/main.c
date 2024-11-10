#include <stdio.h>
#include "calculator.h"  // Gọi file header để sử dụng các biến và hàm đã khai báo

int num1 = 0;  // Khởi tạo biến toàn cục cho số thứ nhất
int num2 = 0;  // Khởi tạo biến toàn cục cho số thứ hai

// Định nghĩa các hàm tính toán
int add() {
    return num1 + num2;
}

int subtract() {
    return num1 - num2;
}

int multiply() {
    return num1 * num2;
}

int divide() {
    if (num2 != 0) {
        return num1 / num2;
    } else {
        printf("Error: Division by zero.\n");
        return 0;
    }
}

int main() {
    // Gán giá trị cho các biến
    num1 = 20;
    num2 = 10;

    // Thực hiện các phép toán và in kết quả ra màn hình
    printf("Num1: %d, Num2: %d\n", num1, num2);
    printf("Sum: %d\n", add());
    printf("Difference: %d\n", subtract());
    printf("Product: %d\n", multiply());
    printf("Quotient: %d\n", divide());

    return 0;
}
