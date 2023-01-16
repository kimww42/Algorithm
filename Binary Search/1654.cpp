#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

long long n, k;
int arr[100009];
long long ans = 0;

int main() {
    long long min = 1, max = INT_MIN;
    scanf("%lld %lld", &k, &n);

    for(int i=0; i<k; i++) {
        scanf("%d", &arr[i]);
        if(max<arr[i])
            max = arr[i];
    }
    max += 1;
    //printf("%d %d\n", min, max);

    while(1) {
        long long mid = (min+max)/2;
        long long tmp=0;

        for(int i=0; i<k; i++) {
            tmp += arr[i]/mid;
        }
            //printf("%d %lld %d %lld\n", min, mid, max, tmp);

        if(tmp < n) {
            max = mid;
        }
        else if (min + 1 >= max) {
            if(ans < mid)
                ans = mid;
            break;
        }
        else {
            min = mid;
        }
    }
    printf("%lld", ans);
    return 0;
}
