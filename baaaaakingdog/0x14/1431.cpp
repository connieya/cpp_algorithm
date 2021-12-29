#include "stdio.h"
#include "cstring"
#include "algorithm"

using namespace std;

struct S
{
    char str[51];
    int len;

    bool operator < (const S &o) const
    {
        int c[2] = {0};
        if (len != o.len) {
            return len < o.len;
        }
        for (int i = 0; str[i]; ++i) {
            if (str[i] >= '0' && str[i] <='9'){
                c[0] += str[i] -'0';
            }
        }
        for (int i = 0; o.str[i]; ++i) {
            if (o.str[i] >= '0' && o.str[i] <='9'){
                c[1] += o.str[i] -'0';
            }
        }
        if (c[0] != c[1]) return c[0] < c[1];
        return strcmp(str,o.str) < 0;
    }

};


int main(void)
{
    int n;
    S s[51];
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%s",s[i].str);
        s[i].len = strlen(s[i].str);
    }
    sort(s, s+n);
    for (int i = 0; i < n; ++i) {
        printf("%s\n",s[i].str);
    }
}