#include "stdio.h"
#include "queue"
using namespace std;

int main(void)
{
    int n , m , num;
    priority_queue<long long , vector<long long > , greater<long long >> pq;
    scanf("%d %d",&n,&m);
    while (n--){
        scanf("%d",&num);
        pq.push(num);
    }
    while (m--) {
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();
        pq.push(a+b);
        pq.push(a+b);
    }
    long long ans =0;
    while (!pq.empty()){
        ans += pq.top();
        pq.pop();
    }
    printf("%lld",ans);
}