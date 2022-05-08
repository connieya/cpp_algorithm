#include "bits/stdc++.h"
#define INF 50001
using namespace std;


int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

vector<pair<int,int>> graph[INF];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> q;
    q.push_back(1);
    q.push_back(2);
    q.push_back(23);
    vector<int> t = q;
    for (int s: t ) {
        cout << s << ' ';
    }
    stack<int> s;
    s.push(2);
    s.top();
}