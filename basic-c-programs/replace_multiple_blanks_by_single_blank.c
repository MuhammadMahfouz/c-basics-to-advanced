#include <stdio.h>

int main() {
    int c;
    int blank = 0;    // Flag to track if the last character was a blank
    
    while((c = getchar()) != EOF){
        if (c == ' ') {
            if (blank == 0){  // Check if the last character was not a blank
                putchar(c); // Output a single blank
                blank = 1;  // Set the flag to indicate the last character was a blank
        }
    }
        else {
            putchar(c); // Output the current character
            blank = 0;  // Reset the flag since the current character is not a blank
        }
        
    }
}