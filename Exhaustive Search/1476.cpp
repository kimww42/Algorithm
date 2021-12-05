// https://www.acmicpc.net/problem/1476

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <cstring>
using namespace std;

int main() {
	int e, s, m;
	int fe=1, fs=1, fm=1;
	int ans=1;
	scanf("%d %d %d", &e, &s, &m);
	
	while(1) {
		if(fe == e && fs == s && fm == m) {
			break;
		}
		fe++;
		fs++;
		fm++;
		
		if(fe == 16)
			fe=1;
		if(fs == 29)
			fs=1;
		if(fm == 20)
			fm=1;
		
		ans++;
	}
	
	printf("%d", ans);
	return 0;
}
