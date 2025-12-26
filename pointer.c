#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 42;
    int *ptr = &x;

    // Print pointer details
    printf("Value of x: %d\n", x);
    printf("Address stored in ptr: %p\n", (void*)ptr);
    printf("Address of ptr itself: %p\n", (void*)&ptr);

    // Print MAC address using system command
    // On Windows (VS Studio terminal), "getmac" works
    printf("\nYour MAC Address:\n");
    system("getmac");

    return 0;
}