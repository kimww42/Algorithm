// https://www.acmicpc.net/problem/9095

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int dp[13] = {};
	
	scanf("%d", &n);
	
	for(int j=0; j<n; j++) {
		int a;
		scanf("%d", &a);
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;

		for(int i=4; i<=a; i++) {
			dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]);
		}
		printf("%d\n", dp[a]);
	}

	return 0;
}
