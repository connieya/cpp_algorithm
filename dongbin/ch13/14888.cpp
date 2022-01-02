#include "stdio.h"
#include "queue"

using namespace std;

typedef struct {
    int x;
    int y;
    int type;
} virus;

struct compare {
    bool operator()(virus &v1, virus &v2) {
        return v1.type > v2.type;
    }
};

int main(void) {
    priority_queue<virus, vector<virus>, compare> pq;
    virus v;
    for (int i = 0; i < 5; ++i) {
        scanf("%d %d %d", &v.x, &v.y, &v.type);
        pq.push(v);
    }
    for (int i = 0; i < 5; ++i) {
        printf("%d ", pq.top().type);
        pq.pop();
    }


}