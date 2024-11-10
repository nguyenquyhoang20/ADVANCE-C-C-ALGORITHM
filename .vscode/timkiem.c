#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    int age;
    char address[100];
    char phone[20];
    struct Node *next;
} Node;

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

// Hàm in danh sách
void print_list(Node *head) {
    while (head != NULL) {
        printf("Họ và tên: %s, Tuổi: %d, Địa chỉ: %s, SĐT: %s\n",
               head->name, head->age, head->address, head->phone);
        head = head->next;
    }
}

// Hàm tìm kiếm theo tên
Node* search_by_name(Node *head, const char *name) {
    while (head != NULL) {
        if (strcmp(head->name, name) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Hàm tìm kiếm theo tuổi
Node* search_by_age(Node *head, int age) {
    while (head != NULL) {
        if (head->age == age) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Hàm tìm kiếm theo số điện thoại
Node* search_by_phone(Node *head, const char *phone) {
    while (head != NULL) {
        if (strcmp(head->phone, phone) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Hàm hiển thị menu
void showMenu(Node *head) {
    int choice;
    char name[50], phone[20];
    int age;
    Node *result;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Hiển thị toàn bộ danh sách\n");
        printf("2. Tìm kiếm theo tên\n");
        printf("3. Tìm kiếm theo tuổi\n");
        printf("4. Tìm kiếm theo số điện thoại\n");
        printf("5. Thoát\n");
        printf("Chọn lựa của bạn: ");
        scanf("%d", &choice);
        getchar(); // Xóa ký tự newline sau khi nhập

        switch (choice) {
            case 1:
                print_list(head);
                break;
            case 2:
                printf("Nhập tên để tìm: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Xóa ký tự newline
                result = search_by_name(head, name);
                if (result != NULL) {
                    printf("Tìm thấy: Họ và tên: %s, Tuổi: %d, Địa chỉ: %s, SĐT: %s\n",
                           result->name, result->age, result->address, result->phone);
                } else {
                    printf("Không tìm thấy tên %s\n", name);
                }
                break;
            case 3:
                printf("Nhập tuổi để tìm: ");
                scanf("%d", &age);
                result = search_by_age(head, age);
                if (result != NULL) {
                    printf("Tìm thấy: Họ và tên: %s, Tuổi: %d, Địa chỉ: %s, SĐT: %s\n",
                           result->name, result->age, result->address, result->phone);
                } else {
                    printf("Không tìm thấy tuổi %d\n", age);
                }
                break;
            case 4:
                printf("Nhập số điện thoại để tìm: ");
                
                fgets(phone, sizeof(phone), stdin);
                phone[strcspn(phone, "\n")] = 0; // Xóa ký tự newline
                result = search_by_phone(head, phone);
                if (result != NULL) {
                    printf("Tìm thấy: Họ và tên: %s, Tuổi: %d, Địa chỉ: %s, SĐT: %s\n",
                           result->name, result->age, result->address, result->phone);
                } else {
                    printf("Không tìm thấy số điện thoại %s\n", phone);
                }
                break;
            case 5:
                printf("Thoát chương trình.\n");
                break;
            default:
                printf("Lựa chọn không hợp lệ, vui lòng chọn lại.\n");
        }
    } while (choice != 5);
}

int main() {
    Node *head = NULL;
    readCSV(&head, "thongtin.csv"); // Đọc dữ liệu từ file thongtin.csv

    if (head != NULL) {
        showMenu(head); // Hiển thị menu lựa chọn
    } else {
        printf("Danh sách trống.\n");
    }

    return 0;
}
