#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool valid(char ch){
        if( (ch >= 'a' && ch <='z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <='9')){
            return true;
        }
        return false;
    }

    bool checkPalin(string tmp){
        int len = tmp.length();
        for(int i=0; i < len/2; i++) {
            if(tmp[i] != tmp[len-1-i]) return false;
        }

        return true;
    }

    bool isPalindrome(string s) {
        string tmp = "";
        int length = s.length();
        for(int i=0; i<length; i++){
            if(valid(s[i])){
                tmp.push_back(s[i]);
            }
        }
        for(int i = 0; i< tmp.length(); i++) {
            if(tmp[i] >= 'A' && tmp[i] <=  'Z'){
                tmp[i] += 32;
            }
        }

        return checkPalin(tmp);
    }
};