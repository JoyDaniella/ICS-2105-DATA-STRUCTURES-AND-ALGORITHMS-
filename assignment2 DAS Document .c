#ONGA'RE JOY ACHIENG DANIELLA -SCT222-0157/2023
#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int data;
    struct DNode* next;
    struct DNode* prev;
} DNode;

// Function to create a new doubly linked list node
DNode* createDNode(int data) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to append a node to a doubly linked list
void append(DNode** head, int data) {
    DNode* newNode = createDNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    DNode* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to print a doubly linked list
void printDList(DNode* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to reverse a doubly linked list
DNode* reverse(DNode* head) {
    DNode* temp = NULL;
    DNode* current = head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        head = temp->prev;
    }
    return head;
}

// Function to add two numbers represented as doubly linked lists
DNode* addNumbers(DNode* list1, DNode* list2) {
    list1 = reverse(list1);
    list2 = reverse(list2);

    DNode* result = NULL;
    int carry = 0;

    while (list1 != NULL || list2 != NULL || carry != 0) {
        int sum = carry;
        if (list1 != NULL) {
            sum += list1->data;
            list1 = list1->next;
        }
        if (list2 != NULL) {
            sum += list2->data;
            list2 = list2->next;
        }
        append(&result, sum % 10);
        carry = sum / 10;
    }

    result = reverse(result);
    return result;
}

int main() {
    DNode* list1 = NULL;
    DNode* list2 = NULL;

    // Example input
    append(&list1, 2);
    append(&list1, 5);
    append(&list1, 9);
    append(&list2, 3);
    append(&list2, 8);
    append(&list2, 1);

    printf("List 1: ");
    printDList(list1);
    printf("List 2: ");
    printDList(list2);

    DNode* sumList = addNumbers(list1, list2);
    printf("Sum stored in a doubly linked list: ");
    printDList(sumList);

    return 0;
}
