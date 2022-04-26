#include "bits/stdc++.h"

using namespace std;

int electric[101];
int use[101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, K , ans = 0;
    cin >> N >> K;
    for (int i = 0; i < K; ++i) {
        cin >> electric[i];
    }
    for (int i = 0; i < K; ++i) {
        bool isUse = false;
        for (int j = 0; j < N; ++j) {
            if (electric[i] == use[j]){
                isUse = true;
                break;
            }
        }
        // 전기 용품을 사용하고 있으니 뽑을 필요가 없다.
        if (isUse) continue;


        isUse = false;
        // 플러그에 남은 구멍이 있는지 확인해보자
        for (int j = 0; j < N; ++j) {
            if (use[j] == 0){
                use[j] = electric[i];
                isUse = true;
                break;
            }
        }
        // 뽑을게 없다.
        if (isUse) continue;

        // 모든 플러그 콘센트를 사용하고 있으니 이제 무엇을 뽑을지 정하자
        int swap , val = -1;
        for (int j = 0; j < N; ++j) {
            int tmp = 0;
            for (int k = i+1; k <K  && use[j] != electric[k] ; ++k) {
                tmp++;
            }
            if (tmp > val){
                val = tmp;
                swap = j;
            }
        }
        use[swap] = electric[i];
        ans++;

    }
    cout << ans;

}