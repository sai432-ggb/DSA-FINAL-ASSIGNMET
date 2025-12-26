#include <stdio.h>
#include <stdlib.h>

// Define node
struct Node {
    int data;
    struct Node *next;
};

// Function to traverse linked list
void traverse(struct Node *head) {
    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert at a given position (middle)
void insertAtPos(struct Node **head, int value, int pos) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (pos == 1) { // insert at beginning
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    for (int i = 1; temp != NULL && i < pos-1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete at a given position (middle)
void deleteAtPos(struct Node **head, int pos) {
    if (*head == NULL) return;

    struct Node *temp = *head;

    if (pos == 1) { // delete head
        *head = temp->next;
        free(temp);
        return;
    }

    struct Node *prev = NULL;
    for (int i = 1; temp != NULL && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int main() {
    struct Node *head = NULL;

    // Create initial list: 10 -> 20 -> 30
    insertAtPos(&head, 10, 1);
    insertAtPos(&head, 20, 2);
    insertAtPos(&head, 30, 3);
    traverse(head);

    // Insert 15 at position 2
    insertAtPos(&head, 15, 2);
    traverse(head);

    // Delete node at position 3
    deleteAtPos(&head, 3);
    traverse(head);

    // Print MAC address (Windows VS Studio terminal)
    printf("\nYour MAC Address:\n");
    system("getmac");

    return 0;
}