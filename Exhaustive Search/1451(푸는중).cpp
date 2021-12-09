#include <cstdio>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <cstring>
using namespace std;

long long n, m, ans=INT_MIN;
char arr[59][59];

long long area(int sx, int dx, int sy, int dy) {
	long long sum=0;
	
	for(int i=sx; i<=dx; i++) {
		for(int j=sy; j<=dy; j++) {
			sum += (int)(arr[i][j] - 48);
			//printf("arr[%d][%d] %d sum %d\n", i, j, (int)arr[i][j]-48, sum);
		}
	}
	//printf("sx%d dx%d sy%d dy%d sum : %d\n",sx, dx, sy, dy, sum);
	return sum;
}

int main() {
	scanf("%lld %lld", &n, &m);
	
	for(int i=0; i<n; i++)
		scanf("%s", &arr[i]);
	
	//6 cases
	
	//1. -------------
	//  |      |      |
	//  |      |      |
	//   -------------
	//  |             |
	//  |             |
	//   -------------
	
	for(int i=0; i<n-1; i++) {
		for(int j=0; j<m-1; j++) {
			ans = max(area(0, i, 0, j) * area(0, i,j+1, m-1) * area(i+1, n-1, 0, m-1), ans);	
		}
	}
	
	
	//2. -------------
	//  |             |
	//  |             |
	//   -------------
	//  |      |      |
	//  |      |      |
	//   -------------
	for(int i=n-1; i>0; i--) {
		for(int j=0; j<m-1; j++) {
			ans = max(area(0, m-1, 0, i-1) * area(0, j, i, n-1) * area(j+1, m-1, i, n-1), ans);	
		}
	}
	
	//3. -------------
	//  |      |      |
	//  |      |      |
	//  |------       |
	//  |      |      |
	//  |      |      |
	//   -------------
	for(int j=0; j<m-1; j++) {
		for(int i=0; i<n-1; i++) {
			ans = max(area(0, i, 0, j) * area(i+1, n-1, 0, j) * area(0, n-1, j+1, m-1), ans);	
		}
	}
	
	
	//4. -------------
	//  |      |      |
	//  |      |      |
	//  |       ------|
	//  |      |      |
	//  |      |      |
	//   -------------
	for(int j=0; j<m-1; j++) {
		for(int i=0; i<n-1; i++) {
			ans = max(area(0, j, 0, n-1) * area(j+1, m-1, 0, i) * area(j+1, m-1, i+1, n-1), ans);	
		}
	}
	
	
	//5. -------------
	//  |             |
	//  |-------------|
	//  |             |
	//  |-------------|
	//  |             |
	//   -------------
	for(int i=0; i<n-2; i++) {
		int secondsize=0;
		for(int j=i+1; j+secondsize<n-1; secondsize++) {
			ans = max(area(0, i, 0, m-1) * area(j, j+secondsize, 0, m-1) * area(j+secondsize+1, n-1, 0, m-1), ans);	
		}
	}
	
	
	//6. -------------
	//  |    |   |    |
	//  |    |   |    |
 	//  |    |   |    |
	//  |    |   |    |
	//  |    |   |    |
	//   -------------
	for(int i=0; i<m-2; i++) {
		int secondsize=0;
		for(int j=i+1; j+secondsize<m-1; secondsize++) {
			ans = max(area(0, n-1, 0, i) * area(0, n-1, j, j+secondsize) * area(0, n-1, j+secondsize+1, m-1), ans);	
		}
	}
	
	
	printf("%lld", ans);
	return 0;
}
