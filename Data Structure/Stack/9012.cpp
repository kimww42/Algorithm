// https://www.acmicpc.net/problem/9012

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <cstring>
#include <stack>
using namespace std;


int main() {
	
	int n;
	char inp[60];
	
	scanf("%d", &n);
	
	for(int i=0; i<n; i++) {
	    stack <int> s;
		scanf("%s", inp);
		
		for(int j=0; j<strlen(inp); j++) {
			if(inp[j] == '(') {
				s.push(1);
			} else if(inp[j] == ')') {
				if((int)s.size() <= 0) {
					printf("NO\n");
					break;
				}
				else
					s.pop();
			}
			if(j==strlen(inp)-1 && (int)s.size() != 0) {
				printf("NO\n");
			} else if (j == strlen(inp)-1){
				printf("YES\n");
			}
		}
	}
	
	
	return 0;
}
