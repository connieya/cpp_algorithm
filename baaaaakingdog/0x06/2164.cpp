#include "stdio.h"
#include "queue"

int main(void)
{
    int n;
    scanf("%d",&n);
    std::queue<int > queue;
    for (int i = 1; i <= n; ++i) {
        queue.push(i);
    }
    while (queue.size()>1){
        queue.pop();
        queue.push(queue.front());
        queue.pop();
    }
    printf("%d",queue.front());
}