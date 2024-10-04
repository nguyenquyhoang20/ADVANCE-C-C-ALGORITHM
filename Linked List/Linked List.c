#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Thư viện để sử dụng kiểu dữ liệu bool

typedef struct node
{
    int value;   // Dữ liệu mà node chứa
    struct node* next;   // Con trỏ trỏ tới node tiếp theo

}node;

// Hàm tạo một node mới
node* createNode(int value)  
{
    node* ptr = (node*)malloc(sizeof(node));  // Cấp phát bộ nhớ cho node mới

    ptr->value = value; // gán giá trị cho ptr
    ptr->next = NULL;  // Vì node mới chưa nối vào danh sách nên ptr là NULL
    return ptr;
}


void push_back(node** array, int value)
{
    node* temp;
    temp = createNode(value); // khoi tao node
                              // temp = 0xa1

    
    if (*array == NULL)   // if array doesn't have any node yet
    {

        *array = temp;
    }
    else                // if array has some node
    {
        node* p = *array;          // use p instead of array because we are using pointer, use array will change the structure of linkedlist
        while (p->next != NULL) // which mean the current node is not the last node
        {
            p = p->next;    // check next node until it a last node

        }

        p->next = temp;     // change it next member point to address of new node have just create
    }
}


// hàm thêm node bất kì
void insert(node **array, int value, int pos) {
    // Tạo node mới
    node* ptr = createNode(value);  // Khởi tạo node mới chứa giá trị 5
    
    if (pos == 0) {
        // Thêm vào đầu danh sách
        ptr->next = *array; // Liên kết node mới với node đầu tiên hiện tại
        *array = ptr;       // Cập nhật đầu danh sách
        return;
    }

    // Duyệt đến vị trí cần chèn
    node* current = *array;
    for (int i = 0; i < pos - 1; i++) {
        if (current == NULL) { // Nếu đến cuối danh sách mà chưa đến vị trí
            printf("Error: Position is out of bounds.\n");
            free(ptr); // Giải phóng bộ nhớ của node mới
            return;
        }
        current = current->next; // Chuyển đến node tiếp theo
    }

    // Chèn node mới vào vị trí
    ptr->next = current->next; // Liên kết node mới với node tiếp theo
    current->next = ptr;        // Cập nhật node hiện tại để trỏ đến node mới
}


// hàm xóa node bất kỳ
void delete_list(node **array, int pos) {
    if (*array == NULL) { // Kiểm tra nếu danh sách trống
        printf("Error: List is empty. Nothing to delete.\n");
        return;
    }

    node* current = *array; // Trỏ đến node đầu tiên
    node* temp; // Biến để lưu node cần xóa

    if (pos == 0) { // Nếu xóa node đầu tiên
        temp = *array; // Lưu trữ node đầu tiên
        *array = (*array)->next; // Cập nhật con trỏ đầu danh sách
        free(temp); // Giải phóng bộ nhớ của node đầu tiên
        return;
    }

    // Duyệt đến vị trí cần xóa
    for (int i = 0; i < pos - 1; i++) {
        if (current == NULL || current->next == NULL) { // Nếu đến cuối danh sách mà chưa đến vị trí
            printf("Error: Position is out of bounds.\n");
            return;
        }
        current = current->next; // Chuyển đến node tiếp theo
    }

    // Xóa node tại vị trí pos
    temp = current->next; // Lưu trữ node cần xóa
    if (temp == NULL) { // Nếu không có node tiếp theo (đến cuối danh sách)
        printf("Error: Position is out of bounds.\n");
        return;
    }
    current->next = temp->next; // Cập nhật con trỏ của node hiện tại để bỏ qua node cần xóa
    free(temp); // Giải phóng bộ nhớ của node cần xóa
}




void push_front(node** array, int value)
{
    node* temp = createNode(value);   // khởi tạo node mới
    
    temp->next = *array;              // liên kết node mới với node đầu tiên hiện tại
    *array = temp;                    // gán node mới làm node đầu tiên
}


void pop_back(node** array)
{
    node* p, * temp;
    p = *array;
    int i = 0; // to 

    while (p->next->next != NULL)     // free the last node in the list
    {
        p = p->next;
        i++;
    }
    temp = p->next;
    p->next = NULL;
    free(temp);

}



void pop_front(node** array)
{
    if (*array == NULL) // Nếu danh sách trống
    {
        printf("List is empty. Nothing to pop.\n");
        return;
    }

    node* temp = *array;   // Trỏ đến node đầu tiên
    *array = (*array)->next; // Cập nhật con trỏ đầu trỏ đến node tiếp theo
    free(temp);            // Giải phóng node đầu tiên
}




int get(node* array, int pos)
{
    int i = 0;
 
    while (array->next != NULL && pos != i)
    {
        array = array->next;
        i++;
    }

    if (pos != i)
    {
        printf("Error: List has less element\n");
        return 0;
    }

    int value = array->value;
    return value;
}

// Hàm lấy giá trị của node đầu tiên
int front(node *array)
{
    if (array == NULL) // Kiểm tra nếu danh sách trống
    {
        printf("Error: List is empty. Cannot retrieve front value.\n");
        return -1; // Trả về giá trị không hợp lệ
    }

    return array->value; // Trả về giá trị của node đầu tiên
}


// Hàm lấy giá trị của node cuối cùng
int back(node *array)
{
    if (array == NULL) // Kiểm tra nếu danh sách trống
    {
        printf("Error: List is empty. Cannot retrieve back value.\n");
        return -1; // Trả về giá trị không hợp lệ
    }

    // Duyệt đến node cuối cùng
    while (array->next != NULL)
    {
        array = array->next;
    }

    return array->value; // Trả về giá trị của node cuối cùng
}



// Hàm tính kích thước của danh sách
int size(node *array) {
    int count = 0; // Khởi tạo biến đếm
    while (array != NULL) { // Duyệt qua từng node
        count++; // Tăng biến đếm
        array = array->next; // Chuyển đến node tiếp theo
    }
    return count; // Trả về kích thước
}


// hàm kiểm tra node có rỗng hay ko
bool empty(node *array) {
    return array == NULL; // Trả về true nếu danh sách rỗng
}


int main()
{
    node* arr = NULL;
    
    // Thêm các phần tử vào cuối danh sách
    push_back(&arr, 2);
    push_back(&arr, 7);
    push_back(&arr, 4);
    push_back(&arr, 5);
    push_back(&arr, 3);
    push_back(&arr, 10);
    push_back(&arr, 13);
    push_back(&arr, 15);
    push_back(&arr, 17);
    push_back(&arr, 20);
    push_back(&arr, 22);


// Thêm phần tử vào một vị trí cụ thể
    insert(&arr, 9, 2); // Thêm giá trị 9 vào vị trí 2
    insert(&arr, 15, 4);

    // Xóa node tại vị trí 6
    delete_list(&arr, 9);

    // Lấy kích thước của danh sách
    int listSize = size(arr);
    printf("Size of the list: %d\n", listSize);
    

    // Thêm phần tử vào đầu danh sách
    push_front(&arr, 12);
    push_front(&arr, 8);


    pop_front(&arr); // Xóa node đầu tiên

     // Lấy giá trị của node đầu tiên
    int firstValue = front(arr);
    if (firstValue != -1) // Kiểm tra nếu không có lỗi
{
        printf("First value: %d\n", firstValue);
    }
//  // Lấy giá trị của node cuối cùng
//     int lastValue = back(arr);
//     if (lastValue != -1) // Kiểm tra nếu không có lỗi
    
//         printf("Last value: %d\n", lastValue);


// Kiểm tra lại xem danh sách có rỗng hay không
    if (empty(arr)) {
        printf("The list is empty.\n");
    } else {
        printf("The list is not empty.\n");
    }
    
    
   
    printf("Value test: %d\n", get(arr, 2));
    printf("Value test: %d\n", get(arr, 0));
    printf("Value test: %d\n", get(arr, 5));


	return 0;
}

