#include "iostream"
#include "vector"

using namespace std;

vector<int> makeTable(string pattern) // 최대 일치 테이블 구축
{
    int pattenSize = pattern.size();
    vector<int> table(pattenSize,0);
    int j =0;
    for (int i=1; i < pattenSize; i++) {
        while (j > 0 && pattern[i] != pattern[j]){
            j =  table[j-1];
        }
        if (pattern[i] == pattern[j])
        {
            table[i] = ++j;
        }
    }
    return table;
}

void KMP(string parent , string pattern) {
    vector<int> table = makeTable(pattern);
    int parentSize = parent.size();
    int patternSize = pattern.size();
    int j = 0;
    for (int i = 0; i < parentSize; ++i) {
        while (j > 0 && parent[i] != pattern[j]) {
            j = table[j-1];
        }
        if (parent[i] == pattern[j]) {
            if (j == patternSize-1){
                printf("find index : %d \n",i-patternSize+2);
                j = table[j];
            }else {
                j++;
            }
        }
    }
}

int main()
{
    string parent = "ababacabacaabacaaba";
    string pattern = "abacaaba";
    vector<int > table = makeTable(pattern);
    for (int i = 0; i < table.size(); ++i) {
        printf("%d ",table[i]);
    }
    printf("\n");
    KMP(parent,pattern);

    return 0;
}