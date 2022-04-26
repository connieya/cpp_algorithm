#include "bits/stdc++.h"

using namespace std;

char input[10000][11];

struct TRIE{
    bool Finish;
    TRIE *Node[10]; // 0~ 9 까지
    TRIE() {
        Finish = false;
        for (int i = 0; i < 10; ++i) {
            Node[i] = NULL;
        }
    }
    void insert(char *str){
        if (*str == '\0'){
            Finish = true;
            return;
        }
        int Cur = *str-'0';
        if (Node[Cur] == NULL) Node[Cur] = new TRIE();
        Node[Cur] ->insert(str+1);
    }

    bool find(char *str)
    {
        if (*str == '\0'){
            return false;
        }
        if (Finish) return true;

        int Cur = *str -'0';
        if (Node[Cur] == NULL) return false;
        return Node[Cur]->find(str+1);
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        TRIE * Root = new TRIE();
        for (int i = 0; i < n; ++i) {
            cin >> input[i];
            Root->insert(input[i]);
        }
        int i;
        for (i=0; i<n; i++){
            if (Root->find(input[i])){
                cout << "NO\n";
                break;
            }
        }
        if (i==n){
            cout << "YES\n";
        }
    }
}