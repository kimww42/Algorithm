// https://www.acmicpc.net/problem/11052

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <cstring>
using namespace std;

int main() {
	int n, price[1009];
	int dp[1009];
	scanf("%d", &n);
	
	for(int i=1; i<=n; i++) {
		scanf("%d", &price[i]);
	}
	
	dp[1] = price[1];
	
	for(int i=2; i<=n; i++) {
		dp[i] = price[i];
		for(int j=1; j<i; j++) {
			dp[i] = max(dp[i-j] + dp[j], dp[i]);
		}
		//printf("dp[%d] = %d\n", i, dp[i]);
	}
	
	printf("%d", dp[n]);
	return 0;
}
