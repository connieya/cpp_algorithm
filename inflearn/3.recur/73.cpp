#include "stdio.h"
#include "vector"
#include "algorithm"
#include "queue"

using namespace std;

int main()
{
    int a;
    priority_queue<int> pQ;
    while (true){
        scanf("%d",&a);
        if (a == -1) {
            break;
        }
        if (a == 0 && pQ.empty()){
            printf("-1\n"); continue;
        }
        if (a == 0 && !pQ.empty()) {
            printf("%d\n",pQ.top());
            pQ.pop(); continue;
        }
        pQ.push(a);
    }

}