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
    int k;
    cin >> k;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < min(i + k + 1, n); ++j) {
            ans = max(ans, arr[j] - arr[i]);
        }
    }
    cout << ans;

    return 0;
}

