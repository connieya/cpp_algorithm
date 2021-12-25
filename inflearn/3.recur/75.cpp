#include "stdio.h"
#include "queue"
#include "vector"
#include "algorithm"
using namespace std;

struct Data {
    int money;
    int day;
    Data(int m , int d){
        money = m;
        day = d;
    }
    bool operator<(Data &d){
        return day > d.day; // 내림차순
    }
};
int main(void)
{
    int n,money ,day , max = -1 , ans =0;
    scanf("%d",&n);
    priority_queue<int> pq;
    vector<Data> T;

    for (int i = 0; i < n; ++i) {
        scanf("%d %d",&money,&day);
        T.push_back(Data(money,day));
        if (day > max) {
            max = day;
        }
    }
    sort(T.begin(),T.end());
    int j =0;
    for (int i=max; i>=1; i--) {
        for (; j<n; j++){
            if (T[j].day <i){
                break;
            }
            pq.push(T[j].money);
        }
        if (!pq.empty()){
            ans +=pq.top();
            pq.pop();
        }
    }
    printf("%d",ans);
}