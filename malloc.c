#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
void get_mac() { printf("\nDevice MAC Address: "); system("getmac"); } 
int main() { 
int *ptr = (int*)malloc(5 * sizeof(int)); 
memset(ptr, 0, 5 * sizeof(int)); // Initializing to 0 
printf("Malloc initialized to zero: "); 
for(int i=0; i<5; i++) printf("%d ", ptr[i]); 
get_mac(); 
return 0; 
}