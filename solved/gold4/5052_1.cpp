#include "bits/stdc++.h"

using namespace std;

const int NUMBER_SIZE = 10;

struct TrieNode {
    struct TrieNode *children[NUMBER_SIZE];
    bool isEndOfWord;
};

struct TrieNode *getNode(void) {
    struct TrieNode *pNode = new TrieNode;
    pNode->isEndOfWord = false;
    for (int i = 0; i < NUMBER_SIZE; ++i) {
        pNode->children[i] = NULL;
    }
    return pNode;
}

void insert(struct TrieNode *root, string key) {
    struct TrieNode *pCrawl = root;
    for (int i = 0; i < key.length(); ++i) {
        int index = key[i] - '0';
        if (!pCrawl->children[index]) {
            pCrawl->children[index] = getNode();
        }
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
}

bool call(struct TrieNode *root, string key) {
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (pCrawl->isEndOfWord) {
            return true;
        }
        pCrawl = pCrawl->children[index];
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string str;
        TrieNode *root = getNode();
        bool flag = false;
        for (int i = 0; i < n; ++i) {
            cin >> str;
            insert(root, str);
            if (call(root, str)) {
//                call(root,str)
                flag = true;
            }
        }
        flag ? cout << "NO" << '\n' : cout << "YES" << '\n';
    }
}