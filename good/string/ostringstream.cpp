#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ostringstream out;
    out << "Hello World!" << '\n';
    out << setw(5) << setfill('0') << 123 << '\n';
    cout << out.str();
    out << fixed << setprecision(10) << 123.456789 << '\n';
    cout << out.str();
}