// https://www.acmicpc.net/problem/1463

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int dp[1333333] = {};
	
	scanf("%d", &n);
	
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	
	for(int i=4; i<=n; i++) {
		int a,b,c;
		if(i%3 == 0) {
			a = dp[i/3];
		} else {
			a = 9999999;
		}
		if(i%2 == 0) {
			b = dp[i/2];
		} else {
			b = 9999999;
		}
		dp[i] = min({a, b, dp[i-1]}) + 1;
	}
	printf("%d", dp[n]);
	return 0;
}
