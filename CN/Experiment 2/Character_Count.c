#include<stdio.h>
#include<string.h>
char frames[10][50], final[50], *len;
int no_of_frames;
int main() {
    int i, j = 0;
    printf("Enter the number of frames: ");
    scanf("%d\n", &no_of_frames);
    for (i = 0; i < no_of_frames; i++) {
        gets(frames[i]);
    }
    for (i = 0; i < no_of_frames; i++) {
        final[j++] = '0' + strlen(frames[i]);
        strcat(final, frames[i]);
        j += strlen(frames[i]);
    }
    puts(final);
}