#include "stdio.h"
#include "stack"

char str[31];

int main(void)
{
    scanf("%s",str);
    std::stack<char> s;
    for (int i=0; str[i]; i++){
        if (str[i] == '('){
            s.push(str[i]);
        }else if (s.empty()){
            printf("NO");
            return 0;
        }else {
            s.pop();
        }
    }
    if (s.empty()){
        printf("YES");
    }else {
        printf("NO");
    }
}