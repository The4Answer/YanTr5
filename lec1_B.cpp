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

int goalsNeeded(int totalNeeded, int firstAway, int secondAway, bool awaySecondGame);

int main() {
    string tmp;
    int goalsF1, goalsS1;
    cin >> tmp;
    goalsF1 = tmp[0] - '0', goalsS1 = tmp[2] - '0';
    int goalsF2, goalsS2;
    cin >> tmp;
    goalsF2 = tmp[0] - '0', goalsS2 = tmp[2] - '0';
    int away;
    cin >> away;
    int ans = 0;
    int need = (goalsS2 + goalsS1) - (goalsF1 + goalsF2);
    if (need < 0) {
        cout << 0;
        return 0;
    }
    if (away == 1)
        ans = goalsNeeded(need, goalsF2, goalsS1, true);
    else 
        ans = goalsNeeded(need, goalsF1, goalsS2, false);

    cout << ans;

    return 0;
}

int goalsNeeded(int totalNeeded, int firstAway, int secondAway, bool awaySecondGame) {
    if (awaySecondGame) {
        if (totalNeeded + firstAway > secondAway)
            return totalNeeded;
        else
            return totalNeeded + 1;
    }
    else {
        if (firstAway > secondAway)
            return totalNeeded;
        else
            return totalNeeded + 1;
    }
    return -1;
}
