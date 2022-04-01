#include "bits/stdc++.h"

using namespace std;

struct Word {
    int size;
    char str[51];
};

bool compare(const Word & w1 , const Word & w2) {
    if (w1.size == w2.size){
        for (int i = 0; i < w1.size; ++i) {
            if (w1.str[i] == w2.str[i]) continue;
            return w1.str[i] < w2.str[i];
        }
    }
    return w1.size < w2.size; // 오름차순
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    Word *word = new Word[n];
    for (int i = 0; i < n; ++i) {
        cin >> word[i].str;
        word[i].size = strlen(word[i].str);
    }
    sort(word,word+n , compare);
    for (int i = 0; i < n - 1; ++i) {
        if (strcmp(word[i].str,word[i+1].str)){
            cout << word[i].str << '\n';
        }
    }
    cout << word[n-1].str;
}