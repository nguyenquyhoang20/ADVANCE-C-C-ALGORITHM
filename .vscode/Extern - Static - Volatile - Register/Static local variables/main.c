#include <stdio.h>
#include "counter.h"  // Gọi file header để sử dụng hàm counter


// Hàm tính trung bình với biến static đếm số lần gọi và tổng giá trị
double counter(int value) {
    static int count = 0;  // Biến static để đếm số lần hàm được gọi
    static int sum = 0;    // Biến static để lưu tổng các giá trị đầu vào

    count++;               // Tăng biến đếm mỗi khi hàm được gọi
    sum += value;          // Cộng giá trị đầu vào vào tổng

    return (double)sum / count;  // Trả về trung bình
}

int main() {
    int num1 = 5;
    int num2 = 10;
    int num3 = 15;

    // Gọi hàm counter và in ra kết quả mỗi lần
    printf("Average after input %d: %f\n", num1, counter(num1));
    printf("Average after input %d: %f\n", num2, counter(num2));
    printf("Average after input %d: %f\n", num3, counter(num3));

    return 0;
}
