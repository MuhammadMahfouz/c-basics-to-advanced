#include <stdio.h>  

int main()  // Main function: program execution starts here
{
    int c, nl, s;  // c  - to store each character input
                   // nl - to count number of newlines
                   // s  - to count number of spaces
                   

    nl = 0;  // Initialize newline counter to 0
    s = 0;   // Initialize space counter to 0

    // Read input character by character until End Of File (EOF)
    while ((c = getchar()) != EOF) {
        if (c == '\n') {  // If the character is a newline
            nl++;         // Increment newline counter
        }
        if (c == ' ') {   // If the character is a space
            s++;          // Increment space counter
        }
    }

    // Print the counts of spaces and newlines
    printf("%d %d\n", s, nl);  // Output format: [spaces] [newlines]
}
