// node.h

#ifndef NODE_H
#define NODE_H

typedef struct Node {
    char name[50];
    int age;
    char address[100];
    char phone[20];
    struct Node *next;
} Node;

void add_node(Node **head, char *name, int age, char *address, char *phone);
Node** linked_list_to_array(Node *head, int *size);
Node* binary_search_by_name(Node **array, int size, const char *name);
int compare_by_phone(const void *a, const void *b);
Node* binary_search_by_phone(Node **array, int size, const char *phone);
void readCSV(Node **head, const char *filename);
void print_array(Node **array, int size);
void showMenu(Node *head);

#endif
