#include <bits/stdc++.h>
using namespace std;
#define MAX_N 109

int n, m;
int graph[MAX_N][MAX_N];
int visited[MAX_N];
int cnt = 0;

void findByDFS(int node) {
	visited[node] = 1;
	cnt++;
	for (int i = 1; i <= n; i++) {
		if (visited[i] != 1 && graph[node][i] == 1) {
			findByDFS(i);
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	memset(graph, 0, sizeof(graph));
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	findByDFS(1);
	printf("%d", cnt-1);
	return 0;
}
