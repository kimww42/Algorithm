// https://www.acmicpc.net/problem/11054

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, ans=0;
	int arr[1009];
	int dp[1009], dp2[1009];
	scanf("%d", &n);

	for(int j=0; j<n; j++)
		scanf("%d", &arr[j]);
	
	
	for(int j=0; j<n; j++) {
		int tmp=0;
		for(int k=j; k>=0; k--) {
			if(arr[j] > arr[k] && tmp < dp[k]+1)
				tmp = dp[k] + 1;
			if(k==0 && tmp ==0)
				tmp += 1;
		}
		dp[j] = tmp;
		tmp=0;
	}
	
	for(int j=n-1; j>=0; j--) {
		int tmp=0;
		for(int k=n-1; k>=j; k--) {
			if(arr[j] > arr[k] && tmp < dp2[k]+1)
				tmp = dp2[k] + 1;
			if(k == j && tmp == 0)
				tmp += 1;
		}
		dp2[j] = tmp;
		tmp=0;
	}

	for(int i=0; i<n; i++) {
		if(ans < dp[i] + dp2[i]-1)
			ans = dp[i] + dp2[i]-1;
		//printf("dp[%d] = %d dp2[%d] = %d\n", i, dp[i], i, dp2[i]);
	}
	printf("%d\n", ans);
	
	return 0;
}
