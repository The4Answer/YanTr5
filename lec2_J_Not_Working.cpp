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

int n, m;
bool checkIsGood(vector<vector<char>>& a);
void dfs(int I, int J, vector<vector<char>>& a, vector<vector<int>>& used);
void paint(int I, int J, vector<vector<char>>& a, vector<vector<int>>& used, int color);

int main() {
    //read
    cin >> n >> m;
    vector<vector<char>> a(n);
    for (int i = 0; i < n; ++i)
        a[i].resize(m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    //solve
    if (checkIsGood(a)) {
        //find solution
        vector<vector<int>> used(n);
        for (int i = 0; i < n; ++i)
            used[i].resize(m, 0);
        int islands = 0;
        int startI = 0 , startJ = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (used[i][j] == 0 && a[i][j] == '#') {
                    startI = i, startJ = j;
                    paint(i, j, a, used, islands);
                    islands++;
                }
            }
        }
        if (islands == 0)
            cout << "NO";
        else if (islands == 2) {
            cout << "YES" << "\n";
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j)
                    cout << a[i][j];
                cout << "\n";
            }
        }
        else {
            vector<vector<char>> arr;
            arr = a;
            cout << "YES" << "\n";
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (j == startJ && a[i][j] == 'a') {
                        arr[i][j] = 'b';
                    }
                }
            }
            bool checkA = false;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (arr[i][j] == 'a') {
                        checkA = true;
                    }
                }
            }
            if (checkA) {
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < m; ++j) {
                        if (j == startJ && a[i][j] == 'a') {
                            cout << 'b';
                        }
                        else {
                            cout << a[i][j];
                        }
                    }
                    cout << "\n";
                }
            }
            else {
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < m; ++j) {
                        if (i == startI && a[i][j] == 'a') {
                            cout << 'b';
                        }
                        else {
                            cout << a[i][j];
                        }
                    }
                    cout << "\n";
                }
            }
        }
    }
    else {
        //no solution
        cout << "NO";
    }

    return 0;
}

void paint(int I, int J, vector<vector<char>>& a, vector<vector<int>>& used, int color) {
    used[I][J] = 1;
    if (color == 0)
        a[I][J] = 'a';
    else
        a[I][J] = 'b';
    if (I > 0 && used[I - 1][J] == 0 && a[I - 1][J] == '#')
        paint(I - 1, J, a, used, color);
    if (J > 0 && used[I][J - 1] == 0 && a[I][J - 1] == '#')
        paint(I, J - 1, a, used, color);
    if (I + 1 < n && used[I + 1][J] == 0 && a[I + 1][J] == '#')
        paint(I + 1, J, a, used, color);
    if (J + 1 < m && used[I][J + 1] == 0 && a[I][J + 1] == '#')
        paint(I, J + 1, a, used, color);
}

void dfs(int I, int J, vector<vector<char>>& a, vector<vector<int>>& used) {
    used[I][J] = 1;
    if (I > 0 && used[I - 1][J] == 0 && a[I - 1][J] == '#')
        dfs(I - 1, J, a, used);
    if (J > 0 && used[I][J - 1] == 0 && a[I][J - 1] == '#')
        dfs(I, J - 1, a, used);
    if (I + 1 < n && used[I + 1][J] == 0 && a[I + 1][J] == '#')
        dfs(I + 1, J, a, used);
    if (J + 1 < m && used[I][J + 1] == 0 && a[I][J + 1] == '#')
        dfs(I, J + 1, a, used);
}

bool checkIsGood(vector<vector<char>>& a) {
    vector<vector<int>> used(n);
    for (int i = 0; i < n; ++i)
        used[i].resize(m, 0);
    int islands = 0;
    int countN = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '#')
                countN++;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (used[i][j] == 0 && a[i][j] == '#') {
                dfs(i, j, a, used);
                islands++;
            }
        }
    }
    if (countN < 2)
        return false;
    if (islands > 2)
        return false;
    return true;
}
