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
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        int ans = 0;
        vector<int> ansL;
        int curL = 1;
        int maxL = 0;
        cin >> maxL;
        for (int j = 1; j < n; ++j) {
            int tmp;
            cin >> tmp;
            if (min(maxL, tmp) < curL + 1) {
                maxL = tmp;
                ansL.push_back(curL);
                curL = 1;
                ans++;
            }
            else {
                maxL = min(maxL, tmp);
                curL++;
            }
        }
        ans++;
        ansL.push_back(curL);
        cout << ans << "\n";
        for (int j = 0; j < ans; ++j)
            cout << ansL[j] << " ";
        cout << "\n";
    }
    

    return 0;
}

