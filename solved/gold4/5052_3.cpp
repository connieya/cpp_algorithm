#include "bits/stdc++.h"

using namespace std;

struct TrieNode{
    bool valid;
    int child[10];
    TrieNode() {
        valid = false;
        fill(child,child+10,-1);
    }
};

struct Trie{
    vector<TrieNode> trie;
    int newNode(){
        TrieNode temp;
        trie.push_back(temp);
        return trie.size()-1;
    }

    void add(string &s , int node = 0, int idx = 0){
        if (idx == s.size()){
            trie[node].valid = true;
            return;
        }
        int c = s[idx]-'0';
        if (trie[node].child[c] == -1) {
            int next = newNode();
            trie[node].child[c] = next;
        }
        add(s,trie[node].child[c] , idx+1);
    }

    bool check(string & s) {
        int now = 0;
        for (int i = 0; i <s.size(); ++i) {
            int c = s[i]-'0';
            if (trie[now].valid) return true;
            if (trie[now].child[c] == -1) return false;
            now = trie[now].child[c];
        }
        for (auto i: trie[now].child) {
            if(i != -1) return true;
        }
        return trie[now].valid;
    }
    Trie(){
        newNode();
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        Trie T;
        int n;
        cin >> n;
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            if (T.check(s)) flag = false;
            if (flag) T.add(s);
        }
        cout << (flag ? "YES" : "NO") << '\n';

    }
}