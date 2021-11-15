// https://www.acmicpc.net/problem/10844

#include <cstdio>
using namespace std;

int main() {
	int n;
	int dp[109][10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
	int ans=0;
	scanf("%d", &n);
	
	for(int i=2; i<=n; i++) {
		for(int j=0; j<=9; j++) {
			if(j==0)
				dp[i-1][j] = dp[i-2][j+1] % 1000000000;
			else if(j==9)
				dp[i-1][j] = dp[i-2][j-1] % 1000000000;
			else
				dp[i-1][j] = (dp[i-2][j-1] + dp[i-2][j+1]) % 1000000000;
		}

	}
	
	for(int k=0; k<=9; k++) {
		ans += dp[n-1][k];
		ans %= 1000000000;
	}
	printf("%d", ans);
	return 0;
}
