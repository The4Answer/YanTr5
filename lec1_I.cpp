//#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <ctime>
//#include <json.hpp>


using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

struct st {
    int day;
    string month;
};

string months[] = { "January", "February", "March", "April", "May", "June", 
            "July", "August", "September", "October", "November", "December" };

string days[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
int year;
int startDay;

bool ifBigYear(int year);
void fillDays(map<string, int>& tDays, int& year, string& day_of_year);
void fillHolidays(vector<st>& holidays, map <string, int>& totalDay);
int findDay(string sDay);
int addDaysMonth(string month);

int main() {
    //read
    int n;
    cin >> n; 
    cin >> year;
    vector<st> holidays(n);
    for (int i = 0; i < n; ++i)
        cin >> holidays[i].day >> holidays[i].month;
    string day_of_year;
    cin >> day_of_year;
    
    //solution
    startDay = findDay(day_of_year);
    map <string, int> totalDays;
    fillDays(totalDays, year, day_of_year);
    fillHolidays(holidays, totalDays);

    //print
    auto minD = totalDays.begin();
    auto maxD = totalDays.begin();
    for (auto day = totalDays.begin(); day != totalDays.end(); day++) {
        if (day->second < minD->second) {
            minD = day;
        }
        if (day->second > maxD->second)
            maxD = day;
    }
    cout << maxD->first << " " << minD->first;

    return 0;
}

int findDay(string sDay) {
    for (int i = 0; i < 7; ++i)
        if (days[i] == sDay)
            return i;
}

bool ifBigYear(int year) {
    if (year % 400 == 0)
        return true;
    else if (year % 4 == 0 && year % 100 != 0)
        return true;
    return false;
}

void fillDays(map<string, int>& tDays, int& year, string& day_of_year) {
    for (int i = 0; i < 7; ++i) {
        if (day_of_year == days[i]) {
            tDays[days[i]] = 53;
        }else if (ifBigYear(year)) {
            if (i == 0 && day_of_year == days[6])
                tDays[days[i]] = 53;
            else if (i > 0 && day_of_year == days[i - 1])
                tDays[days[i]] = 53;
            else
                tDays[days[i]] = 52;
        }
        else {
            tDays[days[i]] = 52;
        }
        tDays[days[i]] += 400;
    }
    return;
}

void fillHolidays(vector<st>& holidays, map <string, int>& totalDay) {
    for (int i = 0; i < holidays.size(); ++i) {
        int _daysToHoli = 0;
        for (int j = 0; j < 12; ++j) {
            if (months[j] != holidays[i].month) {
                _daysToHoli += addDaysMonth(months[j]);
            }
            else {
                break;
            }
        }
        _daysToHoli += holidays[i].day;
        int delt = (startDay + _daysToHoli - 1) % 7;
        totalDay[days[delt]]--;
    }
    return;
}

int addDaysMonth(string month) {
    if (month == months[1])
        if (ifBigYear(year))
            return 29;
        else
            return 28;
    else if (month == months[3] || month == months[5] || month == months[8] || month == months[10])
        return 30;
    return 31;
}
