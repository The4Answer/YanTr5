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
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        m[tmp]++;
    }
        
    //solve
    auto j = m.begin();
    auto i = m.begin();
    int Max = i->second;
    i++;
    for (auto kostil = m.end(); i != m.end(); ++i, ++j) {
        if (i->first - j->first < 2) {
            if (i->second + j->second > Max) {
                Max = i->second + j->second;
            }
        }
        if (i->second > Max) {
            Max = i->second;
        }
    }
    cout << n - Max;

    return 0;
}
