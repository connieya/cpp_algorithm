#include "stdio.h"
#include "queue"

using namespace std;

int main(void)
{
    int n,k;
    scanf("%d %d",&n,&k);
    queue<int> Q;
    for (int i = 1; i <=n; ++i) {
        Q.push(i);
    }
    while (Q.size() > 1) {
        for (int i = 1; i < k; ++i) {
            Q.push(Q.front());
            Q.pop();
        }
        Q.pop();
    }
    printf("%d",Q.front());
}