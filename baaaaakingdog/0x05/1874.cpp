#include "stdio.h"
#include <bits/stdc++.h>
#include "stack"

int main(void) {
    int n, i = 1, num;
    scanf("%d", &n);
    std::stack<int> stack;
    std::string ans;
    while (n--) {
        scanf("%d", &num);
        while (i <= num) {
            stack.push(i++);
            ans += "+\n";
        }
        if (stack.top() == num) {
            stack.pop();
            ans += "-\n";
        }else {
            printf("NO");
            return 0;
        }
    }
    std::cout<<ans;
}