#include <stdio.h>
#define N 9
#define INF 9999

struct Vertex {
	int dist, par;
} v[N];

int adj_matrix[N][N] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

void relax(int i, int j) {
	if (v[j].dist > v[i].dist + adj_matrix[i][j]) {
		v[j].dist = v[i].dist + adj_matrix[i][j];
		v[j].par = i;
	}
}

void BellmanFord(int src) {
	v[src].dist = 0;
	for (int k = 0; k < N - 1; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (adj_matrix[i][j])
					relax(i, j);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (adj_matrix[i][j] && v[j].dist > v[i].dist + adj_matrix[i][j]) {
				printf("Negative edge cycle detected!\n");
				return;
			}
	printf("No negative edge cycles detected!\n");
	for (int i = 0; i < N; i++)
		printf("Distance of source - %d: %d\nParent: %d\n", i, v[i].dist, v[i].par);
}

int main() {
	for (int i = 0; i < N; i++) {
		v[i].dist = INF;
		v[i].par = -1;
	}
	BellmanFord(0);
}