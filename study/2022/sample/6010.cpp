#include "stdio.h"
#include "vector"
#include "algorithm"
using namespace std;

int main(void)
{
    int n,q , count , question;
    vector<int> notes;
    scanf("%d %d",&n,&q);
    int now =0;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&count);
        notes.push_back(now+count-1);
        now += count;
    }

    for (int i = 0; i < q; ++i) {
        scanf("%d",&question);
        auto it = lower_bound(notes.begin(),notes.end(),question);
        printf("%d\n",it - notes.begin()+1);
    }

}