#include "bits/stdc++.h"

using namespace std;

char MP[1001][1001];
int area[3];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m ,k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> MP[i];
    }
    for (int i = 0; i < k; ++i) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        for(int i=0; i<3; i++){
            area[i] = 0;
        }
        for (int j = a-1; j < c; ++j) {
            for (int l = b-1; l < d; ++l) {
                if (MP[j][l] == 'J') {
                    area[0]++;
                }else if(MP[j][l] == 'O') {
                    area[1]++;
                }else {
                    area[2]++;
                }
            }
        }
        cout << area[0] <<' ' << area[1] << ' ' << area[2] << '\n';
    }


}