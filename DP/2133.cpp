// https://www.acmicpc.net/problem/2133

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <limits.h>
using namespace std;

int main() {
	int n;
	long long dp[39];
	
	scanf("%d", &n);
	dp[1] = 0;
	dp[2] = 3;
	for(int i=3; i<=n; i++) {
		if(i%2 == 1) {
			dp[i] = 0;
		}
		else {
			dp[i] = dp[i-2]*3 + 2;
			for(int j=2; i-j*2>0; j++) {
				dp[i] = dp[i] + dp[i-j*2]*2;
			}
		}
	}
	printf("%lld", dp[n]);
	return 0;
}
