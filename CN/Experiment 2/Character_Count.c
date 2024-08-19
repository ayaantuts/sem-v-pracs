#include<stdio.h>
#include<string.h>

char frames[4][50], final[300], len[20];
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
        // ssprintf will store the length as stream of characters in the char* len
        sprintf(len, "%lu", strlen(frames[i]) + 1);
        // Concatenate the len string to the final string
        strcat(final, len);
        // Finally, append the frame
        strcat(final, frames[i]);
    }
    printf("%s\n", final);
    return 0;
}