# 코테 뿌수자 !!!!!!


### 초기화 하는 함수

- memset

```c
memset(dp,-1,sizeof(dp));
```


### tuple

```c
vector<tuple<int, int, int>> ans;
 ans.push_back({x+1, y+1, i});
 int x, y, len;
 tie(x, y, len) = ans[i];
```

### vector 에 원소 있는지

```c
if(find(v.begin(), v.end(), 0) == v.end()) { // vector내에 0이 존재하지 않음
        cout << "not exist\n";
    }

    if(find(v.begin(), v.end(), 6) != v.end()) { // vector내에 6이 존재함
        cout << find(v.begin(), v.end(), 6) - v.begin(); // index 확인
    }
```

### unordered_set  find()

```c
if (s.find(3) == s.end()) { // 3이 set 자료구조에 없다면~
        cout << "3 is not in set";
    } else {
        cout << "3 is in set  : true";
    }
```

## unique

### unique 구현

```c++
#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> v = {1, 1, 1, 2, 3, 3, 4, 4, 4, 4, 5, 4, 4, 3, 2, 1};
    for (int l = 0, r = 0; ++r < v.size(); l = r) {
        if (v[l] == v[r]) {
            while (++r < v.size()) {
                if (v[l] != v[r]) {
                    v[++l] = v[r];
                }
            }
            break;
        }
    }
    for (auto &i: v) {
        cout << i << ' ';
    }
    cout << '\n';
}
```


### 중복 원소 제거

```c++
#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
	fastio;
	vector<int> v = { 1, 1, 1, 2, 3, 3, 4, 4, 4, 4, 5, 4, 4, 3, 2, 1 };
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (auto& i : v) cout << i << ' '; cout << '\n'; // 1 2 3 4 5
}
```