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

vector<int> a;

long long findL(long long l, long long r, int targ) {
    while (l < r) {
        long long mid = (r + l) / 2;
        if (a[mid] >= targ)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}
long long findR(long long l, long long r, int targ) {
    while (l < r) {
        long long mid = (r + l + 1) / 2;
        if (a[mid] <= targ)
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}

int main() {
    //read
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    //solve
    sort(a.begin(), a.end());
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        long long l, r;
        cin >> l >> r;
        long long id1 = findL(0, n - 1, l);      //left included
        long long id2 = findR(0, n - 1, r);      //right inc
        if (a[id1] >= l && a[id2] <= r)
            cout << id2 - id1 + 1 << " ";
        else
            cout << 0 << " ";
    }

    return 0;
}
