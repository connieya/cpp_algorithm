#include "stdio.h"
#include "queue"
using namespace std;


priority_queue<long long , vector<long long > , greater<long long >> pq;

void input(int k) {
    int num;
    while (k--) {
        scanf("%d",&num);
        pq.push(num);
    }
}
long long solve() {
    long long ans = 0;
    while (pq.size() > 1){
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();
        ans += a+b;
        pq.push(a+b);
    }
    pq.pop();
    return ans;
}

int main(void)
{
    int t ,k;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&k);
        input(k);
        printf("%lld\n",solve());
    }
}