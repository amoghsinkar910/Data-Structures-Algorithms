//https://leetcode.com/problems/non-overlapping-intervals/

//author: _mayor
#include <bits/stdc++.h>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>> &a)
{
    sort(a.begin(), a.end());
    int i, start = a[0][0], end = a[0][1], cnt = 0;
    for (i = 1; i < a.size(); i++)
    {
        if (a[i][0] < end)
        {
            cnt++;
            end = min(end, a[i][1]);
        }
        else
        {
            start = a[i][0];
            end = a[i][1];
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int i, n, x, y;
    cin >> n;
    vector<vector<int>> a(n);
    for (i = 0; i < n; i++)
    {
        cin >> x >> y;
        a[i].push_back(x);
        a[i].push_back(y);
    }

    cout << eraseOverlapIntervals(a) << "\n";

    return 0;
}