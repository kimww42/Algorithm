// https://www.acmicpc.net/problem/1699

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <limits.h>
using namespace std;

int main() {
	int n, ans=0;
	int dp[100009];
	scanf("%d", &n);
	
	dp[1] = 1;
	for(int i=2; i<n+1; i++) {
		dp[i] = INT_MAX;
		for(int j=1; j*j<=i; j++) {
			dp[i] = min(dp[i], dp[i-j*j]+1);
			//printf("j:%d dp[%d]:%d\n", j,i, dp[i]);
		}
	}
	printf("%d", dp[n]);
	return 0;
}
