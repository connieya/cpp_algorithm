#include "bits/stdc++.h"

using namespace std;

int main()
{
    int i;
    int test = 0x1234678;
    char * ptr = (char *)&test;

    for(i=0; i < sizeof(int); i++){
        printf("%x",ptr[i]);
    }
}