#include <stdio.h>

// This program reads characters from standard input and prints them,
// replacing sequences of spaces and newlines with a single newline.
// It uses getchar() to read characters one by one and putchar() to print them.
// It handles multiple spaces and newlines by printing only one newline
// for each sequence of blanks or newlines, and prints other characters as they are.
// It continues until EOF (End of File) is reached.

int main() {
    int c;
    int blank = 0;  // Flag to track if we are in a blank/newline sequence

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n') {
            if (blank == 0) {
                printf("\n");   // Print a single newline for the first blank
                blank = 1;      // Set flag to indicate a blank was seen
            }
        } else {
            putchar(c);         // Print non-blank characters normally
            blank = 0;          // Reset flag
        }
    }
}
