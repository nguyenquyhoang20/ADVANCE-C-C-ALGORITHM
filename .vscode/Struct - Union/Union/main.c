#include <stdio.h>
#include "shape.h"

// Hàm tính diện tích của hình học
// is_circle = 1 nếu là hình tròn, is_circle = 0 nếu là hình chữ nhật
float area_of_shape(Shape shape, int is_circle) {
    if (is_circle) {
        return 3.14159f * shape.radius * shape.radius; // Diện tích hình tròn: pi * r^2
    } else {
        return shape.rectangle.width * shape.rectangle.height; // Diện tích hình chữ nhật: w * h
    }
}


int main() {
    Shape shape1, shape2;

    // Tạo một hình tròn với bán kính là 5
    shape1.radius = 5.0f;
    // Tính diện tích hình tròn
    printf("Area of circle with radius %.2f = %.2f\n", shape1.radius, area_of_shape(shape1, 1));

    // Tạo một hình chữ nhật với chiều rộng 4 và chiều cao 6
    shape2.rectangle.width = 4.0f;
    shape2.rectangle.height = 6.0f;
    // Tính diện tích hình chữ nhật
    printf("Area of rectangle with width %.2f and height %.2f = %.2f\n", shape2.rectangle.width, shape2.rectangle.height, area_of_shape(shape2, 0));

    return 0;
}