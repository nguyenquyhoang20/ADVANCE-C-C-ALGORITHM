#include <stdio.h>
#include "counter.h"  // Gọi file header để sử dụng hàm add_to_total



// Biến static toàn cục để lưu trữ tổng các giá trị
static int total = 0;  // Biến này chỉ có thể được truy cập trong file counter.c

// Hàm thêm giá trị vào tổng và trả về tổng mới
int add_to_total(int value) {
    total += value;  // Cộng giá trị vào tổng
    return total;    // Trả về tổng mới
}



int main() {
    // Gọi hàm add_to_total với các giá trị khác nhau
    printf("Total after adding 10: %d\n", add_to_total(10));
    printf("Total after adding 20: %d\n", add_to_total(20));
    printf("Total after adding 30: %d\n", add_to_total(30));

    return 0;
}
