#include <iostream>
using namespace::std;

int main()
{
    int a , b , sum=0; // sum 초기화 안해주면 쓰레기 값이 저장됨
    cin >> a >> b;
    for (int i = a; i < b; ++i) {
        sum +=i;
        cout <<i<<"+";
    }
    cout<<b<<"=";
    cout<<sum+b;
}