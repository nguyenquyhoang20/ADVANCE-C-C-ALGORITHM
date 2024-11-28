#include <stdio.h>
#include "search.h"  // Bao gồm header chứa khai báo hàm search


// Hàm tìm kiếm tuyến tính
int linearSearch(int arr[], int n, int target) {
    register int i;  // Khai báo biến i là register
    for (i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;  // Trả về chỉ số nếu tìm thấy
        }
    }
    return -1;  // Trả về -1 nếu không tìm thấy
}

int main() {
    int arr[] = {3, 5, 1, 8, 6, 7, 10, 2};  // Mảng số nguyên
    int n = sizeof(arr) / sizeof(arr[0]);  // Số phần tử trong mảng
    int target = 7;  // Phần tử cần tìm

    // Gọi hàm tìm kiếm
    int result = linearSearch(arr, n, target);
    
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }
    
    return 0;
}
