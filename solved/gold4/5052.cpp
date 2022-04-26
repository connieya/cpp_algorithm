#include "bits/stdc++.h"

using namespace std;

const int MAX = 10;

struct Trie {
    Trie *go[MAX];
    bool output;
    bool goexist;

    Trie() {
        fill(go, go + MAX, nullptr);
        output = goexist = false;
    }

    ~Trie() {
        for (int i = 0; i < MAX; ++i) {
            if (go[i]) delete go[i];
        }
    }

    bool insert(const char *key) {
        if (*key == '\0') {
            output = true;
            return !goexist;
        }
        int next = *key - '0';
        if (!go[next]) go[next] = new Trie;
        goexist = true;
        return !output && go[next]->insert(key + 1);
    }

};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Trie *root = new Trie;
        bool result = true;
        for (int i = 0; i < n; ++i) {
            char tel[11];
            cin >> tel;
            if (result && !root->insert(tel)) result = false;
        }

        string ans = result ? "YES" : "NO";
        cout << ans << '\n';
        delete root;
    }

}
