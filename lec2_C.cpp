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
    int sum = 0;
    int _max = 0;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        _max = max(_max, tmp);
        sum += tmp;
    }
    if (sum - _max < _max) {
        cout << 2*_max - sum;
    }
    else {
        cout << sum;
    }

    return 0;
}

