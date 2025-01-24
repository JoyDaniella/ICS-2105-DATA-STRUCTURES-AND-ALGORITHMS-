#ONGA'RE JOY ACHIENG DANIELLA -SCT222-0157/2023
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the list
void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to merge two sorted linked lists
Node* merge(Node* list1, Node* list2) {
    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    tail->next = (list1 != NULL) ? list1 : list2;
    return dummy.next;
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;

    // Example input
    append(&list1, 1);
    append(&list1, 3);
    append(&list1, 5);
    append(&list2, 2);
    append(&list2, 4);
    append(&list2, 6);

    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    Node* mergedList = merge(list1, list2);
    printf("Merged List: ");
    printList(mergedList);

    return 0;
}
