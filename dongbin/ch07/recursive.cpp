#include "bits/stdc++.h"

using namespace std;

int binary_search(vector<int>& arr, int target ,int lt , int rt) {
    if (lt > rt) return -1;
    int mid = (lt+rt)/2;
    if (arr[mid] == target) return mid+1; // 찾은 경우 중간 값 인덱스 반환
    if(arr[mid] > target) return binary_search(arr,target,lt,mid-1); // 중간 값보다 찾고자 하는 값이 작은 경우
    return binary_search(arr,target,mid+1,rt); // 중간 값보다 찾고자 하는 값이 큰 경우 오른쪽 확인

}

int n ,target;
vector<int> arr;
int main(void)
{
    // 원소의 개수 : n , 찾고자 하는 값 : target
    cin >> n >> target;
    // 전체 원소 입력 받기
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    int result = binary_search(arr,target,0,n-1);
    if (result == -1){
        cout << "원소가 존재하지 않습니다." << '\n';
    }else{
        cout << result << '\n';
    }
}