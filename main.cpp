#include "bits/stdc++.h"
#define INF 50001
using namespace std;

string get_compiler_info() {
    stringstream  str;

#if defined(__clang__)
    str << "clang" << __clang_major__ << '.' << __clang_major__ << '.' << __clang_patchlevel__;
#elif defined(__GNUC__) && !defined(__ICC)
    str << "gcc " << __GNUC__ << '.' << __GNUC_MINOR__ << '.' << __GNUC__PATCHLEVEL__;
#elif definded(_MSC_VER)
    str << "msvc " << _MSC_VER;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout << getcom
}