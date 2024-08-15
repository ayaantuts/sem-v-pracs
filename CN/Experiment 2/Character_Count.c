#include<stdio.h>
#include<malloc.h>
#include<string.h>

char frames[4][50], final[300], *len;
int no_of_frames;

int main() {
    int i;
    printf("Enter the number of frames: ");
    scanf("%d", &no_of_frames);
    // Input the frame strings
    for (i = 0; i < no_of_frames; i++) {
        printf("Enter frame %d: ", i + 1);
        scanf("%s", frames[i]);
    }
    for (i = 0; i < no_of_frames; i++) {
        // Convert the length of the frame to a stream of characters and append it to the final string
        len = (char *)malloc(strlen(frames[i]) + 1);
        // ssprintf will store the length as stream of characters in the char* len
        sprintf(len, "%lu", strlen(frames[i]));
        // Concatenate the len string to the final string
        strcat(final, len);
        // Finally, append the frame
        strcat(final, frames[i]);
        // Free len to improve memory
        free(len);
    }
    printf("%s\n", final);
    return 0;
}