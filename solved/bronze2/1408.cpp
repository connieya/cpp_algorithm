#include "bits/stdc++.h"

using namespace std;

typedef struct {
    int hour;
    int minute;
    int second;
} Time;

Time setTime(string time) {
    return Time{stoi(time.substr(0, 2)), stoi(time.substr(3, 2)), stoi(time.substr(6))};
}

void printResult(Time &result){
    string hh = to_string(result.hour);
    string mm = to_string(result.minute);
    string ss = to_string(result.second);

    hh = hh.length() == 1 ? '0'+hh : hh;
    mm = mm.length() == 1 ? '0'+mm : mm;
    ss = ss.length() == 1 ? '0'+ss : ss;

    cout << hh<<":"<<mm<<":"<<ss;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string currentTime, startTime;
    cin >> currentTime >> startTime;
    Time current = setTime(currentTime);
    Time start = setTime(startTime);

    Time result;
    result.second = start.second - current.second;
    if (result.second < 0){
        result.second += 60;
        start.minute--;
    }
    result.minute = start.minute - current.minute;
    if (result.minute < 0){
        result.minute += 60;
        start.hour--;
    }
    result.hour = start.hour-current.hour;
    if (result.hour < 0) {
        result.hour +=24;
    }
    printResult(result);
}