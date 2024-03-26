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



int main() {
    //read
    int n;
    cin >> n;

    map<pair<int, int>, int> table;
    for (int i = 0; i < n; ++i) {
        pair<int,int> tmp;
        cin >> tmp.first >> tmp.second;
        table[tmp]++;
    }

    //solve
    int Max = 5;
    vector<pair<int, int>> ans;
    for (auto i = table.begin(); i != table.end(); ++i) {
        for (auto j = table.begin(); j != table.end(); ++j) {
            if (i != j) {
                int _i = j->first.first - i->first.first;
                int _j = j->first.second - i->first.second;
                pair<int, int> check1;
                pair<int, int> check2;
                auto _ch1 = table.begin();
                auto _ch2 = table.begin();
                if (abs(_i) == abs(_j)) {
                    check1.first = j->first.first;
                    check1.second = i->first.second;
                    check2.first = i->first.first;
                    check2.second = j->first.second;
                    _ch1 = table.find(check1);
                    _ch2 = table.find(check2);
                }
                else if (_i == 0) {
                    check1.first = i->first.first + _j;
                    check1.second = i->first.second;
                    check2.first = j->first.first + _j;
                    check2.second = j->first.second;
                    _ch1 = table.find(check1);
                    _ch2 = table.find(check2);
                }
                else if (_j == 0) {
                    check1.first = j->first.first;
                    check1.second = i->first.second + _i;
                    check2.first = i->first.first;
                    check2.second = j->first.second + _i;
                    _ch1 = table.find(check1);
                    _ch2 = table.find(check2);
                }
                else
                    continue;
                /// ///////////////////////
                if (_ch1 == table.end() && _ch2 == table.end() && Max > 2) {
                    Max = 2;
                    ans.resize(0);
                    ans.push_back(check1);
                    ans.push_back(check2);
                }
                else if (_ch1 != table.end() && _ch2 != table.end()) {
                    cout << 0;
                    return 0;
                }
                else if (_ch1 == table.end() && _ch2 != table.end() && Max > 1) {
                    Max = 1;
                    ans.resize(0);
                    ans.push_back(check1);
                }
                else if (_ch2 == table.end() && _ch1 != table.end() && Max > 1) {
                    Max = 1;
                    ans.resize(0);
                    ans.push_back(check2);
                }
            }
        }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }

    return 0;
}
