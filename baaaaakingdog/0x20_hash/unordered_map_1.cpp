#include "iostream"
#include "string"
#include "unordered_map"

using namespace std;

int main() {
    unordered_map<string, double> mymap = {
            {"mom", 5.6},
            {"dad", 3.4},
            {"bro", 6.7}
    };
    string input;
    cout << "who?";
    getline(cin, input);

    unordered_map<string, double>::const_iterator got = mymap.find(input);
    if (got == mymap.end()) {
        cout << "not found";
    } else {
        cout << got->first << " is " << got->second;

        cout << '\n';
    }
}