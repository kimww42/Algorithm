#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, arr[505][505];
	
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &arr[i][j]);
		}
	}


	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				arr[i][j] += arr[i - 1][j];
			}
			else if (j == i) {
				arr[i][j] += arr[i - 1][j - 1];
			}
			else {
				arr[i][j] += max(arr[i - 1][j], arr[i - 1][j-1]);
			}
			//printf("%d ", arr[i][j]);
		}
		//printf("\n");
	}


	int maxx = arr[n-1][0];

	for (int i = 1; i < n; i++) {
		maxx = max(arr[n - 1][i], maxx);
	}
	printf("%d", maxx);
	return 0;
}
