#include "stdio.h"
#include "queue"
#include "algorithm"

bool visited[100001];
int dist[100001];

int main(void)
{
    int n ,k;
    scanf("%d %d",&n,&k);
    visited[n] = true;
    std::fill(dist,dist+100001,-1);
    std::queue<int> Q;
    Q.push(n);
    dist[n] = 0;
    while (dist[k] == -1){
        int cur = Q.front();
        Q.pop();
        for(int e : {cur*2 ,cur-1 , cur+1}){
            if (e>=0 && e<=100000 && !visited[e]){
                visited[e] = true;
                if (e == cur*2){
                    dist[e] = dist[cur];
                }else{
                    dist[e] = dist[cur]+1;
                }
                Q.push(e);
            }
        }
    }
    printf("%d",dist[k]);
}