#include "stdio.h"
#include "queue"

using namespace std;

int point[10001];
int dx[3] = {1,-1,5};

int main(void)
{
    int s ,e;
    scanf("%d %d",&s, &e);
    if (s>=e){
        printf("%d",s-e);
    }else{
        queue<int> Q;
        Q.push(s);
        fill(point,point+10001,-1);
        point[s] = 0;
        while (point[e] == -1) {
            int cur = Q.front(); Q.pop();
            for (int i = 0; i < 3; ++i) {
                int nx = dx[i] + cur;
                if (nx >=0 && nx <=10000 && point[nx] == -1) {
                    point[nx] = point[cur] +1;
                    Q.push(nx);
                }
            }
        }
        printf("%d",point[e]);
    }

}