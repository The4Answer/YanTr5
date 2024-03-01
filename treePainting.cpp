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
    long long p, v;
    cin >> p >> v;
    long long q, m;
    cin >> q >> m;
    if (p > q) {
        swap(p, q);
        swap(v, m);
    }
    long long ans = v + m;
    long long first = (v + m + 2);
    long long second = (q - p + 1);
    if (first < second) {
        ans += first;
    }
    else {
        ans += second;
    }

    long long ans2 = 2 * v + 1;
    ans = max(ans, ans2);
    long long ans3 = 2 * m + 1;
    ans = max(ans, ans3);
    cout << ans;
    return 0;
}
