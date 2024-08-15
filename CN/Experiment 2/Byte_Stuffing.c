#include <stdio.h>

char string[50], final[300], start, end, flag;

int main() {
    int i = 0, j = 0;
    printf("Enter the message: ");
    scanf("%s", string);
    printf("\nEnter the Start Flag: ");
    // The \n%c is because, to end previous output, newline character is entered
    // (enter key is pressed) hence, We need to consume(read/scan) it
    scanf("\n%c", &start);
    printf("\nEnter the End Flag: ");
    scanf("\n%c", &end);
    printf("\nEnter the Escape Flag: ");
    scanf("\n%c", &flag);
    // Append the start character
    final[j++] = start;
    while (string[i] != '\0') {
        // Check if the string contains either of start, end or flag character
        if (string[i] == start || string[i] == end || string[i] == flag) {
            // If there is any, pre-append by flag character
            final[j++] = flag;
        }
        // Append the character in the final string
        final[j++] = string[i];
        i++;
    }
    // Append the ending character, and subsequently, terminate the string
    final[j++] = end;
    final[j] = '\0';
    printf("%s\n", final);
    return 0;
}