#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1009

int n, m;
int graph[MAX_N][MAX_N];
int visited[MAX_N];

void findByBFS(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (visited[i] != 1 && graph[now][i] == 1) {
				q.push(i);
				visited[i] = 1;
			}
		}
	}
}

int main() {
	int cnt = 0;

	scanf("%d %d", &n, &m);
	memset(graph, 0, sizeof(graph));
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i] != 1) {
			findByBFS(i);
			cnt++;
			i = 0;
		}
	}
	printf("%d", cnt);
	return 0;
}
