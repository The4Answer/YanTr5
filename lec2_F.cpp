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
    vector <int> arr(n);
    int Max = -1;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        Max = max(Max, arr[i]);
    }
    int a, b, k;
    cin >> a >> b >> k;

    //solve
    int ans = -1;
    for (int i = a; i <= b; i += max(1, k/2)) {
        int nPass = (i - 1) / k;
        nPass %= arr.size();
        ans = max(ans, arr[nPass]);
        if (nPass > 0)
            ans = max(ans, arr[n - nPass]);

        if (ans == Max)
            break;
    }
    cout << ans;

    return 0;
}

