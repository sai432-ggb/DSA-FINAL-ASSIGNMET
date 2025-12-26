#include <stdio.h>
#include <stdlib.h>

// Define a self-referential structure (Node)
struct Node {
    int data;
    struct Node *next;
};

// Function to push an element onto the stack
void push(struct Node **top, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Stack Overflow (Memory allocation failed)\n");
        return;
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed onto stack\n", value);
}

// Function to pop an element from the stack
void pop(struct Node **top) {
    if (*top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }
    struct Node *temp = *top;
    printf("%d popped from stack\n", temp->data);
    *top = temp->next;
    free(temp);
}

// Function to display stack elements
void display(struct Node *top) {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements (Top to Bottom): ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

int main() {
    struct Node *top = NULL; // Initialize empty stack

    // Perform stack operations
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    display(top);

    pop(&top);
    display(top);

    // Print MAC address (Windows VS Studio terminal)
    printf("\nYour MAC Address:\n");
    system("getmac");

    // Free remaining nodes
    while (top != NULL) {
        struct Node *temp = top;
        top = top->next;
        free(temp);
    }

    return 0;
}