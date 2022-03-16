#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1009

int n, m, v;
int graph[MAX_N][MAX_N];
int visited[MAX_N];

void dfs(int vertex) {
	visited[vertex] = 1;
	printf("%d ", vertex);

	for (int i = 1; i <= n; i++) {
		if (visited[i] != 1 && graph[vertex][i] == 1) {
			dfs(i);
		}
	}
}

void bfs() {
	queue<int> q;
	q.push(v);
	visited[v] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		printf("%d ", now);
		for (int i = 1; i <= n; i++) {
			if (visited[i] != 1 && graph[now][i] == 1) {
				q.push(i);
				visited[i] = 1;
			}
		}
	}
}
int main() {

	scanf("%d %d %d", &n, &m, &v);
	memset(graph, 0, sizeof(graph));

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	dfs(v);
	printf("\n");
	memset(visited, 0, sizeof(visited));
	bfs();
	return 0;
}
