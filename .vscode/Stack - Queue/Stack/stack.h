#ifndef STACK_H
#define STACK_H

typedef struct Stack {
    int* items;  // Mảng động để lưu các phần tử trong stack
    int size;    // Kích thước stack (kích thước tối đa)
    int top;     // Vị trí của phần tử ở đỉnh stack
} Stack;

// Hàm khởi tạo stack
void initialize(Stack* stack, int size);

// Kiểm tra stack có rỗng không
int is_empty(Stack stack);

// Kiểm tra stack đã đầy chưa
int is_full(Stack stack);

// Thêm phần tử vào stack
void push(Stack* stack, int value);

// Lấy phần tử ra khỏi stack
int pop(Stack* stack);

// Lấy phần tử ở đỉnh stack
int top(Stack stack);

#endif // STACK_H
