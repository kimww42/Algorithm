// https://www.acmicpc.net/problem/2156

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int a;
	int arr[10009];
	int dp[10009];
	scanf("%d", &a);

	for(int j=3; j<a+3; j++)
		scanf("%d", &arr[j]);

	for(int j=3; j<a+3; j++) {
		dp[j] = max({dp[j-1], dp[j-2] + arr[j], dp[j-3] + arr[j-1] + arr[j]});
	}
		
	printf("%d\n", dp[a+2]);
	
	return 0;
}
