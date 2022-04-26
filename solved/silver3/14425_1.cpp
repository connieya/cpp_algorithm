#include "bits/stdc++.h"

using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

struct TrieNode *getNode(void) {
    struct TrieNode *pNode = new TrieNode;
    pNode->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        pNode->children[i] = NULL;
    }
    return pNode;
}

void insert(struct TrieNode *root, string key) {
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); ++i) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index]) {
            pCrawl->children[index] = getNode();
        }
        pCrawl = pCrawl->children[index];
    }

    pCrawl->isEndOfWord = true;
}

bool search(struct TrieNode *root, string key) {
    struct TrieNode *pCrawl = root;
    for (int i = 0; i < key.length(); ++i) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index]) return false;

        pCrawl = pCrawl->children[index];
    }
    return (pCrawl->isEndOfWord);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    struct TrieNode *root = getNode();
    string str;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> str;
        insert(root, str);
    }
    for (int i = 0; i < m; ++i) {
        cin >> str;
        ans += search(root, str);
    }
    cout << ans;
}