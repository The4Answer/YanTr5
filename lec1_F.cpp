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
    int n;
    cin >> n;
    int ind = -1;
    const long long inf = 100000000000;
    vector<long long> a(n);
    vector<char> ans(n, '#');
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        if (a[i] % 2 != 0 && ind == -1)
            ind = i;
    }
    long long cur = inf;
    for (int i = 1; i < n; ++i) {
        if (i - 1 == ind) {
            cur = a[i];
        }
        else {
            if (cur == inf)
                cur = a[i - 1];
            if (i == ind) {
                if (cur % 2 == 0) {
                    ans[i] = '+';
                }
                else {
                    ans[i] = 'x';
                }
            }
            else {
                cur = (cur * a[i]);
                cur = cur % 1000000000;
                ans[i] = 'x';
            }
        }
    }
    if (ind + 1 < n) {
        if (cur % 2 == 0) {
            ans[ind + 1] = '+';
        }
        else {
            ans[ind + 1] = 'x';
        }
    }

    for (int i = 1; i < n; ++i)
        cout << ans[i];

    return 0;
}

