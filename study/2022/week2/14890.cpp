#include "bits/stdc++.h"

using namespace std;

int MAP[100][100];
int N, L;
bool isDown = false; // 오르막 내리막 바뀌는 구간
bool search_row(int x, int y ,int count) {
    if (y == N - 1) { // 마지막 행 까지 도달 true!!
        return true;
    }
    if (y+1 < N && MAP[x][y] != MAP[x][y+1]) { // 높이가 다르다면
        if (abs(MAP[x][y] - MAP[x][y+1]) > 1){  // 높이가 다른데 높이 차이가 1 초과면 false;
            return false;
        }

        if (MAP[x][y] +1 == MAP[x][y+1]){ // 오르막;
            if (!isDown){ // 그 전에 계속 평지였다면,
                if(count < L) { // 경사로 길이보다 작다면
                    return false;
                }
                search_row(x,y+1,1); // 오르막 긻 부터 다시 길이 1로 시작
            }else { // 내리막길 부터 길이 시작 되었다면,
                if (count < 2*L) {
                    return false; // 내리막길 과 오르막길에 대한 경사로의 길이는 2*L 그리고 그거보다 작다면  false;
                }
                isDown = false;
                search_row(x,y+1,1); // 오르막길로 올라 간뒤 다시 길이 1
            }
        }

        if (MAP[x][y] -1 == MAP[x][y+1]) { // 다음 길이 내리 막길이라면
            if (!isDown){ // 내리막길이 처음 시작이라면
                isDown = true; // 내리막길 시작
                search_row(x,y+1,1);
            }else { // 그 전에 내리막길 부터 시작 했다면
                if (count < L){ // 경사로 길이 보다 작다면
                    return false;
                }else {
                    search_row(x,y+1,1);
                }
            }

        }

    } else if(y+1 < N && MAP[x][y] == MAP[x][y+1]){ // 계속 평지라면
        search_row(x, y + 1,count+1);
    }
}

int main(void) {
    cin >> N >> L;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> MAP[i][j];
        }
    }
    for (int i = 0; i < N; ++i) {
        isDown = false;
        cout << search_row(i,0,1) << '\n';
    }

}