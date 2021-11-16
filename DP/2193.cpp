// https://www.acmicpc.net/problem/2193

#include <cstdio>
using namespace std;

int main() {
	int n;
	long long dp[100][2] = {0,0,0,1};
	scanf("%d", &n);
	
	for(int i=2; i<=n; i++) {
		dp[i][0] = dp[i-1][0] + dp[i-1][1];
		dp[i][1] = dp[i-1][0];
	}
	
	printf("%lld\n",dp[n][0] + dp[n][1]);
	return 0;
}
