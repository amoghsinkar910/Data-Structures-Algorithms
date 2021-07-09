//https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#

//author: _mayor
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> path;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool check(int x, int y, int n, vector<vector<int>> &a, vector<vector<int>> &vis)
    {
        if (x >= 0 && x < n && y >= 0 && y < n && vis[x][y] == 0 && a[x][y] == 1)
            return true;
        return false;
    }

    void rec(int x, int y, int n, vector<vector<int>> &a, vector<vector<int>> &vis, string &s)
    {

        if (x == n - 1 && y == n - 1)
        {
            path.push_back(s);
            return;
        }

        vis[x][y] = 1;

        for (int k = 0; k < 4; k++)
        {
            int X = x + dx[k];
            int Y = y + dy[k];
            if (check(X, Y, n, a, vis))
            {
                if (dx[k] == 0 && dy[k] == 1)
                    s += 'R';
                else if (dx[k] == 0 && dy[k] == -1)
                    s += 'L';
                else if (dx[k] == 1 && dy[k] == 0)
                    s += 'D';
                else if (dx[k] == -1 && dy[k] == 0)
                    s += 'U';
                rec(X, Y, n, a, vis, s);
                s.pop_back();
            }
        }

        vis[x][y] = 0;
    }

    vector<string> findPath(vector<vector<int>> &a, int n)
    {
        string s;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        if (a.size() && a[0][0])
            rec(0, 0, n, a, vis, s);
        sort(path.begin(), path.end());
        return path;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// class Solution
// {
// public:
//     vector<string> path;

//     bool check(int x, int y, int n, vector<vector<int>> &a, vector<vector<int>> &vis)
//     {
//         if (x >= 0 && x < n && y >= 0 && y < n && vis[x][y] == 0 && a[x][y] == 1)
//             return true;
//         return false;
//     }

//     void rec(int x, int y, int n, vector<vector<int>> &a, vector<vector<int>> &vis, string &s)
//     {
//         if (x == -1 || x == n || y == -1 || y == n || a[x][y] == 0 || vis[x][y] == 1)
//             return;

//         if (x == n - 1 && y == n - 1)
//         {
//             path.push_back(s);
//             return;
//         }

//         vis[x][y] = 1;

//         if (check(x + 1, y, n, a, vis))
//         {
//             s.push_back('D');
//             rec(x + 1, y, n, a, vis, s);
//             s.pop_back();
//         }

//         if (check(x - 1, y, n, a, vis))
//         {
//             s.push_back('U');
//             rec(x - 1, y, n, a, vis, s);
//             s.pop_back();
//         }

//         if (check(x, y - 1, n, a, vis))
//         {
//             s.push_back('L');
//             rec(x, y - 1, n, a, vis, s);
//             s.pop_back();
//         }

//         if (check(x, y + 1, n, a, vis))
//         {
//             s.push_back('R');
//             rec(x, y + 1, n, a, vis, s);
//             s.pop_back();
//         }

//         vis[x][y] = 0;
//     }

//     vector<string> findPath(vector<vector<int>> &a, int n)
//     {
//         string s;
//         vector<vector<int>> vis(n, vector<int>(n, 0));

//         rec(0, 0, n, a, vis, s);
//         sort(path.begin(), path.end());
//         return path;
//     }
// };

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         vector<vector<int>> m(n, vector<int>(n, 0));
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 cin >> m[i][j];
//             }
//         }
//         Solution obj;
//         vector<string> result = obj.findPath(m, n);
//         if (result.size() == 0)
//             cout << -1;
//         else
//             for (int i = 0; i < result.size(); i++)
//                 cout << result[i] << " ";
//         cout << endl;
//     }
//     return 0;
// }