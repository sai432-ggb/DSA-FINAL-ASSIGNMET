#include <stdio.h>
#include <string.h>
#include<stdlib.h>

int main() {
    char str1[50], str2[50];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    // Compare using built-in function strcmp
    int result = strcmp(str1, str2);

    if (result == 0) {
        printf("Strings are equal.\n");
    } else if (result < 0) {
        printf("First string is less than second string.\n");
    } else {
        printf("First string is greater than second string.\n");
    }

    // Print MAC address (Windows VS Studio terminal)
    printf("\nYour MAC Address:\n");
    system("getmac");

    return 0;
}