// https://www.acmicpc.net/problem/11722

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
		int tmp=1;
		for(int k=j-1; k>=0; k--) {
			if(arr[j] < arr[k] && tmp < dp[k] + 1)
				tmp = dp[k]+1;
		}
		dp[j] = tmp;
		tmp=1;
	}
	
	for(int i=0; i<n; i++) {
		if(ans < dp[i])
			ans = dp[i];
		//printf("dp[%d] = %d\n", i, dp[i]);
	}
	printf("%d\n", ans);
	
	return 0;
}
