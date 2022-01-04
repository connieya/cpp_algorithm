#include "stdio.h"
#include "algorithm"

using namespace std;

int main(void) {
    int N, C, ans = 0;
    scanf("%d %d", &N, &C);
    int arr[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + N);
    int lt = 1;
    int rt = arr[N - 1] - arr[0];
    while (lt <= rt) {
        int mid = (lt + rt) / 2;
        int cnt = 1;
        int pre = arr[0];
        for (int i = 1; i < N; ++i) {
            int dis = arr[i] - pre;
            if (dis >= mid) {
                cnt++; // 거리가 작을 수록 공유기 개수가 많아진다.
            }
            pre = arr[i];
        }
        // C개 이상의 공유기를 설치할 수 있는 경우, 거리를 증가시키기
        if (cnt >= C) {
            lt = mid + 1; // 거리를 증가 시키려면 왼쪽 부분 값을 증가
            ans = max(ans,mid);
        } else { // C개 이상의 공유기를 설치할 수 없는 경우, 거리를 감소시키기
            rt = mid - 1;
        }
    }
    printf("%d",ans);

}