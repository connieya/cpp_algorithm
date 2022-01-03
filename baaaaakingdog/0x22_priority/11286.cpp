#include "stdio.h"
#include "algorithm"
#include "queue"
using namespace std;

class cmp {
public:
    bool operator() (int a, int b) {
        if (abs(a) == abs(b)) {
            return a >b;
        }
        return abs(a) > abs(b);
    }
};

int main(void)
{
    int n , num;
    scanf("%d",&n);
    priority_queue<int, vector<int>, cmp> pq;
    while (n--) {
        scanf("%d",&num);
        if (!num && !pq.empty()){
            printf("%d\n",pq.top());
            pq.pop(); continue;
        }
        if (!num && pq.empty()){
            printf("0\n"); continue;
        }
        pq.push(num);
    }

}