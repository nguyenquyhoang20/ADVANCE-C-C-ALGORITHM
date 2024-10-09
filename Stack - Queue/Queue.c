#include <stdio.h>
#include <stdlib.h>


typedef struct Queue {
    int* items;
    int size;  //Kích thước tối đa của hàng đợi.
    int front, rear;        //front: Chỉ số của phần tử đầu tiên trong hàng đợi.
                            //rear: Chỉ số của phần tử cuối cùng trong hàng đợi.
} Queue;
// Ban đầu, front và rear đều được khởi tạo là -1 để biểu thị hàng đợi rỗng.
void initialize(Queue *queue, int size) //Khởi tạo hàng đợi
{
    queue->items = (int*) malloc(sizeof(int)* size);// Cấp phát bộ nhớ cho hàng đợi với kích thước là `size`
    queue->front = -1;  // Khởi tạo chỉ số `front` và `rear` là -1.
    queue->rear = -1;
    queue->size = size;  // Gán kích thước của hàng đợi.
}
// hàm kiểm tra hàng đợi 
int is_empty(Queue queue) {
    return queue.front == -1; // Nếu front là -1, hàng đợi đang rỗng.
}
// Hàm is_full() - Kiểm tra hàng đợi đầy
int is_full(Queue queue) {
    return (queue.rear + 1) % queue.size == queue.front;
}

// Hàm enqueue() - Thêm phần tử vào cuối hàng đợi
void enqueue(Queue *queue, int value) {
    if (!is_full(*queue)) {
        if (is_empty(*queue)) {
            queue->front = queue->rear = 0;// Nếu hàng đợi rỗng, cập nhật cả front và rear về 0.
        } else {
            queue->rear = (queue->rear + 1) % queue->size;// Di chuyển rear theo vòng tròn.

        }
        queue->items[queue->rear] = value; // Thêm phần tử vào vị trí rear.
    } else {
        printf("Queue overflow\n"); // Nếu hàng đợi đầy, thông báo lỗi.
    }
}

int dequeue(Queue *queue) {
    if (!is_empty(*queue)) {
        int dequeued_value = queue->items[queue->front]; // Lấy giá trị của phần tử đầu tiên.
        if (queue->front == queue->rear) {   // Nếu chỉ có một phần tử trong hàng đợi.
            queue->front = queue->rear = -1; // Đặt hàng đợi về trạng thái rỗng.
        } else {
            queue->front = (queue->front + 1) % queue->size; // Di chuyển front theo vòng tròn
        }
        return dequeued_value;
    } else {
        printf("Queue underflow\n"); // Nếu hàng đợi rỗng, thông báo lỗi.
        return -1;
    }
}
// Hàm front() - Lấy giá trị của phần tử đầu tiên
int front(Queue queue) {
    if (!is_empty(queue)) {
        return queue.items[queue.front];
    } else {
        printf("Queue is empty\n");
        return -1;
    }
}

// hàm rear  Lấy giá trị của phần tử cuối cùng trong hàng đợi
int rear(Queue queue) {
    if (!is_empty(queue)) {
        return queue.items[queue.rear];
    }else{
        printf("Queue is empty.\n");
        return -1;
    }
}
    

int main() {
    Queue queue;
    initialize(&queue, 3);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Front element: %d\n", front(queue));

    printf("Dequeue element: %d\n", dequeue(&queue));
    printf("Dequeue element: %d\n", dequeue(&queue));

    printf("Front element: %d\n", front(queue));

    enqueue(&queue, 40);
    enqueue(&queue, 50);
    printf("Dequeue element: %d\n", dequeue(&queue));
    printf("Front element: %d\n", front(queue));
    printf("Rear: %d\n", rear(queue));  

    return 0;
}
