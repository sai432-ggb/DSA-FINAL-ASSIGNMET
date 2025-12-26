#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Linked list node
struct Node {
    int data;
    struct Node *next;
};

// Insert at beginning of linked list
void insertLinked(struct Node **head, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Delete at beginning of linked list
void deleteLinked(struct Node **head) {
    if (*head == NULL) return;
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

int main() {
    int n = 100000; // number of elements
    int *arr = (int*)malloc(n * sizeof(int));
    struct Node *head = NULL;

    clock_t start, end;
    double cpu_time_used;

    // ---------------- ARRAY INSERTION ----------------
    start = clock();
    for (int i = 0; i < n; i++) {
        // Insert at beginning (shift elements right)
        for (int j = i; j > 0; j--) {
            arr[j] = arr[j-1];
        }
        arr[0] = i;
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time for Array Insertion at beginning: %f seconds\n", cpu_time_used);

    // ---------------- LINKED LIST INSERTION ----------------
    start = clock();
    for (int i = 0; i < n; i++) {
        insertLinked(&head, i);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time for Linked List Insertion at beginning: %f seconds\n", cpu_time_used);

    // ---------------- ARRAY DELETION ----------------
    start = clock();
    for (int i = n; i > 0; i--) {
        // Delete at beginning (shift elements left)
        for (int j = 0; j < i-1; j++) {
            arr[j] = arr[j+1];
        }
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time for Array Deletion at beginning: %f seconds\n", cpu_time_used);

    // ---------------- LINKED LIST DELETION ----------------
    start = clock();
    while (head != NULL) {
        deleteLinked(&head);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time for Linked List Deletion at beginning: %f seconds\n", cpu_time_used);

    // Print MAC address (Windows VS Studio terminal)
    printf("\nYour MAC Address:\n");
    system("getmac");

    free(arr);
    return 0;
}