#include <stdio.h>
#include <string.h>

char string[50], final[50];
int max_sep = 5;

int main() {
    int i = 0, j = 0, count1 = 0, checkones = 0;
    printf("Enter the Message (binary): ");
    gets(string);
    // strcat(final, "01111110");
    while (string[i] != '\0') {
        if (checkones)
            if (string[i] == '1')
                count1++;
        if (string[i] == '0') {
            checkones = 1;
        }
        final[j++] = string[i];
        if (count1 == max_sep) {
            count1 = 0;
            checkones = 0;
            printf("Inserting '0' at %d\n", j);
            final[j++] = '0';
        }
        i++;
    }
    // strcat(final, "01111110");
    printf("Final String(without flags): ");
    puts(final);
}