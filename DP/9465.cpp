// https://www.acmicpc.net/problem/9465

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int a;
	int arr[100009][2];
	int dp[3][100009];
	scanf("%d", &a);
	
	for(int i=0; i<a; i++) {
		int n;
		scanf("%d", &n);
		
		for(int j=0; j<2; j++)
			for(int k=2; k<n+2; k++)
				scanf("%d", &arr[k][j]);

		for(int j=2; j<n+2; j++) {
			dp[0][j] = arr[j][0] + max(dp[1][j-1], dp[2][j-1]);
			dp[1][j] = arr[j][1] + max(dp[0][j-1], dp[2][j-1]);
			dp[2][j] = max(dp[0][j-1], dp[1][j-1]);
		}
		
		printf("%d\n", max({dp[0][n+1], dp[1][n+1], dp[2][n+1]}));
	}
	
	return 0;
}
