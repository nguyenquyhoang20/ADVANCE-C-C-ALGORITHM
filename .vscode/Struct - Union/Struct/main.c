#include <stdio.h>
#include <math.h>
#include "vector.h"

// Hàm khởi tạo vector với 2 giá trị x và y
void initialize_vector(Vector* v, float x, float y) {
    v->x = x;
    v->y = y;
}

// Hàm cộng 2 vector
Vector add_vectors(Vector v1, Vector v2) {
    Vector result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    return result;
}

// Hàm trừ 2 vector
Vector subtract_vectors(Vector v1, Vector v2) {
    Vector result;
    result.x = v1.x - v2.x;
    result.y = v1.y - v2.y;
    return result;
}

// Hàm nhân vector với một hằng số
Vector multiply_vector_by_scalar(Vector v, float scalar) {
    Vector result;
    result.x = v.x * scalar;
    result.y = v.y * scalar;
    return result;
}

// Hàm tính độ dài (magnitude) của vector
float magnitude(Vector v) {
    return sqrt(v.x * v.x + v.y * v.y);
}


int main() {
    Vector v1, v2, result;

    // Khởi tạo 2 vector
    initialize_vector(&v1, 3.0f, 4.0f);  // Vector v1 = (3, 4)
    initialize_vector(&v2, 1.0f, 2.0f);  // Vector v2 = (1, 2)

    // Cộng 2 vector
    result = add_vectors(v1, v2);
    printf("v1 + v2 = (%.2f, %.2f)\n", result.x, result.y);

    // Trừ 2 vector
    result = subtract_vectors(v1, v2);
    printf("v1 - v2 = (%.2f, %.2f)\n", result.x, result.y);

    // Nhân vector với một hằng số
    result = multiply_vector_by_scalar(v1, 2.5f);
    printf("v1 * 2.5 = (%.2f, %.2f)\n", result.x, result.y);

    // Tính độ dài của vector
    printf("Magnitude of v1 = %.2f\n", magnitude(v1));

    return 0;
}