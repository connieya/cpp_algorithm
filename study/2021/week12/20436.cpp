#include "bits/stdc++.h"

using namespace std;

char keyboard[3][10] = {
        {'q','w','e','r','t','y' ,'u','i','o','p'},
         {'a','s','d','f','g','h','j','k','l'},
        {'z','x','c','v','b','n','m'}
        };
pair<int,int> leftFinger , rightFinger;
int ans = 0;

void init(char left , char right){
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (keyboard[i][j] == left){
                leftFinger.first =i;
                leftFinger.second = j;
            }
            if (keyboard[i][j] == right) {
                rightFinger.first = i;
                rightFinger.second = j;
            }
        }
    }
}

void solve(char ch) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (ch == keyboard[i][j]){
                if (j > 4 || (i==2 && j== 4)){
                    ans += abs(i-rightFinger.first)+ abs(j-rightFinger.second);
                    rightFinger.first = i;
                    rightFinger.second = j;
                }else {
                    ans += abs(i-leftFinger.first)+ abs(j-leftFinger.second);
                    leftFinger.first = i;
                    leftFinger.second = j;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char left ,right;
    cin >> left >> right;
    string input;
    cin >> input;
    init(left,right);
    int len = input.length();
    for (int i = 0; i < len; ++i) {
        solve(input[i]);
    }
    cout << ans+len;

}