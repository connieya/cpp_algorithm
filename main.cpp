#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int> &arrow, vector<int> &tmp) {
    // 가장 큰 점수 차이로 우승할 수 있는 방법이 여러 개 일 경우
    // 가장 낮은 점수를 더 많이 맞힌 경우가 정답이다.
    for (int i = 11; i >= 0; i--) {
        if (arrow[i] != tmp[i]) return arrow[i] > tmp[i];
    }
    return false;
}

vector<int> solution(int n, vector<int> info) {
    vector<int> ret(12, -1);
    // 0점은 의미가 없으니깐
    // 0번 인덱스 부터  9번 인덱스는 라이언이 맞힌 화살 점수(10-i)
    // 10 번 인덱스는 남은 화살의 수
    // 11 번 인덱스는 점수 총합
    for (int brute = 0; brute < 1024; brute++) {
        // brute = 10개의 비트 =>  1111111111(2)~ 0000000000(2)
        // 비트가 켜진 곳은 해당 점수에서 라이언이 이긴 것을 의미
        vector<int> arrow(12);
        int score = 0;
        int left = n;
        for (int i = 0; i < 10; i++) { // 0점~10점까지 확인 해보자
            if (brute & (1 << i)) {
                score += 10 - i;
                left -= info[i] + 1; // 어피치 보다 무조건 1발이라도 더 맞춰야 하니깐
                arrow[i] = info[i] + 1;
            } else if (info[i] != 0) {
                score -= 10 - i;
            }
        }

        if (score <= 0 || left < 0) continue;
        arrow[10] = left;
        arrow[11] = score;
        if (cmp(arrow, ret)) ret = arrow;
    }
    if (ret[0] == -1) return vector<int>({-1});
    ret.pop_back();
    return ret;
}