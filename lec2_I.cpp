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
    int i;
    int j;
};

bool cmp(st f, st s) {
    return f.i < s.i;
}

int main() {
    //read
    int n;
    cin >> n;
    vector<st> ships(n);
    vector<bool> used(n, false);
    vector<vector<int>> field(n);
    for (int i = 0; i < n; ++i)
        field[i].resize(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> ships[i].i >> ships[i].j;
        ships[i].i -= 1, ships[i].j -= 1;
        field[ships[i].i][ships[i].j] = 1;
    }
    
    //solve
    sort(ships.begin(), ships.end(), cmp);
    int ans = 100000000;
    for (int j = 0; j < n; ++j) { // looking for the best J
        vector<bool> copyU(n, false);
        copyU = used;
        int curAns = 0;
        for (int i = 0; i < n; ++i) {
            if (field[i][j] == 0) {
                for (int k = 0; k < n; ++k) {
                    if (!copyU[k]) {
                        copyU[k] = true;
                        if (ships[k].j == j) 
                            continue;
                        curAns += abs(i - ships[k].i) + abs(j - ships[k].j);
                        break;
                    }
                }
            }
        }
        ans = min(ans, curAns);
    }
    cout << ans;

    return 0;
}

