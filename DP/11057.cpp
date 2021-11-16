// https://www.acmicpc.net/problem/11057

#include <cstdio>
using namespace std;

int main() {
	int n;
	int dp[1009][10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
	int ans=0, tmp=0;
	scanf("%d", &n);
	
	for(int i=2; i<=n; i++) {
		for(int j=0; j<=9; j++) {
			for(int k=0; k<=j; k++) {
				dp[i-1][j] += (dp[i-2][k] % 10007);
			}
		}

	}
	
	for(int k=0; k<=9; k++) {
		ans += dp[n-1][k];
	}
	printf("%d\n", ans%10007);
	return 0;
}
