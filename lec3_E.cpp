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

void fill(map<int, int>& m) {
    int n;
    cin >> n;
    map<int, int> used;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        if (used[tmp] == 0)
            m[tmp]++;
        used[tmp]++;
    }
}

int main() {
    //read
    map<int, int> m;
    fill(m);
    fill(m);
    fill(m);

    //solve
    for (auto i = m.begin(); i != m.end(); ++i) 
        if (i->second > 1)
            cout << i->first << " ";

    return 0;
}
