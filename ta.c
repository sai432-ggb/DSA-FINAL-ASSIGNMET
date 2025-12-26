#include <stdio.h>
#include <stdlib.h>

#define MAX 15  // maximum number of nodes

// Function to print tree in array form
void printTree(int tree[], int n) {
    printf("Tree (Array Representation):\n");
    for (int i = 0; i < n; i++) {
        printf("Index %d -> %d\n", i, tree[i]);
    }
}

// Function to traverse tree (inorder)
void inorder(int tree[], int index, int n) {
    if (index >= n || tree[index] == -1) return;

    // Left child
    inorder(tree, 2*index + 1, n);

    // Root
    printf("%d ", tree[index]);

    // Right child
    inorder(tree, 2*index + 2, n);
}

int main() {
    int tree[MAX];
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d node values (use -1 for NULL):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tree[i]);
    }

    // Print array representation
    printTree(tree, n);

    // Inorder traversal
    printf("\nInorder Traversal of Tree: ");
    inorder(tree, 0, n);
    printf("\n");

    // Print MAC address (Windows VS Studio terminal)
    printf("\nYour MAC Address:\n");
    system("getmac");

    return 0;
}