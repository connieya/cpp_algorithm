#include "stdio.h"
#include "vector"

int main(void) {
    int n, m;
    scanf("%d", &n);
    std::vector<int> arrN(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arrN[i]);
    }
    scanf("%d", &m);
    std::vector<int> arrM(m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &arrM[i]);
    }
    std::vector<int> answer(n + m);
    int nIndex = 0, mIndex = 0, i = 0;
    while (nIndex < n && mIndex < m) {
        if (arrN[nIndex] < arrM[mIndex]) {
            answer[i++] = arrN[nIndex];
            nIndex++;
        } else {
            answer[i++] = arrM[mIndex];
            mIndex++;
        }
    }
    for (int j=i; j<n+m; j++){
        if (nIndex == n){
            answer[j] = arrM[mIndex++];
        }else{
            answer[j] = arrN[nIndex++];
        }
    }

    for (int i=0; i<n+m; i++){
        printf("%d ",answer[i]);
    }
}