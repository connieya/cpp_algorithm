#include "bits/stdc++.h"

using namespace std;

int Hash(string , int);
int power = 1;
void findString(string str , string pattern)
{
    int patternSize = pattern.size();
    int strSize = str.size();
    int patternHash = Hash(pattern , patternSize);
    int strHash = 0;
    for (int i = 0; i <= strSize - patternSize; ++i) {
        if (i== 0){
            strHash = Hash(str,patternSize);
        }else {
            strHash = 2 * (strHash-str[i-1]*power)+str[patternSize-1+i];
        }
//        printf("strHash : %d  power : %d \n",strHash , power);

        if (strHash == patternHash) {
            int j = 0;
            for (j = 0; j < patternSize; ++j) {
                if (str[i+j] != pattern[j]){
                    break;
                }
            }
            if (j>=patternSize){
                printf("pattern : %d  , str : %d  => ",patternHash, strHash);
                printf("find index  :  %d  \n",i+1);
            }

        }
    }

}

int Hash(string str , int size)
{
    int hashValue = 0;
    power =1;
    for (int i = 0; i < size; ++i) {
        hashValue += str[size-1-i]*power;
        if (i <size-1){
            power *= 2;
        }
    }
    return hashValue;
}

int main()
{
    string str = "ababacabacaabacaabaabca";
    string pattern = "aba";
    findString(str,pattern);
    return 0;
}