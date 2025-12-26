#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix[10][10]; // static matrix for simplicity
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Count non-zero elements
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                count++;
            }
        }
    }

    // Sparse matrix representation: [row, col, value]
    int **sparse = (int **)malloc((count + 1) * sizeof(int *));
    for (int i = 0; i <= count; i++) {
        sparse[i] = (int *)malloc(3 * sizeof(int));
    }
    
    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = count;

    int k = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    // Print sparse matrix
    printf("\nSparse Matrix Representation (row col value):\n");
    for (int i = 0; i <= count; i++) {
        printf("%d %d %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }

    // Free allocated memory
    for (int i = 0; i <= count; i++) {
        free(sparse[i]);
    }
    free(sparse);

    // Print MAC address (Windows VS Studio terminal)
    printf("\nYour MAC Address:\n");
    system("getmac");

    return 0;
}