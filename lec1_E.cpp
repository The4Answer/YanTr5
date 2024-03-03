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
    long long n, k, d;
    cin >> n >> k >> d;
    long long x = n * 10;
    bool isGood = false;
    for (int i = 0; i < 10; ++i) {
        if ((x + i) % k == 0) {
            x += i;
            isGood = true;
            d--;
            break;
        }
    }
    if (!isGood) {
        cout << -1;
        return 0;
    }
    cout << x;
    for (int i = 0; i < d; ++i)
        cout << 0;

    return 0;
}

