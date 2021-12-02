#include <cstdio>
int main()
{
    int n, s = 0;
    scanf("%d", &n);
    while (scanf("%1d", &n) != -1) s += n;
    printf("%d", s);
}