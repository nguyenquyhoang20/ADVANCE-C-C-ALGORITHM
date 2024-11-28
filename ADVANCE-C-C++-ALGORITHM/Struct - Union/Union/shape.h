#ifndef SHAPE_H
#define SHAPE_H

// Định nghĩa một union chứa các kiểu hình học khác nhau
typedef union Shape {
    float radius;       // Đối với hình tròn (circle)
    struct {            // Đối với hình chữ nhật (rectangle)
        float width;
        float height;
    } rectangle;
} Shape;

// Hàm tính diện tích của hình học
float area_of_shape(Shape shape, int is_circle);

#endif // SHAPE_H
