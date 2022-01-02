#include "stdio.h"
#include "deque"

int main(void) {
    int n, ans = 0;
    scanf("%d", &n);
    std::deque<int> deque;
    while (n--) {
        char cmd[100];
        scanf("%s", cmd);
        if (cmd[0] == 'f') {
            ans = deque.size() ? deque.front() : -1;
            printf("%d\n", ans);
            continue;
        }
        if (cmd[0] == 'b') {
            ans = deque.size() ? deque.back() : -1;
            printf("%d\n", ans);
            continue;
        }
        if (cmd[0] == 'e') {
            ans = deque.size() ? 0 : 1;
            printf("%d\n", ans);
            continue;
        }
        if (cmd[0] == 's') {
            printf("%d\n", deque.size());
            continue;
        }
        if (cmd[0] == 'p' && cmd[5] == 'b') {
            int num;
            scanf("%d", &num);
            deque.push_back(num);
            continue;
        }
        if (cmd[0] == 'p' && cmd[5] == 'f') {
            int num;
            scanf("%d", &num);
            deque.push_front(num);
            continue;
        }
        if (cmd[0] == 'p' && cmd[4] == 'f') {
            if (deque.empty()) {
                printf("%d\n", -1);
            } else {
                printf("%d\n", deque.front());
                deque.pop_front();
            }
            continue;
        }
        if (cmd[0] == 'p' && cmd[4] == 'b') {
            if (deque.empty()) {
                printf("%d\n", -1);
            } else {
                printf("%d\n", deque.back());
                deque.pop_back();
            }
            continue;
        }
    }
}