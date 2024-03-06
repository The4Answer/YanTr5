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
    int k;
    cin >> k;
    int lx = 1000000001, ly = 1000000001, rx = -1000000001, ry = -1000000001;
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        lx = min(lx, x);
        ly = min(ly, y);
        rx = max(rx, x);
        ry = max(ry, y);
    }
    cout << lx << " " << ly << " " << rx << " " << ry;

    return 0;
}

