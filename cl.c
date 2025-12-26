#include <stdio.h>
#include <stdlib.h>

// Define node
struct Node {
    int data;
    struct Node *next;
};

// Function to traverse circular linked list
void traverse(struct Node *head) {
    if (head == NULL) return;
    struct Node *temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// Insert at end
void insertEnd(struct Node **head, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}

// Delete a node by value
void deleteNode(struct Node **head, int value) {
    if (*head == NULL) return;

    struct Node *curr = *head, *prev = NULL;

    // If head node is to be deleted
    if (curr->data == value) {
        // Find last node
        struct Node *last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        if (curr->next == *head) { // Only one node
            free(curr);
            *head = NULL;
            return;
        }
        last->next = curr->next;
        *head = curr->next;
        free(curr);
        return;
    }

    // Search for node
    do {
        prev = curr;
        curr = curr->next;
        if (curr->data == value) {
            prev->next = curr->next;
            free(curr);
            return;
        }
    } while (curr != *head);
}

int main() {
    struct Node *head = NULL;

    // Insert nodes
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);

    traverse(head);

    // Delete a node
    deleteNode(&head, 20);
    traverse(head);

    // Print MAC address (Windows VS Studio terminal)
    printf("\nYour MAC Address:\n");
    system("getmac");

    return 0;
}