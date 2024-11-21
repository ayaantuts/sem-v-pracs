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
int visited[N], visitedCount = 0;

int extractMin() {
	int i, min = INF, minIdx = -1;
	for (i = 0; i < N; i++) {
		if (visited[i] == 0 && min > v[i].dist) {
			min = v[i].dist;
			minIdx = i;
		}
	}
	return minIdx;
}

void relax(int i, int j) {
	if (v[j].dist > v[i].dist + adj_matrix[i][j]) {
		v[j].dist = v[i].dist + adj_matrix[i][j];
		v[j].par = i;
	}
}

void djikstra(int src) {
	v[src].dist = 0;
	v[src].par = -1;
	while (visitedCount < N) {
		int u = extractMin();
		visitedCount++;
		visited[u] = 1;
		for (int i = 0; i < N; i++)
			if (adj_matrix[u][i])
				relax(u, i);
	}
}

int main() {
	for (int i = 0; i < N; i++) {
		v[i].dist = INF;
		v[i].par = -1;
	}
	djikstra(0);
	for (int i = 0; i < N; i++)
		printf("Distance of source - %d: %d\nParent: %d\n", i, v[i].dist, v[i].par);
	return 0;
}