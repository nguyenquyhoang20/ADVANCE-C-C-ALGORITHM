#ifndef QUEUE_H
#define QUEUE_H

// Khai báo cấu trúc Queue
typedef struct Queue {
    int* items;
    int size;  // Kích thước tối đa của hàng đợi.
    int front, rear;  // front: Chỉ số của phần tử đầu tiên, rear: Chỉ số của phần tử cuối cùng.
} Queue;

// Các hàm thao tác với Queue
void initialize(Queue *queue, int size);  // Khởi tạo hàng đợi
int is_empty(Queue queue);  // Kiểm tra hàng đợi có rỗng không
int is_full(Queue queue);  // Kiểm tra hàng đợi có đầy không
void enqueue(Queue *queue, int value);  // Thêm phần tử vào hàng đợi
int dequeue(Queue *queue);  // Lấy phần tử đầu tiên từ hàng đợi
int front(Queue queue);  // Lấy phần tử đầu tiên trong hàng đợi
int rear(Queue queue);  // Lấy phần tử cuối cùng trong hàng đợi

#endif // QUEUE_H
