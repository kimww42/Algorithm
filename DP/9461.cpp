// https://www.acmicpc.net/problem/9461

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <limits.h>
using namespace std;

int main() {
	int n;
	long long dp[109];
	
	scanf("%d", &n);
	
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	
	for(int i=0; i<n; i++) {
		int a;
		scanf("%d", &a);
		
		for(int j=6; j<=a; j++) {
			dp[j] = dp[j-5] + dp[j-1];
		}
		
		printf("%lld\n", dp[a]);
	} 
	return 0;
}
