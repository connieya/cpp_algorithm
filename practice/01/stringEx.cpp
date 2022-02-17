#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a = "Time is 2020Year 03Month";
    int len = a.size();

    // 소문자
    for (int i = 0; i < len; ++i) {
        if (islower(a[i])) cout << a[i] << ' ';
    }
    cout << '\n';

    // 대문자
    for (int i = 0; i < len; ++i) {
        if (isupper(a[i])) cout << a[i] << ' ';
    }
    cout << '\n';


    // 숫자
    for (int i = 0; i < len; ++i) {
        if (isdigit(a[i])) cout << a[i] << ' ';
    }
    cout << '\n';

    // 해당 문자 인덱스 번호
    cout << a.find('T') << '\n';
    cout << a.find('2') << '\n';

    // 뒤에 해당 문자 추가
    a.push_back('s');
    cout << a<< '\n';

    // 문자열 젤 뒤에 인덱스 값 제거
    a.pop_back();
    cout << a<< '\n';

    a = a+'d';
    cout << a<< '\n';

    a.pop_back();
    a = a+" 27days";
    cout << a<< '\n';

    cout << a.substr(8) << '\n';
    cout << a.substr(8,4) << '\n';
}