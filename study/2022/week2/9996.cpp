#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string str;
    cin >> str;
    int index = str.find("*");
    string left = str.substr(0,index);
    string right = str.substr(index+1);
    while (n--) {
        string answer = "NE";
        string input;
        cin >> input;
        if (input.length() >= str.length()-1){
            if (left.compare(input.substr(0,index)) == 0
            && right.compare(input.substr(input.length()-right.length())) == 0){
                answer = "DA";
            }
        }
        cout << answer << '\n';
    }
}