#include "stdio.h"
#include "queue"

using namespace std;

int main(void) {
    int n , num;
    scanf("%d", &n);
    priority_queue<int , vector<int> , greater<int>> pq;
    while (n--) {
        scanf("%d",&num);
        pq.push(num);
    }
    int sum =0,a,b;
    while (pq.size() >1) {
        a =pq.top();
        pq.pop();
        b =pq.top();
        pq.pop();
        sum += a+b;
        pq.push(a+b);
    }
    printf("%d",sum);
}