// https://www.acmicpc.net/problem/2579

#include <cstdio>
#include <algorithm>
#include <limits.h>
using namespace std;

int main() {
	int n, ans=INT_MIN;
	int arr[1009];
	int dp[1009], chk[1009];
	
	scanf("%d", &n);

	for(int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}
	dp[0] = arr[0];
	dp[1] = arr[0]+arr[1];
	dp[2] = max(arr[0]+arr[2], arr[1]+arr[2]);
	for(int i=3; i<n; i++) {
		dp[i] = max(dp[i-3]+arr[i-1]+arr[i], dp[i-2] + arr[i]);
	}
	
	printf("%d", dp[n-1]);
	return 0;
}
