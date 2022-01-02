#include "stdio.h"
#include "queue"

using namespace std;

typedef struct
{
    int x,y,type,second;

} virus;

struct compare {
    bool operator()(virus &v1, virus &v2) {
        return v1.type > v2.type;
    }
};


int n,k,s,x,y;
int arr[200][200];

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int main(void)
{
    scanf("%d %d",&n,&k);
    priority_queue<virus, vector<virus>, compare> pq;
    virus v;
    int time = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d",&arr[i][j]);
            if (arr[i][j]){
                v.x = i;
                v.y = j;
                v.type = arr[i][j];
                v.second = 0;
                pq.push(v);
            }
        }
    }
    scanf("%d %d %d",&s,&x,&y);
    queue<virus> Q;
    while (!pq.empty()) {
         auto cur = pq.top();
         pq.pop();
        Q.push(cur);
    }
    while (!Q.empty()){
        auto cur = Q.front();
        Q.pop();
        if (cur.second == s){
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = cur.x +dx[i];
            int ny = cur.y +dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n ) continue;
            if (!arr[nx][ny]){
                arr[nx][ny] = cur.type;
                Q.push({nx,ny,cur.type,cur.second+1});
            }
        }
    }
    printf("%d",arr[x-1][y-1]);
}