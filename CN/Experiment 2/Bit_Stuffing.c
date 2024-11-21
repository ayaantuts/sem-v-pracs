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
        if (string[i] == '1')
            count1++;
        else
            count1 = 0;
        final[j++] = string[i];
        // But if we encounter 5 consecutive 1s, append a 0
        if (count1 == max_sep) {
            // Printing the position after which a '0' is stuffed
            printf("Inserting '0' after %dth character\n", i + 1);
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