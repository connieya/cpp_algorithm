#include <iostream>
using namespace::std;

int main()
{
    int n,x ,num;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>> n >> x;
    while (n--){
        cin >> num;
        if(num <x){
            cout << num << ' ';
        }
    }
}