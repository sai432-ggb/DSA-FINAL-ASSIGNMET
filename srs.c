#include <stdio.h>
#include <stdlib.h>

// Define a self-referential structure
struct Node {
    int data;
    struct Node *next;  // Pointer to another Node of the same type
};

int main() {
    // Create three nodes dynamically
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    struct Node *second = (struct Node*)malloc(sizeof(struct Node));
    struct Node *third = (struct Node*)malloc(sizeof(struct Node));

    // Assign data and link nodes
    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL; // End of list

    // Traverse and print linked list
    struct Node *temp = head;
    printf("Linked List:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    // Print MAC address (Windows VS Studio terminal)
    printf("\nYour MAC Address:\n");
    system("getmac");

    // Free allocated memory
    free(head);
    free(second);
    free(third);

    return 0;
}