#include "stdio.h"
using namespace std;

int main()
{
    char str[100];
    int res =0, cnt =0 ,i;
    scanf("%s",str);
    for(i=0; str[i] !='\0'; i++){
        if(str[i] >= '0' && str[i] <='9'){
            res = res*10+(str[i]-'0');
        }
    }
    printf("%d\n",res);
    for(int i=1; i<=res; i++){
        if(res%i==0){
            cnt++;
        }
    }
    printf("%d\n",cnt);
}