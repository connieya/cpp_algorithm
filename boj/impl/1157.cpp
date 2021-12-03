#include <stdio.h>

int alpha[26], c = 26, d =-1, e;

int main() {
    char b[1000001];
    scanf("%s", b);
    for (int i = 0; b[i] != '\0'; i++) {
        int index =0;
        if(b[i]> 96) {
            index = b[i]-97;
        }else{
            index = b[i]-65;
        }
        alpha[index]++;
    }
    for (; c--;) {
        if (alpha[c] > d) {
            d = alpha[c];
            e = c;
        } else if (alpha[c] == d) {
            e = -2;
        }
    }
    printf("%c", e + 65);
}
