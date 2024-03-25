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
    map<string, int> m;
    int counter = 0;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        for (int j = 0; j < tmp; ++j) {
            string name;
            cin >> name;
            m[name]++;
            if (m[name] == n)
                counter++;
        }
    }

    //solve
    cout << counter << "\n";
    for (auto i = m.begin(); i != m.end(); ++i)
        if (i->second == n)
            cout << i->first << " "; 

    return 0;
}
