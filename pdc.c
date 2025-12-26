#include <stdio.h>
#include <stdlib.h>

int main() {
    int i = 5, a, b;

    // Pre-increment
    a = ++i;  // i is incremented first, then assigned
    printf("Pre-increment: i = %d, a = %d\n", i, a);

    // Reset i
    i = 5;

    // Post-increment
    b = i++;  // i is assigned first, then incremented
    printf("Post-increment: i = %d, b = %d\n", i, b);

    // Print MAC address (Windows VS Studio terminal)
    printf("\nYour MAC Address:\n");
    system("getmac");

    return 0;
}