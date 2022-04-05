#include "bits/stdc++.h"

using namespace std;

int arr[101][101];
string temp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string A,B,C;
    cin >> A >> B >> C;
    int lenA = A.length();
    int lenB = B.length();
    int lenC= C.length();
    for (int i = 1; i <= lenA; ++i) {
        for (int j = 1; j <= lenB; ++j) {
            if (A[i-1] == B[j-1]) {
                arr[i][j] = arr[i-1][j-1]+1;
            }else {
                arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
            }
        }
    }
    while (lenA != 0 && lenB != 0){
        if (arr[lenA][lenB] > arr[lenA-1][lenB-1] && arr[lenA][lenB] > arr[lenA-1][lenB] && arr[lenA][lenB] > arr[lenA][lenB-1]){
            temp.push_back(A[lenA-1]);
            lenA--;
            lenB--;
        } else if(arr[lenA][lenB] > arr[lenA][lenB-1] && arr[lenA][lenB] == arr[lenA-1][lenB]) {
            lenA--;
        }else {
            lenB--;
        }
    }
    reverse(temp.begin(),temp.end());
    cout << temp << '\n';
    int lenT = temp.length();
    for (int i = 1; i <= lenT; ++i) {
        for (int j = 1; j <= lenC; ++j) {
            arr[i][j] = 0;
        }
    }
    for (int i = 1; i <= lenT; ++i) {
        for (int j = 1; j <= lenC; ++j) {
            if (temp[i-1] == C[j-1]) {
                arr[i][j] = arr[i-1][j-1]+1;
            }else {
                arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
            }
        }
    }
    cout << arr[lenT][lenC];


}