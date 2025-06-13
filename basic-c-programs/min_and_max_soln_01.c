// Solution #1
// Using gets() and atoi() to read integers from input until "done" is entered
#include <stdio.h>

int main() {
    int first = 1;
    char str[1000];
    int maxval, minval;

    while (gets(str) != NULL) {
        // Check for "done"
        if (str[0] == 'd' && str[1] == 'o' && str[2] == 'n' &&
            str[3] == 'e' && str[4] == '\0') {
            break;
        }

        int val = atoi(str);  // Convert input string to int

        if (first || val > maxval) maxval = val;
        if (first || val < minval) minval = val;
        first = 0;
    }

    if (!first) {
        printf("Maximum %d\n", maxval);
        printf("Minimum %d\n", minval);
    } else {
        printf("No numbers were entered.\n");
    }

    return 0;
}
