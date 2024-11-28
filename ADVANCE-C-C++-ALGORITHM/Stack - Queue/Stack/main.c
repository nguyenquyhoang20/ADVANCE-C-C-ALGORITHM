#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Hàm khởi tạo stack
void initialize(Stack* stack, int size) {
    stack->items = (int*) malloc(sizeof(int) * size); // Cấp phát bộ nhớ cho stack
    stack->size = size;  // Gán kích thước cho stack
    stack->top = -1;     // Gán cho stack bằng -1 vì đang rỗng 
}

// Kiểm tra stack có rỗng không
int is_empty(Stack stack) {
    return stack.top == -1;
}

// Kiểm tra stack đã đầy chưa
int is_full(Stack stack) {
    return stack.top == stack.size - 1; // Hàm is_full trả về 1 nếu stack đầy (tức là top == size - 1)
}

// Thêm phần tử vào stack
void push(Stack* stack, int value) {
    if (!is_full(*stack)) { // Kiểm tra xem stack đã đầy chưa
        stack->items[++stack->top] = value; // Thêm phần tử vào và tăng top
    } else {
        printf("Stack overflow\n"); // Thông báo nếu stack đầy
    }
}

// Lấy phần tử ra khỏi stack (pop)
int pop(Stack* stack) {
    if (!is_empty(*stack)) { // Kiểm tra xem stack có rỗng không
        return stack->items[stack->top--]; // Trả về phần tử ở đỉnh stack và giảm top
    } else {
        printf("Stack underflow\n"); // Thông báo nếu stack rỗng
        return -1;
    }
}

// Lấy phần tử ở đỉnh stack
int top(Stack stack) {
    if (!is_empty(stack)) {
        return stack.items[stack.top]; // Lấy phần tử ở đỉnh stack
    } else {
        printf("Stack is empty\n");
        return -1;
    }
}
int main() {
    Stack stack1;
    initialize(&stack1, 5);  // Khởi tạo stack với kích thước 5

    // Thêm phần tử vào stack
    push(&stack1, 10);
    push(&stack1, 20);
    push(&stack1, 30);
    push(&stack1, 40);
    push(&stack1, 50);

    // Thử thêm phần tử khi stack đã đầy
    push(&stack1, 60);

    // Lấy phần tử ở đỉnh stack
    printf("Top element: %d\n", top(stack1));

    // Lấy phần tử ra khỏi stack
    printf("Pop element: %d\n", pop(&stack1));
    printf("Pop element: %d\n", pop(&stack1));

    // Lấy phần tử ở đỉnh stack sau khi pop
    printf("Top element: %d\n", top(stack1));

    return 0;
}