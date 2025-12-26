#include <stdio.h>
#include <stdlib.h>

// Define a self-referential structure (Node)
struct Node {
    int data;
    struct Node *next;
};

// Define front and rear pointers for the queue
struct Node *front = NULL;
struct Node *rear = NULL;

// Function to check if queue is empty
int isEmpty() {
    return (front == NULL);
}

// Function to enqueue (insert at rear)
void enqueue(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Queue Overflow (Memory allocation failed)\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued to queue\n", value);
}

// Function to dequeue (remove from front)
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow!\n");
        return;
    }
    struct Node *temp = front;
    printf("%d dequeued from queue\n", temp->data);
    front = front->next;

    if (front == NULL) {
        rear = NULL; // Queue becomes empty
    }
    free(temp);
}

// Function to display queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    struct Node *temp = front;
    printf("Queue elements (Front to Rear): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();

    // Print MAC address (Windows VS Studio terminal)
    printf("\nYour MAC Address:\n");
    system("getmac");

    // Free remaining nodes
    while (!isEmpty()) {
        dequeue();
    }

    return 0;
}