// Solution: #02 
// use strcmp to check for "done" and atoi to convert string to integer
// and gets to read input
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int minval, maxval;
    char str[1000];
    int first = 1;
    
    while(1){
        gets(str);

        if(strcmp(str, "done") == 0) break;
        
        int val = atoi(str);
        if (first || val < minval) {
            minval = val;
        }
        if (first || val > maxval) {
            maxval = val;
        }
        first = 0;
    }
    printf("Minimum: %d\n", minval);
    printf("Maximum: %d\n", maxval);

    return 0;
}