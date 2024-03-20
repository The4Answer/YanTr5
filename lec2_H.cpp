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
    int val;
};

int main() {
    //read
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; ++i)
        a[i].resize(m);

    st max1, max2J, max2I;
    max1.val = 0, max2J.val = 0, max2I.val = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (a[i][j] > max1.val) {
                max1.i = i, max1.j = j;
                max1.val = a[i][j];
            }
        }
    }

    //solve
                                        // max1 - i
    //find max2
    for (int i = 0; i < n; ++i) {
        if (i != max1.i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] > max2J.val) {
                    max2J.i = i, max2J.j = j;
                    max2J.val = a[i][j];
                }
            }
        }
    }
    //check
    int maxAns1 = 0;
    for (int i = 0; i < n; ++i) {
        if (i != max1.i) {
            for (int j = 0; j < m; ++j) {
                if (j != max2J.j) {
                    maxAns1 = max(maxAns1, a[i][j]);
                }
            }
        }
    }

                                           //max1 - j
    //find another max2
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (max1.j != j) {
                if (a[i][j] > max2I.val) {
                    max2I.i = i, max2I.j = j;
                    max2I.val = a[i][j];
                }
            }
        }
    }
    //check
    int maxAns2 = 0;
    for (int i = 0; i < n; ++i) {
        if (i != max2I.i) {
            for (int j = 0; j < m; ++j) {
                if (j != max1.j) {
                    maxAns2 = max(maxAns2, a[i][j]);
                }
            }
        }
    }
    if (maxAns1 < maxAns2) {
        cout << max1.i + 1 << " " << max2J.j + 1;
    }
    else {
        cout << max2I.i + 1 << " " << max1.j + 1;
    }

    return 0;
}

