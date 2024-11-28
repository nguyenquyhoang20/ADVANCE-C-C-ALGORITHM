#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vector {
    float x;  // Phần x của vector
    float y;  // Phần y của vector
} Vector;

// Hàm khởi tạo vector với 2 giá trị x và y
void initialize_vector(Vector* v, float x, float y);

// Hàm cộng 2 vector
Vector add_vectors(Vector v1, Vector v2);

// Hàm trừ 2 vector
Vector subtract_vectors(Vector v1, Vector v2);

// Hàm nhân vector với một hằng số
Vector multiply_vector_by_scalar(Vector v, float scalar);

// Hàm tính độ dài (magnitude) của vector
float magnitude(Vector v);

#endif // VECTOR_H
