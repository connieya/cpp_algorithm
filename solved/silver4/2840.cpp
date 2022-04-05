#include "bits/stdc++.h"

using namespace std;

char arr[26];
void init() {
    for (int i = 0; i < 26; ++i) {
        arr[i] = '!';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k ,r;
    char alpha;
    init();
    cin >> n >> k;
    cin >> r >> alpha;
    if (r>n-1){
        r -= n;
    }
    arr[r] = alpha;
    int num = r;
    int lastIndex;
    for (int i = 0; i < k-1; ++i) {
       cin >> r >> alpha;
        num += r;
        if (num > n-1){
            num -=n;
        }
//        cout << num << ' ' << alpha << ' ' << arr[num] << '\n';
        if (arr[num] != '!' && alpha != arr[num]){
            cout << "!" << '\n';
            return 0;
        }
        arr[num] = alpha;
        lastIndex = num;
    }
    string ans = "";
    for (int i = lastIndex; i >=0; --i) {
        if (arr[i] == '!'){
            ans+= "?";
        }else {
            ans += arr[i];
        }
    }
    for (int i = n-1; i > lastIndex; --i) {
        if (arr[i] == '!'){
            ans+= "?";
        }else {
            ans += arr[i];
        }
    }
    bool flag =false;
    int i;
    for (i = 0; i < ans.length()-1; ++i) {
        if (arr[i] == arr[i+1]){
            flag = true;
        }
    }
    if (arr[i-1] == arr[i]){
        flag = true;
    }
    if (flag){
        cout << "!";
        return 0;
    }
    cout << ans;
}