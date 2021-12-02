#include <cstdio>
int main()
{
    char jumin[20];
    int year , age;
    scanf("%s" , &jumin);
    if(jumin[7] =='1' || jumin[7] == '2'){
        year = 1900+((jumin[0]-'0')*10 + (jumin[1]-'0'));
    }else {
        year = 2000+((jumin[0]-'0')*10 + (jumin[1]-'0'));
    }
    age = 2019-year+1;
    printf("%d " , age);
    if(jumin[7] == '1' || jumin[7] == '3'){
        printf("M\n");
    }else {
        printf("W\n");
    }
}