#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k, arr[15], cnt=0;

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

		for (int i = n - 1; i >= 0; i--) {
			if (k >= arr[i] ) {
				k -= arr[i];
				cnt++;
				i++;
			}
		}
	printf("%d", cnt);
	return 0;
}
