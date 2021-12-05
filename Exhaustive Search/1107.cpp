// https://www.acmicpc.net/problem/1107

#include <bits/stdc++.h>
using namespace std;

int len = 0, n, channel, reslen=0;
int arr[11] = { 0, };

int check(int chan, int chklen) {
	int div = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < chklen; j++) {
			//printf("%d = chan == %d\n", chan / div % 10, arr[i]);
			if (chan /div % 10 == arr[i]) {
				return 1;
			}
			else {
				div *= 10;
			}
		}
		div = 1;
	}
	return 2;
}

int findlen(int chan) {
	int len = 0;
	if (chan == 0)
		len = 1;
	while (chan > 0) {
		chan /= 10;
		len++;
	}
	return len;
}

int main() {
		int res = INT_MAX, tmp = 0, tmpres = INT_MAX;
		scanf("%d", &channel);
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);

		int pluschan = channel;
		int minuschan = channel;
		len = findlen(channel);
		while (1) {
			reslen = findlen(pluschan);
			if (check(pluschan, reslen) == 2) {
				tmpres = pluschan - channel;
				tmpres += reslen;
				tmp = 1;
				//printf("tmpres : %d\n", tmpres);
			}
			else
				pluschan++;
			reslen = findlen(minuschan);
			if (check(minuschan, reslen) == 2 && minuschan >= 0) {
				res = channel - minuschan;
				//printf("res+len : %d\n", res + reslen);
				res = min(res + reslen, tmpres);
				break;
			}
			else
				minuschan--;
			if (tmp == 1) {
				res = tmpres;
				break;
			}
			if (abs(channel - 100) < pluschan - channel && abs(channel - 100) < channel - minuschan) {
				res = abs(channel - 100);
				break;
			}
			//printf("%d %d\n", pluschan, minuschan);
		}
		printf("%d", min(abs(channel - 100), res));
	return 0;
}
