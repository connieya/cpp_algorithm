#include "bits/stdc++.h"

bool checkValid(std::stack<char> stack, char ch) {
    if (stack.empty()) {
        return false;
    }
    if (ch == ']' && stack.top() != '[') {
        return false;
    }
    if (ch == ')' && stack.top() != '(') {
        return false;
    }
    return true;
}

int main(void) {
    char str[32];
    scanf("%s", str);
    std::stack<char> stack;
    int sum = 0;
    int num = 1;
    for (int i = 0; str[i]; ++i) {
        if (str[i] == '(') {
            num *= 2;
            stack.push(str[i]);
        } else if (str[i] == '[') {
            num *= 3;
            stack.push(str[i]);
        } else {
            if (!checkValid(stack, str[i])) {
                sum = 0;
                break;
            } else if (str[i] == ')') {
                if (str[i - 1] == '(') {
                    sum += num;
                }
                stack.pop();
                num = num / 2;
            } else if (str[i] == ']') {
                if (str[i - 1] == '[') {
                    sum += num;
                }
                stack.pop();
                num = num / 3;
            }

        }
    }
    if (stack.empty()) {
        printf("%d", sum);
    } else {
        printf("%d", 0);
    }
}