#include "stdio.h"
#include "set"
using namespace std;

set<int> s;

int main(void)
{
    int n ,m , tmp;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&tmp);
        s.insert(tmp);
    }
    scanf("%d",&m);
    for (int i = 0; i < m; ++i) {
        scanf("%d",&tmp);
        if (s.find(tmp) != s.end()) {
            printf("yes\n");
        }else {
            printf("no\n");
        }
    }
}