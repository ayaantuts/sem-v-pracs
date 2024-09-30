#include <stdio.h>

int subnet[4], ip[4];
int no_of_classes;
char class;

int main() {
	int i, j, op1, op2;
	printf("Enter the ip address: ");
	scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
	//printf("\nEnter the subnet mask: ");
	//scanf("%d.%d.%d.%d", &subnet[0], &subnet[1], &subnet[2], &subnet[3]);
	printf("\nEnter the class: ");
	scanf("\n%c", &class);
	switch(class) {
		case 'A':
		case 'a':
			no_of_classes = 1;
			break;
		case 'B':
		case 'b':
			no_of_classes = 2;
			break;
		case 'C':
		case 'c':
			no_of_classes = 3;
			break;
		case 'D':
		case 'd':
			no_of_classes = 4;
			break;
		default:
			printf("\nInvalid input!");
			return 0;
	}
	printf("\nSubnet mask: ");
	for (i = 0; i < no_of_classes; i++) {
		subnet[i] = 255;
		printf("255");
		if (i != no_of_classes - 1)
			printf(".");
	}
	for (j = 0; j < 4 - no_of_classes; j++) {
		subnet[4 - j - 1] = 0;
		printf(".0");
	}
	printf("\nNetwork address: ");
	for (i = 0; i < 4; i++) {
		op1 = ip[i] & subnet[i];
		printf("%d", op1);
		if (i != 3)
			printf(".");
	}
	return 0;
}