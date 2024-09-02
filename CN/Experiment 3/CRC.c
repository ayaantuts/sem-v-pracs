#include <stdio.h>
#include <string.h>
char dx[50], gx[10], fx[50], rx[50];
int dxlen, gxlen, fxlen, rxlen;

void xor(char* a, char* b, int len) {
	int i = 1;
	while (i < len) {
		if (a[i] == b[i]) {
			a[i - 1] = '0';
		} else {
			a[i - 1] = '1';
		}
		i++;
	}
	a[i - 1] = '\0';
}

void crc(char* dx, char* gx, char* fx) {
	int i = 0, j = 0;
	while (i < strlen(gx) - 1) {
		dx[strlen(dx) + i] = '0';
		i++;
	}
	dx[strlen(dx) + i] = '\0';
	for (i = 0; i < strlen(gx); i++) {
		fx[i] = dx[i];
	}
	i = 0;
	while (i < strlen(dx) - strlen(gx)) {
		if (fx[0] == '1') {
			xor(fx, gx, strlen(gx));
		} else {
			for (j = 1; j < strlen(gx); j++) {
				fx[j - 1] = fx[j];
			}
		}
		if (i < strlen(dx) - strlen(gx) - 1)
			fx[gxlen - 1] = dx[gxlen + i];
		else
			fx[gxlen - 1] = '\0';
		i++;
	}
	fx[i] = '\0';
}

int main() {
	int i = 0, j = 0;
	printf("Enter the data blocks: ");
	scanf("%s", dx);
	printf("\nEnter the generator polynomial: ");
	scanf("%s", gx);
	dxlen = strlen(dx);
	gxlen = strlen(gx);
	while (i < gxlen - 1) {
		dx[dxlen + i] = '0';
		i++;
	}
	dx[dxlen + i] = '\0';
	dxlen = strlen(dx);
	crc(dx, gx, fx);
	printf("\nCRC code: %s\n", fx);
	i = strlen(dx) - strlen(fx);
	while (i < strlen(dx)) {
		dx[i] = fx[i - strlen(dx) + strlen(fx)];
		i++;
	}
	dx[i] = '\0';
	printf("\nTransmitted data: %s\n", dx);
	printf("\nEnter the received data: ");
	scanf("%s", rx);
	rxlen = strlen(rx);
	crc(rx, gx, fx);
	printf("\nRemainder: %s\n", fx);
	for (i = 0; i < strlen(fx); i++) {
		if (fx[i] == '1') {
			printf("\nError detected\n");
			return 0;
		}
	}
	printf("\nNo error detected\n");
	return 0;
}