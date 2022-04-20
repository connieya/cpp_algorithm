#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin >> str;
    int len = str.length();
    int ans = 0;
    for (int i = 0; i < len; ++i) {
        ans++;
        if (str[i] == 'c' && i+1 < len &&  (str[i+1] == '=' || str[i+1] == '-' ) ){
            i++;
        }else if ( (str[i] == 'l' || str[i] == 'n') && i+1 < len && str[i+1] == 'j'){
            i++;
        }else if ( (str[i] == 's' || str[i] == 'z' ) && i+1 < len && str[i+1] == '=' ){
            i++;
        }else if (str[i] == 'd' && i+1 < len && str[i+1] == '-'){
            i++;
        }else if (str[i] =='d' && i+1 < len && str[i+1] == 'z' && i+2 < len && str[i+2] == '='){
            i+=2;
        }
    }
    cout << ans;

}