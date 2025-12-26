#include <stdio.h>
#include <stdlib.h>

// Define a node for polynomial term
struct Node {
    int coeff;
    int pow;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term at the end
void insertTerm(struct Node **poly, int coeff, int pow) {
    struct Node *newNode = createNode(coeff, pow);
    if (*poly == NULL) {
        *poly = newNode;
        return;
    }
    struct Node *temp = *poly;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display polynomial
void displayPoly(struct Node *poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->pow);
        poly = poly->next;
        if (poly != NULL) printf(" + ");
    }
    printf("\n");
}

int main() {
    struct Node *poly = NULL;

    // Example polynomial: 5x^2 + 3x^1 + 7
    insertTerm(&poly, 5, 2);
    insertTerm(&poly, 3, 1);
    insertTerm(&poly, 7, 0);

    printf("Polynomial Representation:\n");
    displayPoly(poly);

    // Print MAC address (Windows VS Studio terminal)
    printf("\nYour MAC Address:\n");
    system("getmac");

    // Free memory
    while (poly != NULL) {
        struct Node *temp = poly;
        poly = poly->next;
        free(temp);
    }

    return 0;
}