#include <stdio.h>

char data[4], check[3], final[7], received[7];
int parity_pos[] = {3, 1, 0};
int data_pos[] = {6, 5, 4, 2};

void calculate_parity_bits() {
    for (int i = 0; i < 3; i++) {
        check[i] = 0;
        for (int j = 0; j < 4; j++) {
            if (data[j] == '1' && (j & (1 << parity_pos[i]))) {
                check[i] ^= 1;
            }
        }
        final[parity_pos[i]] = check[i] + '0';
    }
}

void print_hamming_code() {
    printf("The Hamming code is: ");
    for (int i = 0; i < 7; i++) {
        printf("%c", final[i]);
    }
    printf("\n");
}

void check_received_hamming_code(char received[]) {
    int error_position = -1;
    int calculated_check[3] = {0, 0, 0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 7; j++) {
            if (received[j] == '1' && (j & (1 << parity_pos[i]))) {
                calculated_check[i] ^= 1;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        if (calculated_check[i] != (received[parity_pos[i]] - '0')) {
            error_position = (1 << parity_pos[i]) - 1;
            break;
        }
    }
    if (error_position != -1) {
        printf("Error detected at position %d\n", error_position);
        received[error_position] ^= 1; // Invert the bit at the error position
        printf("Corrected Hamming code: ");
        for (int i = 0; i < 7; i++) {
            printf("%c", received[i]);
        }
        printf("\n");
    } else {
        printf("No errors detected\n");
    }
}

int main() {
    printf("Enter the data: ");
    scanf("%s", data);
    calculate_parity_bits();
    for (int i = 0; i < 4; i++) {
        final[data_pos[i]] = data[i];
    }
    print_hamming_code();
    printf("Enter the received bit string: ");
    scanf("%s", received);
    check_received_hamming_code(received);

    return 0;
}