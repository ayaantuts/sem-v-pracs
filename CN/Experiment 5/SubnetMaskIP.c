#include <stdio.h>

int subnet[4], ip[4], network[4];
int subnet_octets;
char class;

int main() {
	int i, j, op1, op2;
	char class;
	printf("Enter the ip address: ");
	scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
	if (ip[0] >= 1 && ip[0] <= 127)
		class = 'A';
	else if (ip[0] >= 128 && ip[0] <= 191)
		class = 'B';
	else if (ip[0] >= 192 && ip[0] <= 223)
		class = 'C';
	else if (ip[0] >= 224 && ip[0] <= 239)
		class = 'D';
	else if (ip[0] >= 240 && ip[0] <= 255)
		class = 'E';
	else
		class = '\0';
	if (class)
		printf("The given IP address belongs to Class %c\n", class);
	switch(class) {
		case 'A':
			subnet_octets = 1;
			break;
		case 'B':
			subnet_octets = 2;
			break;
		case 'C':
			subnet_octets = 3;
			break;
		case 'D':
			subnet_octets = 4;
			break;
		case 'E':
			printf("\n--- Special (Reserved) Address! ---\n");
			return 0;
		default:
			printf("Invalid input!\n");
			return 0;
	}
	for (i = 0; i < subnet_octets; i++)
		subnet[i] = 255;
	for (i = subnet_octets; i < 4; i++)
		subnet[i] = 0;
	printf("The subnet mask is %d.%d.%d.%d\n", subnet[0], subnet[1], subnet[2], subnet[3]);
	for (i = 0; i < 4; i++)
		network[i] = ip[i] & subnet[i];
	printf("The network ID is %d.%d.%d.%d\n", network[0], network[1], network[2], network[3]);
	return 0;
}