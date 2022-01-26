#include "bits/stdc++.h"
#include <cstring>
#include <algorithm>
using namespace std;

struct Data {
    char str[51];
    int len;
};

Data data[20000];

bool compare(Data d1, Data d2) {
    if (d1.len == d2.len) {
        return strcmp(d1.str, d2.str) < 0;
    }
    return d1.len < d2.len;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", data[i].str);
        data[i].len = strlen(data[i].str);
    }
    sort(data, data + n, compare);
    printf("%s\n", data[0].str);
    for (int i = 1; i < n; ++i) {
        if (strcmp(data[i].str, data[i - 1].str) != 0) {
            printf("%s\n", data[i].str);
        }
    }
}