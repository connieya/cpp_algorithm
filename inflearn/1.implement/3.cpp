#include <iostream>
using namespace::std;

int main()
{
    int n ,sum =1;
    cin >> n ;
    cout <<"1";
    for (int i = 2; i <= n/2; ++i) {
        if (n % i ==0){
            sum += i;
            cout <<" + " << i;
        }
    }
    cout <<" = "<< sum;
}