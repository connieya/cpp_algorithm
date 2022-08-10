# UNF

```c

int parent[1000];
int find(int a);
void Union(int a , int b);

int find(int a){
    if (a == parent[a]){
        return a;
    }
    return parent[a] = find(parent[a]);
}

void Union(int a ,int b){
        a = find(a);
        b = find(b);
        if(a != b) {
            parent[a] = b;
        }
}

int main()
{
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
}
```