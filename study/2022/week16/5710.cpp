#include "bits/stdc++.h"

using namespace std;

int watt[] = {100,9900,990000};
int price[] = {2,3,5,7};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a,b;
    while (1){
        cin >> a >> b;
        if (!a && !b) break;
        int lt = 0;
        int rt = a;
        int ans ,total_watt = 0;
        for (int i = 0; i < 3; ++i) {
            if (a < watt[i]*price[i]){
                total_watt += total_watt/price[i];
                break;
            }else {
                a -= watt[i]*price[i];
                total_watt += watt[i]/price[i];
            }
        }
        cout << total_watt << '\n';

        while (lt <= rt){
            int mid = (lt+rt)/2;
            if (a-mid >= b){
                lt = mid+1;
                ans = mid;
            }else {
                rt = mid-1;
            }
        }
//        cout << ans << '\n';
    }
}