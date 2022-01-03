#include "stdio.h"
#include "vector"

using namespace std;

int main() {
    vector<int> V;
    V.push_back(1);
    V.push_back(12);
    V.push_back(13);
    V.push_back(15);
    printf("%d \n",V.front());
    printf("%d \n",V.back());
    return 0;
}
