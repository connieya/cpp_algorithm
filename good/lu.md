## STL 라이브러리 사용

```c++
#include "bits/stdc++.h"

using namespace std;

int main() {
    int arr[] = {-2, -1, 2, 4, 12, 17, 21, 43};
    cout << lower_bound(arr, arr + 8, 4) - arr << '\n'; // 3번째 인덱스 
    cout << upper_bound(arr, arr + 8, 4) - arr << '\n'; // 4번째 인덱스
}
```

- lower_bound의 반환형은 Iterator 이므로 실제로 몇 번째 인덱스인지 알고 싶다면
- lower_bound 값에서 배열 첫 번째 주소를 가리키는 배열의 이름을 빼 주면 됩니다.
- 벡터의 경우 v.begin()을 빼 주면 됩니다.

## 직접 구현

```c++
#include "bits/stdc++.h"

using namespace std;

int l_bound(int arr[], int st, int end, int target) {
    while (st < end) {
        int mid = (st + end) / 2;
        if (arr[mid] >= target) {
            end = mid;
        } else {
            st = mid + 1;
        }
    }
    return end;
}

int u_bound(int arr[], int st, int end, int target) {
    while (st < end) {
        int mid = (st + end) / 2;
        if (arr[mid] > target) {
            end = mid;
        } else {
            st = mid + 1;
        }
    }
    return end;
}


int main() {
    int arr[] = {-2, -1, 2, 4, 12, 17, 21, 43};
    cout << l_bound(arr,0,8,4) << '\n'; // 3번쩨 인덱스
    cout << u_bound(arr,0,8,4) << '\n'; // 4번째 인덱스
}
```