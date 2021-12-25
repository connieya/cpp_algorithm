#include "stdio.h"
#include "queue"

using namespace std;

int main()
{
    int a;
    priority_queue<int> pq;
    while (true){
        scanf("%d",&a);
        if (a == -1) {
            break;
        }
        if (a == 0 && pq.empty()){
            printf("-1\n"); continue;
        }
        if (a == 0 && !pq.empty()) {
            printf("%d\n",-pq.top());
            pq.pop(); continue;
        }
        pq.push(-a);
    }
}