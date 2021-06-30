//https://leetcode.com/problems/set-matrix-zeroes/

//author: _mayor
#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &a)
{
    int i, j, flag = 1;
    int r = a.size(), c = a[0].size();

    for (i = 0; i < r; i++)
    {
        if (a[i][0] == 0)
            flag = 0;
        for (j = 1; j < c; j++)
        {
            if (a[i][j] == 0)
            {
                a[i][0] = 0;
                a[0][j] = 0;
            }
        }
    }

    for (i = r - 1; i >= 0; i--)
    {
        for (j = c - 1; j >= 1; j--)
        {
            if (a[i][0] == 0 || a[0][j] == 0)
                a[i][j] = 0;
        }
        if (!flag)
            a[i][0] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    {
        ll i, j, k, n, cnt = 0;
    }

    return 0;
}