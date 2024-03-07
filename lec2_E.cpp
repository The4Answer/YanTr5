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

struct st {
    int up;
    int down;
};

int main() {
    int n;
    cin >> n;
    vector <st> arr(n);
    vector<int> used(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i].up >> arr[i].down;

    //+
    st lastP;
    lastP.up = 1, lastP.down = 0;
    int lastIdP = -1;
    for (int i = 0; i < n; ++i) {
        if (arr[i].up > arr[i].down && arr[i].down > lastP.down) {
            lastP = arr[i];
            lastIdP = i;
        }
    }
    //-
    st lastM;
    lastM.up = 0, lastM.down = 0;
    int lastIdM = -1;
    for (int i = 0; i < n; ++i) {
        if (arr[i].up <= arr[i].down && arr[i].up > lastM.up) {
            lastM = arr[i];
            lastIdM = i;
        }
    }

    //sol
    long long cur = 0;
    long long _max = 0;
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (arr[i].up > arr[i].down && i != lastIdP) {
            cur += arr[i].up;
            _max = max(_max, cur);
            cur -= arr[i].down;
            used[i] = 1;
            ans.push_back(i + 1);
        }
    }
    if (lastIdP > -1) {
        cur += lastP.up;
        _max = max(_max, cur);
        cur -= lastP.down;
        used[lastIdP] = 1;
        ans.push_back(lastIdP + 1);
    }
    if (lastIdM > -1) {
        cur += lastM.up;
        _max = max(_max, cur);
        cur -= lastM.down;
        used[lastIdM] = 1;
        ans.push_back(lastIdM + 1);
    }
    for (int i = 0; i < n; ++i) {
        if (used[i] != 1)
            ans.push_back(i + 1);
    }
    cout << _max << "\n";
    for (int i = 0; i < n; ++i)
        cout << ans[i] << " ";

    return 0;
}

