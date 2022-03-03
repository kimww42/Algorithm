#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, k;

	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < k; i++) {
		if (n >= m * 2)
			n--;
		else
			m--;
	}
	if (n >= m * 2)
		printf("%d", m);
	else
		printf("%d", n / 2);
	return 0;
}
