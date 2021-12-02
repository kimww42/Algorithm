// https://www.acmicpc.net/problem/2225

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <limits.h>
using namespace std;

int main() {
	int n, k;
	int dp[209][209];
	scanf("%d %d", &n, &k);
	
	// init
	for(int i=1; i<n+1; i++)
		dp[i][1] = 1;
	for(int i=1; i<k+1; i++)
		dp[1][i] = i;
	
	
	for(int i=2; i<n+1; i++) {
		for(int j=2; j<k+1; j++) {
			dp[i][j] = (dp[i-1][j] + dp[i][j-1])%1000000000;
		}
	}
	printf("%d", dp[n][k]); 
	return 0;
}
