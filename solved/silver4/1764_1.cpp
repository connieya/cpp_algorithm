#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

const ll HASH_SIZE = 100000;
const ll MAX_NODE = 500000;

struct Node {
    char name[21];
    Node *next;

} nodes[MAX_NODE];

int idx = 0;

Node *newNode() {
    return &nodes[idx++];
}

struct Bucket {
    int count;
    Node *head;

} HashTable[HASH_SIZE];

unsigned int get_key(char *str) {
    ll key = 0, p = 1;
    for (int i = 0; str[i]; ++i) {
        key = (str[i] << 2) +key;
    }
    return key % HASH_SIZE;
}

int strcmp(char a[] , char b[])
{
    int i =0;
    while (a[i]) {
        if (a[i] != b[i]) break;
        i++;
    }
    return a[i]-b[i];
}

void strcpy(char a[] , char b[])
{
    int i;
    for (i=0; b[i]; i++){
        a[i] = b[i];
    }
    a[i] = 0;
}

void add(char * str) {
    unsigned int key = get_key(str);
    Node * node = newNode();
    strcpy(node->name , str);
    node->next = 0;
    if (HashTable[key].count != 0){
        node -> next = HashTable[key].head;
    }
    HashTable[key].head = node;
    HashTable[key].count++;
}

bool find(char * str)
{
    unsigned int key = get_key(str);
    Node * node = HashTable[key].head;
    while (node) {
        if (strcmp(str , node->name) == 0){
            return true;
        }
        node = node -> next;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    char a[21];
    vector<string> ans;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        add(a);
    }
    for (int i = 0; i < m; ++i) {
        cin >> a;
        if (find(a)) {
            ans.push_back(a);
        }
    }
    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for (string a: ans) {
        cout << a << '\n';
    }
}