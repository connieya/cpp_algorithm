#include "stdio.h"
#include "queue"

int main()
{
    int n,k;
    scanf("%d %d",&n ,&k);
    std::queue<int> queue;
    for (int i=1; i<=n; i++){
        queue.push(i);
    }
    printf("<");
    while (queue.size() > 1){
        for (int i = 1; i < k; ++i) {
           queue.push(queue.front());
           queue.pop();
        }
        printf("%d, ",queue.front());
        queue.pop();
    }
    printf("%d>",queue.front());
}