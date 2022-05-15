#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 1; i <= t; ++i) {
        string str1, str2;
        getline(cin, str1);
        getline(cin, str2);

        while (!str1.empty() && str1.back() == ' ') str1.pop_back();
        while (!str2.empty() && str2.back() == ' ') str2.pop_back();
        while (!str1.empty() && str1.front() == ' ')str1.erase(0, 1);
        while (!str2.empty() && str2.front() == ' ')str2.erase(0, 1);

        for (auto &s1: str1) {
            s1 = tolower(s1);
        }
        for (auto &s2: str2) {
            s2 = tolower(s2);
        }

        regex r1(R"([\[\{])");

        str1 = regex_replace(str1, r1, "(");
        str2 = regex_replace(str2, r1, "(");

        regex r2(R"([\]\}])");
        str1 = regex_replace(str1, r2, ")");
        str2 = regex_replace(str2, r2, ")");

        regex r3(R"(;)");
        str1 = regex_replace(str1, r3, ",");
        str2 = regex_replace(str2, r3, ",");

        regex r4(R"([\s\t]+)");
        str1 = regex_replace(str1, r4, " ");
        str2 = regex_replace(str2, r4, " ");

        regex r5(R"(\s?\(\s?)");
        str1 = regex_replace(str1,r5,"(");
        str2 = regex_replace(str2,r5,"(");

        regex r6(R"(\s?\)\s?)");
        str1 = regex_replace(str1,r6,")");
        str2 = regex_replace(str2,r6,")");

        regex r7(R"(\s?\.\s?)");
        str1 = regex_replace(str1, r7, ".");
        str2 = regex_replace(str2, r7, ".");

        regex r8(R"(\s?\,\s?)");
        str1 = regex_replace(str1, r8, ",");
        str2 = regex_replace(str2, r8, ",");

        regex r9(R"(\s?\:\s?)");
        str1 = regex_replace(str1, r9, ":");
        str2 = regex_replace(str2, r9, ":");

        cout << "Data Set " << i << ": ";
        str1 == str2 ? cout << "equal\n\n" : cout << "not equal\n\n";
    }
}