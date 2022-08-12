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