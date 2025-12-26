#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;

    // Using malloc
    int *arr1 = (int*)malloc(n * sizeof(int));
    printf("Values in malloc array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr1[i]);  // Junk values (uninitialized)
    }
    printf("\n");

    // Using calloc
    int *arr2 = (int*)calloc(n, sizeof(int));
    printf("Values in calloc array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr2[i]);  // All zeros
    }
    printf("\n");

    // Print MAC address (Windows VS Studio terminal)
    printf("\nYour MAC Address:\n");
    system("getmac");

    free(arr1);
    free(arr2);

    return 0;
}