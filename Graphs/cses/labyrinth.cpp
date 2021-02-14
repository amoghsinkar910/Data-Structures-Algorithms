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

const ll N = 1e3 + 5;
char a[N][N];
ll vis[N][N], pr[N][N], n, m;
ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, 1, 0, -1};
queue<pair<ll, ll>> q;
string pat = "URDL";

void bfs(pair<ll, ll> c)
{
    ll i;
    vis[c.fi][c.se] = 1;
    q.push(c);
    while (!q.empty())
    {
        pair<ll, ll> p = q.front();
        q.pop();
        for0(i, 4)
        {
            ll x = p.fi + dx[i];
            ll y = p.se + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && (a[x][y] == '.' || a[x][y] == 'B') && vis[x][y] == 0)
            {
                vis[x][y] = 1;
                q.push({x, y});
                pr[x][y] = i;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll i, j;
    pair<ll, ll> start, end;
    cin >> n >> m;
    for0(i, n)
    {
        for0(j, m)
        {
            cin >> a[i][j];
            if (a[i][j] == 'A')
                start = {i, j};
            else if (a[i][j] == 'B')
                end = {i, j};
        }
    }

    bfs(start);

    //path print
    if (vis[end.fi][end.se] == 1)
    {
        vll ans;
        while (end != start)
        {
            ll dir = pr[end.fi][end.se];
            ans.pb(dir);
            end = {end.fi - dx[dir], end.se - dy[dir]};
        }
        reverse(ans.begin(), ans.end());

        cout << "YES" << endl;
        cout << ans.size() << endl;
        for (auto it : ans)
        {
            cout << pat[it];
        }
        cout << "\n";
    }
    else
    {
        cout << "NO"
             << "\n";
    }

    return 0;
}