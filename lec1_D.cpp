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

void markB(vector<vector<char>> &arr, vector<vector<int>>& used, int I, int J);
void markR(vector<vector<char>> &arr, vector<vector<int>>& used, int I, int J);

int main() {
    vector<vector<char>> arr(8);
    vector<vector<int>> used(8);
    for (int i = 0; i < 8; ++i) {
        arr[i].resize(8);
        used[i].resize(8, 0);
    }

    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            cin >> arr[i][j];

    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            if (arr[i][j] == 'B')
                markB(arr, used, i, j);
            else if (arr[i][j] == 'R')
                markR(arr, used, i, j);
            else
                continue;
                
    int ans = 0;
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            if (used[i][j] == 0)
                ans++;

    cout << ans;

    return 0;
}

void markB(vector<vector<char>>& arr, vector<vector<int>>& used, int I, int J) {
    used[I][J] = 1;
    int i = I, j = J;
    //left_up
    while (i - 1 >= 0 && j - 1 >= 0) {
        i--, j--;
        if (arr[i][j] == '*')
            used[i][j] = 1;
        else
            break;
    }
    //left_down
    i = I, j = J;
    while (i + 1 < 8 && j - 1 >= 0) {
        i++, j--;
        if (arr[i][j] == '*')
            used[i][j] = 1;
        else
            break;
    }
    //right_up
    i = I, j = J;
    while (i - 1 >= 0 && j + 1 < 8) {
        i--, j++;
        if (arr[i][j] == '*')
            used[i][j] = 1;
        else
            break;
    }
    //right_down
    i = I, j = J;
    while (i + 1 < 8 && j + 1 < 8) {
        i++, j++;
        if (arr[i][j] == '*')
            used[i][j] = 1;
        else
            break;
    }
}


void markR(vector<vector<char>>& arr, vector<vector<int>>& used, int I, int J) {
    used[I][J] = 1;
    //up
    int i = I, j = J;
    while (i - 1 >= 0) {
        i--;
        if (arr[i][j] == '*')
            used[i][j] = 1;
        else
            break;
    }
    //left
    i = I, j = J;
    while (j - 1 >= 0) {
        j--;
        if (arr[i][j] == '*')
            used[i][j] = 1;
        else
            break;
    }
    //right
    i = I, j = J;
    while (j + 1 < 8) {
        j++;
        if (arr[i][j] == '*')
            used[i][j] = 1;
        else
            break;
    }
    //down
    i = I, j = J;
    while (i + 1 < 8) {
        i++;
        if (arr[i][j] == '*')
            used[i][j] = 1;
        else
            break;
    }
}
