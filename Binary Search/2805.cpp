#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    long long n, m, min=0, max=INT_MIN, ans;
    long long namu[1000009];

    scanf("%lld %lld", &n, &m);
    for(int i=0; i<n; i++) {
        scanf("%lld", &namu[i]);
        if(max < namu[i])
            max = namu[i];
    }
        
    while(1) {
        long long mid = (min + max) /2;
        long long sum = 0;
        for(int i=0; i<n; i++) {
            if(namu[i] > mid)
                sum += (namu[i]-mid);
        }
                //printf("min : %lld, mid: %lld, max: %lld, sum: %lld", min, mid, max, sum);
            if (sum == m || min + 1 == max || min == max) {
                ans = mid;
                break;
            }
            else if(sum > m)
                min = mid;
            else
                max = mid;
    }
    printf("%lld", ans);

    return 0;
}
