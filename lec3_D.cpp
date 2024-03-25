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
    int k;
    cin >> n >> k;
    map<int, int> m;
    for (int i = 1; i <= n; ++i) {
        int tmp;
        cin >> tmp;
        if (m[tmp] != 0 && i - m[tmp] <= k) {
            cout << "YES";
            return 0;
        }
        m[tmp] = i;
    }
        
    //solve
    cout << "NO";

    return 0;
}
