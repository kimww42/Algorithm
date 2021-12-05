// https://www.acmicpc.net/problem/2011

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <cstring>
using namespace std;

int main() {
	char str[5009], tmp[5];
	int dp[5009], ans=0;
	scanf("%s", &str);
	
	if(str[0] != '0') {
		dp[0] = 1;
		
		for(int i=1; i<strlen(str); i++) {
			if(str[i] == '0' && str[i-1] == '0') {
				dp[strlen(str)-1] = 0;
				break;
			} else if(str[i] == '0'){
				if((str[i-1] =='1' || str[i-1] == '2')) {
					if(i==1)
						dp[i] = 1;
					else
						dp[i] = dp[i-2];
				} else {
					dp[strlen(str)-1] = 0;
					break;
				}
			} else if(atoi(strncpy(tmp, str+i-1, 2)) >= 10 && atoi(strncpy(tmp, str+i-1, 2)) <= 26) {
				if(i==1)
					dp[i] = (dp[i-1] + 1) % 1000000;
				else
					dp[i] = (dp[i-1] + dp[i-2]) % 1000000;
			} else {
				dp[i] = dp[i-1];
			}
			//printf("dp[%d] = %d\n", i, dp[i]);
		}
		
	}
	
	printf("%d", dp[strlen(str)-1]);
	
	return 0;
}
