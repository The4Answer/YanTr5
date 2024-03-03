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

long long calcActions(int spaces);

int main() {
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int spacesNeeded;
        cin >> spacesNeeded;
        ans += calcActions(spacesNeeded);
    }
    cout << ans;

    return 0;
}

long long calcActions(int spaces) {
    int semi = spaces / 4;
    if (spaces % 4 == 3)
        semi += 2;
    else
        semi += (spaces % 4);
    return semi;
}
