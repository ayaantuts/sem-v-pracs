#include<stdio.h>
#include<malloc.h>
#include<string.h>
char frames[10][50], final[50], *len;
int no_of_frames;
int main() {
    int i, j = 0;
    printf("Enter the number of frames: ");
    scanf("%d", &no_of_frames);
    for (i = 0; i < no_of_frames; i++) {
        scanf("%s", frames[i]);
    }
    for (i = 0; i < no_of_frames; i++) {
        // Convert the length of the frame to a stream of characters and append it to the final string
        len = (char *)malloc(strlen(frames[i]) + 1);
        sprintf(len, "%lu", strlen(frames[i]));
        strcat(final, len);
        strcat(final, frames[i]);
        j += strlen(frames[i]);
        free(len);
    }
    puts(final);
}