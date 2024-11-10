// node.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"  //lấy node.h
    
#include <locale.h>


// Hàm thêm node và sắp xếp theo tên theo thứ tự từ điển
void add_node(Node **head, char *name, int age, char *address, char *phone) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->age = age;
    strcpy(new_node->address, address);
    strcpy(new_node->phone, phone);
    new_node->next = NULL;

    if (*head == NULL || strcmp((*head)->name, name) >= 0) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    Node *current = *head;
    while (current->next != NULL && strcmp(current->next->name, name) < 0) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
}

// Hàm chuyển danh sách liên kết thành mảng
Node** linked_list_to_array(Node *head, int *size) {
    *size = 0;
    Node *current = head;

    // Đếm số lượng node trong danh sách
    while (current != NULL) {
        (*size)++;
        current = current->next;
    }

    Node **array = (Node **)malloc(*size * sizeof(Node *));
    current = head;
    for (int i = 0; i < *size; i++) {
        array[i] = current;
        current = current->next;
    }
    return array;
}

// Hàm tìm kiếm nhị phân theo tên trong mảng
Node* binary_search_by_name(Node **array, int size, const char *name) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(array[mid]->name, name);
        if (cmp == 0) {
            return array[mid]; // Tìm thấy
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return NULL; // Không tìm thấy
}

// Hàm so sánh để sắp xếp theo số điện thoại
int compare_by_phone(const void *a, const void *b) {
    Node *nodeA = *(Node **)a;
    Node *nodeB = *(Node **)b;
    return strcmp(nodeA->phone, nodeB->phone);
}

// Hàm tìm kiếm nhị phân theo số điện thoại trong mảng
Node* binary_search_by_phone(Node **array, int size, const char *phone) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(array[mid]->phone, phone);
        if (cmp == 0) {
            return array[mid]; // Tìm thấy
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return NULL; // Không tìm thấy
}

// Hàm đọc tệp CSV và xây dựng danh sách
void readCSV(Node **head, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Không thể mở tệp %s\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char name[50], address[100], phone[20];
        int age;
        sscanf(line, "%[^,],%d,%[^,],%s", name, &age, address, phone);
        add_node(head, name, age, address, phone);
    }

    fclose(file);
}

// Hàm hiển thị danh sách từ mảng
void print_array(Node **array, int size) {
    for (int i = 0; i < size; i++) {
        printf("Họ và tên: %s, Tuổi: %d, Địa chỉ: %s, SĐT: %s\n",
               array[i]->name, array[i]->age, array[i]->address, array[i]->phone);
    }
}

// Hàm hiển thị menu
void showMenu(Node *head) {
    int choice;
    char name[50];
    char phone[20];
    int size;
    Node **array;
    Node *result;

    array = linked_list_to_array(head, &size); // Chuyển danh sách liên kết thành mảng

    do {
        printf("\n--- Menu ---\n");
        printf("1. Hiển thị toàn bộ danh sách\n");
        printf("2. Tìm kiếm theo tên\n");
        printf("3. Tìm kiếm theo số điện thoại\n");
        printf("4. Thoát\n");
        printf("Chọn lựa của bạn: ");
        scanf("%d", &choice);
        getchar(); // Xóa ký tự newline sau khi nhập
        
        switch (choice) {
            case 1:
                print_array(array, size);
                break;
            case 2:
                printf("Nhập tên để tìm: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Xóa ký tự newline
                result = binary_search_by_name(array, size, name);
                if (result != NULL) {
                    printf("Tìm thấy: Họ và tên: %s, Tuổi: %d, Địa chỉ: %s, SĐT: %s\n",
                           result->name, result->age, result->address, result->phone);
                } else {
                    printf("Không tìm thấy tên %s\n", name);
                }
                break;
            case 3:
                printf("Nhập số điện thoại để tìm: ");
                fgets(phone, sizeof(phone), stdin);
                phone[strcspn(phone, "\n")] = 0; // Xóa ký tự newline
                qsort(array, size, sizeof(Node *), compare_by_phone);
                result = binary_search_by_phone(array, size, phone);
                if (result != NULL) {
                    printf("Tìm thấy: Họ và tên: %s, Tuổi: %d, Địa chỉ: %s, SĐT: %s\n",
                           result->name, result->age, result->address, result->phone);
                } else {
                    printf("Không tìm thấy số điện thoại %s\n", phone);
                }
                break;
            case 4:
                printf("Thoát chương trình.\n");
                break;
            default:
                printf("Lựa chọn không hợp lệ, vui lòng chọn lại.\n");
        }
    } while (choice != 4);

    free(array); // Giải phóng bộ nhớ của mảng
}




// main.c

int main() {
    setlocale(LC_ALL, "vi_VN.UTF-8");

    Node *head = NULL;
    readCSV(&head, "thongtin.csv"); // Đọc dữ liệu từ file thongtin.csv

    if (head != NULL) {
        showMenu(head); // Hiển thị menu lựa chọn
    } else {
        printf("Danh sách trống.\n");
    }

    return 0;
}
