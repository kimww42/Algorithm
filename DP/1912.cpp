// https://www.acmicpc.net/problem/1912

#include <cstdio>
#include <algorithm>
#include <limits.h>
using namespace std;

int main() {
	int n, ans=INT_MIN;
	int arr[100009];
	int dp[100009], dp2[100009];
	
	scanf("%d", &n);

	for(int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}
	dp[0] = arr[0];
	for(int i=1; i<n; i++) {
		dp[i] = max(arr[i], dp[i-1] + arr[i]);
	}
	
	for(int i=0; i<n; i++) {
		if(ans < dp[i])
			ans = dp[i];
	}
	printf("%d", ans);
	return 0;
}
