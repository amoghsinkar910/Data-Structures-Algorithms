//https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1#

//author:_mayor
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lessThanMid(vector<vector<int>> &a, int ele, int r, int c)
    {
        int l, h, i, cnt = 0;
        for (i = 0; i < r; i++)
        {
            l = 0, h = c - 1;
            while (l <= h)
            {
                int mid = (l + h) / 2;
                if (ele >= a[i][mid])
                {
                    cnt += mid - l + 1;
                    l = mid + 1;
                }
                else
                    h = mid - 1;
            }
        }
        return cnt;
    }
    int median(vector<vector<int>> &a, int r, int c)
    {
        int mx = 0, i, low, high;
        for (i = 0; i < r; i++)
            mx = max(mx, a[i][c - 1]);

        int median_pos = (r * c + 1) / 2;
        low = 1, high = mx;
        while (low < high)
        {
            int mid = (low + high) / 2;
            int cnt = lessThanMid(a, mid, r, c);
            if (cnt < median_pos)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return low;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        cout << obj.median(matrix, r, c) << endl;
    }
    return 0;
}