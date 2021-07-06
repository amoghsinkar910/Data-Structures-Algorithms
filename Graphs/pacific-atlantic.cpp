//https://leetcode.com/problems/pacific-atlantic-water-flow/

//author: _mayor
#include <bits/stdc++.h>

#define for0(i, n) for (long long i = 0; i < n; i++)
#define for1(i, n) for (long long i = 1; i <= n; i++)
#define forc(i, l, r) for (long long i = l; i <= r; ++i)
#define forr0(i, n) for (long long i = n - 1; i >= 0; i--)
#define forr1(i, n) for (long long i = n; i >= 1; i--)

#define pb push_back
#define fi first
#define se second

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef long long int lli;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

//traversing in reverse i.e. from ocean to the coordinate (u,v)
//so proceed only if height of next block is higher than curr block
void dfs(int u, int v, vector<vector<int>> &a, vector<vector<bool>> &vis)
{
    int i, x, y, n = a.size(), m = a[0].size();
    vis[u][v] = 1;
    for (i = 0; i < 4; i++)
    {
        x = u + dx[i];
        y = v + dy[i];
        if (x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == 0 && a[x][y] >= a[u][v])
        {
            dfs(x, y, a, vis);
        }
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>> &a)
{
    vector<vector<int>> ans;
    int n = a.size(), m = a[0].size(), i, j, k;

    vector<vector<bool>> p(n, vector<bool>(m, false));
    vector<vector<bool>> at(n, vector<bool>(m, false));

    for (i = 0; i < n; i++)
    {
        dfs(i, 0, a, p);
        dfs(i, m - 1, a, at);
    }

    for (i = 0; i < m; i++)
    {
        dfs(0, i, a, p);
        dfs(n - 1, i, a, at);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (p[i][j] && at[i][j])
            {
                ans.push_back({i, j});
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll i, j, k, n, cnt = 0;


    return 0;
}