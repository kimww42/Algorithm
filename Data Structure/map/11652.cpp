// https://www.acmicpc.net/problem/11652

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <cstring>
#include <map>
using namespace std;


int main() {
	
	long long n;
	long long ans = INT_MIN, lotate=INT_MAX;
	map<long long, long long> m;
	scanf("%lld", &n);
	
	for(long long i=0; i<n; i++) {
		long long a;
		scanf("%lld", &a);
		if(m.find(a)!=m.end()) {
			m[a]++;
			//printf("plus %d\n", m[a]);
		} else {
			m.insert(pair<long long, long long>(a, 1));
			//printf("insert");
		}
	}
	
		for(auto iter = m.begin(); iter != m.end(); iter++) {
			if(ans < iter->second) {
				ans = iter->second;
				lotate = iter->first;
				//printf("first, %d second, %d\n", iter->first, iter->second);
			}
			else if(ans == iter->second) {
			    if(lotate > iter->first)
				    lotate = iter->first;
			}
		}
	
	printf("%lld", lotate);
	
	return 0;
}
