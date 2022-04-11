#include "bits/stdc++.h"

using namespace std;

struct Person {
    string name;
    int day;
    int month;
    int year;

    Person(string n, int d, int m, int y) {
        name = n;
        day = d;
        month = m;
        year = y;
    }

};

bool compare(const Person &p1, const Person &p2) {
    if (p1.year == p2.year){
        if (p1.month == p2.month) return p1.day >  p2.day;
        return p1.month > p2.month;
    }
    return p1.year > p2.year;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, day, month, year;
    string name, old, young;
    cin >> n;
    vector<Person> people;
    for (int i =0; i< n; i++) {
        cin >> name >> day >> month >> year;
        people.push_back(Person(name, day, month, year));
    }
    sort(people.begin(), people.end(), compare);
    cout << people[0].name << '\n' << people[n-1].name;
}