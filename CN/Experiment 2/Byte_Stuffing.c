#include <stdio.h>
#include <string.h>

char string[50], final[50], start, end, flag;

int main() {
    int i = 0, j = 0;
    printf("Enter the message: ");
    gets(string);
    printf("\nEnter the Start Flag: ");
    scanf("%c", &start);
    printf("\nEnter the End Flag: ");
    scanf("\n%c", &end);
    printf("\nEnter the Escape Flag: ");
    scanf("\n%c", &flag);
    final[j++] = start;
    while (string[i] != '\0') {
        if (string[i] == start || string[i] == end || string[i] == flag) {
            final[j++] = flag;
        }
        final[j++] = string[i];
        i++;
    }
    final[j++] = end;
    final[j] = '\0';
    puts(final);
}