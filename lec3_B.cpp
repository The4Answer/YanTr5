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
    string s, t;
    cin >> s >> t;
    map<char, int> m;

    //solve
    for (int i = 0; i < s.size(); ++i)
        m[s[i]]++;
    for (int i = 0; i < t.size(); ++i)
        m[t[i]]--;

    for (auto i = m.begin(); i != m.end(); ++i)
        if (i->second != 0) {
            cout << "NO";
            return 0;
        }
    cout << "YES";

    return 0;
}
