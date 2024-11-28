#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"  // Bao gồm header file

// Hàm khởi tạo hàng đợi
void initialize(Queue *queue, int size) {
    queue->items = (int*) malloc(sizeof(int) * size);  // Cấp phát bộ nhớ cho hàng đợi
    queue->front = -1;  // Khởi tạo front và rear là -1 (hàng đợi rỗng)
    queue->rear = -1;
    queue->size = size;  // Gán kích thước của hàng đợi
}

// Hàm kiểm tra hàng đợi có rỗng không
int is_empty(Queue queue) {
    return queue.front == -1;  // Nếu front là -1, hàng đợi rỗng
}

// Hàm kiểm tra hàng đợi có đầy không
int is_full(Queue queue) {
    return (queue.rear + 1) % queue.size == queue.front;
}

// Hàm thêm phần tử vào hàng đợi
void enqueue(Queue *queue, int value) {
    if (!is_full(*queue)) {
        if (is_empty(*queue)) {
            queue->front = queue->rear = 0;  // Nếu hàng đợi rỗng, cập nhật front và rear
        } else {
            queue->rear = (queue->rear + 1) % queue->size;  // Di chuyển rear theo vòng tròn
        }
        queue->items[queue->rear] = value;  // Thêm phần tử vào vị trí rear
    } else {
        printf("Queue overflow\n");  // Nếu hàng đợi đầy
    }
}

// Hàm lấy phần tử đầu tiên từ hàng đợi
int dequeue(Queue *queue) {
    if (!is_empty(*queue)) {
        int dequeued_value = queue->items[queue->front];  // Lấy giá trị phần tử đầu tiên
        if (queue->front == queue->rear) {  // Nếu chỉ còn một phần tử trong hàng đợi
            queue->front = queue->rear = -1;  // Đặt lại hàng đợi rỗng
        } else {
            queue->front = (queue->front + 1) % queue->size;  // Di chuyển front theo vòng tròn
        }
        return dequeued_value;
    } else {
        printf("Queue underflow\n");  // Nếu hàng đợi rỗng
        return -1;
    }
}

// Hàm lấy giá trị phần tử đầu tiên trong hàng đợi
int front(Queue queue) {
    if (!is_empty(queue)) {
        return queue.items[queue.front];
    } else {
        printf("Queue is empty\n");
        return -1;  // Nếu hàng đợi rỗng
    }
}

// Hàm lấy giá trị phần tử cuối cùng trong hàng đợi
int rear(Queue queue) {
    if (!is_empty(queue)) {
        return queue.items[queue.rear];
    } else {
        printf("Queue is empty.\n");
        return -1;  // Nếu hàng đợi rỗng
    }
}
int main() {
    Queue queue;
    initialize(&queue, 3);  // Khởi tạo hàng đợi với kích thước 3

    enqueue(&queue, 10);  // Thêm phần tử vào hàng đợi
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Front element: %d\n", front(queue));  // In ra phần tử đầu tiên trong hàng đợi

    printf("Dequeue element: %d\n", dequeue(&queue));  // Lấy phần tử đầu tiên ra khỏi hàng đợi
    printf("Dequeue element: %d\n", dequeue(&queue));

    printf("Front element: %d\n", front(queue));

    enqueue(&queue, 40);  // Thêm phần tử vào hàng đợi
    enqueue(&queue, 50);
    printf("Dequeue element: %d\n", dequeue(&queue));
    printf("Front element: %d\n", front(queue));
    printf("Rear: %d\n", rear(queue));  // In ra phần tử cuối cùng trong hàng đợi

    return 0;
}