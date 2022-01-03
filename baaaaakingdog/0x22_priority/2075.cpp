#include "stdio.h"
#include "queue"

using namespace std;
int main(void)
{
    int n , num;
    priority_queue<int> pq;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d",&num);
            pq.push(-num);
            if (pq.size() > n){
                pq.pop();
            }
        }
    }
    printf("%d",-pq.top());
}