#include "bits/stdc++.h"

using namespace std;

int arr[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int num,length,weight;
    cin >> num >> length >> weight;
    queue<int> q;
    int ans = 0;
    int sum =0;
    for (int i = 0; i < num; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < num; ++i) {
        while (1){
            if(q.size() == length){
                sum -= q.front();
                q.pop();
            }
            if (sum + arr[i] <= weight){
                break;
            }
            q.push(0);
            ans++;
        }
        q.push(arr[i]);
        sum += arr[i];
        ans++;
    }
    cout << ans+length;

}