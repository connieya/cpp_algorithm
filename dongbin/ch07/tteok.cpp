#include "stdio.h"
#include "algorithm"

using namespace std;
int main(void)
{
    int n,m;
    scanf("%d %d",&n,&m);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n);
    int lt = 0;
    int rt = arr[n-1]-1;
    int mid ,res;
    while (lt <= rt) {
        mid = (lt +rt) /2;
        int sum = 0;
        for (int tt: arr) {
            if (tt >mid){
                sum += tt-mid;
            }
        }
        if (sum >= m){ // 떡의 양이 충반하기 때문에 덜 잘라야함
            res = mid;  // 최대한 덜 잘랐을 때가 정답이므로, 여기에서 result 에 기록
            lt = mid+1;
        }else{
            rt = mid-1;
        }
    }
    printf("%d",res);

}