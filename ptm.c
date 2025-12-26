#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to perform pattern matching (brute-force)
int patternMatch(const char text[], const char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) {
            return i; // Match found at index i
        }
    }
    return -1; // No match found
}

int main() {
    char text[100], pattern[50];

    printf("Enter the text: ");
    scanf("%99s", text);

    printf("Enter the pattern: ");
    scanf("%49s", pattern);

    int result = patternMatch(text, pattern);

    if (result != -1) {
        printf("Pattern found at index %d\n", result);
    } else {
        printf("Pattern not found\n");
    }

    // Print MAC address (Windows VS Studio terminal)
    printf("\nYour MAC Address:\n");
    system("getmac");

    return 0;
}