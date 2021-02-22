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

const ll N = 1e5 + 5;
const ll mod = 1e9 + 7;
const ll INF = 1e9;

int vis[305][305];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int i, int j, vector<vector<int>> &a)
{
    vis[i][j] = 1;
    int n = a.size();
    int m = a[0].size();
    int x, y;
    for (int k = 0; k < 4; k++)
    {
        x = dx[k] + i;
        y = dy[k] + j;
        if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == 1 && !vis[x][y])
        {
            dfs(x, y, a);
        }
    }
}

int numIslands(vector<vector<int>> &a)
{
    int i, j, cnt = 0;
    int n = a.size();
    int m = a[0].size();

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            vis[i][j] = 0;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i][j] == 1 && !vis[i][j])
            {
                dfs(i, j, a);
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    {
        int i, j, k, n, m, cnt = 0;
        cin>>n>>m;
        vector<vector<int>> a(n,vector<int>(m,0));
        for0(i,n) for0(j,m) cin>>a[i][j];
        cout << numIslands(a) << "\n";
    }

    return 0;
}