// https://www.acmicpc.net/problem/11055

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, ans=0;
	int arr[1009];
	int dp[1009];
	scanf("%d", &n);

	for(int j=0; j<n; j++)
		scanf("%d", &arr[j]);
	
	
	for(int j=0; j<n; j++) {
		int tmp=0;
		for(int k=j; k>=0; k--) {
			if(arr[j] > arr[k] && tmp < dp[k]+arr[j])
				tmp = dp[k]+arr[j];
			if(k==0 && tmp ==0)
				tmp = arr[j];
		}
		dp[j] = tmp;
		tmp=0;
	}
	
	for(int i=0; i<n; i++) {
		if(ans < dp[i])
			ans = dp[i];
		//printf("dp[%d] = %d\n", i, dp[i]);
	}
	printf("%d\n", ans);
	
	return 0;
}
