#include <stdio.h>

char string[50], final[50];
int max_sep = 5;

int main() {
    int i = 0, j = 0, count1 = 0, checkones = 0;
    printf("Enter the Message (binary): ");
    // Input the message
    scanf("%s", string);
    // Loop over the string
    while (string[i] != '\0') {
        // checkones acts like a boolean value, we check for 5 consecutive 1s
        if (checkones)
            if (string[i] == '1')
                count1++;
        // checkones is "set" by a 0, as the flag is 01111110
        if (string[i] == '0') {
            checkones = 1;
            // Reset count, it's important
            // As there can be 0s between 1s
            count1 = 0;
        }
        // We append the character as it is
        final[j++] = string[i];
        // But if we encounter 5 consecutive 1s after a 0, append a 0
        if (count1 == max_sep) {
            // Printing the position after which a '0' is stuffed
            printf("Inserting '0' after %dth character\n", i);
            final[j++] = '0';
            // Reset count, and check ones boolean
            count1 = 0;
            checkones = 0;
        }
        i++;
    }
    printf("Final String(without flags): %s\n", final);
    return 0;
}