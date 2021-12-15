#include "stdio.h"
#include "stack"
#include "vector"

using namespace std;

int main(void) {
    int n, i = 1 , num;
    stack<int> s;
    vector<char> ans;
    scanf("%d", &n);
    while (n--){
        scanf("%d",&num);
        if (num > i){
            s.push(num);
            ans.push_back('P');
        }
        if (num == i) {
            ans.push_back('P');
            ans.push_back('O');
            i++;
            while (i ==s.top()){
                s.pop();
                ans.push_back('O');
                i++;
            }
        }
    }
    for (char c: ans) {
        printf("%c",c);
    }

}