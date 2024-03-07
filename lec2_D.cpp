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
    int dSize = 8;
    cin >> n;
    vector<vector<int>> desk(dSize);
    for (int i = 0; i < dSize; ++i)
        desk[i].resize(dSize, 0);

    for (int i = 0; i < n; ++i) {
        int tmpI, tmpJ;
        cin >> tmpI >> tmpJ;
        desk[--tmpI][--tmpJ] = 1;
    }
    int P = n * 4;

    for (int i = 0; i < dSize; ++i) {
        for (int j = 0; j < dSize; ++j) {
            if (desk[i][j] == 1) {
                if (i > 0 && desk[i - 1][j] == 1)
                    P--;
                if (j > 0 && desk[i][j - 1] == 1)
                    P--;
                if (i + 1 < dSize && desk[i + 1][j] == 1)
                    P--;
                if (j + 1 < dSize && desk[i][j + 1] == 1)
                    P--;
            }
        }
    }
    cout << P;


    return 0;
}

