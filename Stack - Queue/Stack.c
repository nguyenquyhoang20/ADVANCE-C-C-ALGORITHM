#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int* items; // Mảng động để lưu các phần tử trong stack
    int size;   // kích thước stack ( kích thước tối đa)
    int top;   // Vị trí của phần tử ở đỉnh stack
} Stack;

// Khởi tạo 
void initialize( Stack *stack, int size) {
    stack->items = (int*) malloc(sizeof(int) * size); // cấp phát bộ nhớ cho stack
    stack->size = size;  // Gán kích thước cho stack
    stack->top = -1; // gán cho stack bằng -1 vì đang rỗng 
}
// kiểm tra stack có rỗng ko
int is_empty( Stack stack) {
    return stack.top == -1;
}
// kiểm tra stack đã đầy chưa 
int is_full( Stack stack) {
     return stack.top == stack.size - 1;   // Hàm is_full trả về 1 nếu stack đầy (tức là top == size - 1), 
                                            //ngược lại trả về 0.
}

void push( Stack *stack, int value) {
    if (!is_full(*stack)) { // kiểm tra xem hàm stack đã đâyf chưa
        stack->items[++stack->top] = value;  // thêm phần tử vào và tăng kích thước
    } else {
        printf("Stack overflow\n");// thông báo phần tử đã đầy 
    } 
}


// Lấy một phần tử ra khỏi Stack (pop)
int pop( Stack *stack) {
    if (!is_empty(*stack)) { // kiểm tra xem hàm stack có rỗng ko
        return stack->items[stack->top--]; // Trả về phần tử ở đỉnh stack và giảm chỉ số top
    } else {
        printf("Stack underflow\n");  // Thông báo khi stack rỗng
        return -1;
    }
}


// lấy phần tử ở đỉnh
int top( Stack stack) {
    if (!is_empty(stack)) {
        return stack.items[stack.top];// lấy phần tư ở đỉnh
    } else {
        printf("Stack is empty\n");
        return -1;
    }
}

int main() {
    Stack stack1;
    initialize(&stack1, 5);


    push(&stack1, 10);
    push(&stack1, 20);
    push(&stack1, 30);
    push(&stack1, 40);
    push(&stack1, 50);
    push(&stack1, 60);

    printf("Top element: %d\n", top(stack1));

    printf("Pop element: %d\n", pop(&stack1));
    printf("Pop element: %d\n", pop(&stack1));

    printf("Top element: %d\n", top(stack1));

    return 0;
}


