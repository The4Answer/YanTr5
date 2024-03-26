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
    map<string, int> m;
    string s;
    getline(cin, s);
    string t = "";
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
            m[t]++;
            t = "";
            continue;
        }
        t += s[i];
    }
    m[t]++;
    t = "";
    while (cin >> s) {
        t = "";
        for (int i = 0; i < s.size(); ++i) {
            t += s[i];
            auto find = m.find(t);
            if (find != m.end() || i == s.size() - 1) {
                cout << t << " ";
                break;
            }
        }
    }

    //solve
    

    return 0;
}
