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
const ll INF = 1e15; //max value do not take 1e9 

vector<vector<ll>> g;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    {
        ll i, j, k, n, m, q;
        cin >> n >> m >> q;
        g.resize(n + 1);
        for (i = 0; i <= n; i++)
            g[i].resize(n + 1);

        //init
        for (i = 1; i <= n; i++)
            for (j = i + 1; j <= n; j++)
                g[i][j] = g[j][i] = INF;

        for0(i, m)
        {
            ll a, b, c;
            cin >> a >> b >> c;
            g[a][b] = g[b][a] = min(c, g[a][b]);
        }

        for (k = 1; k <= n; k++) //intermediate node
        {
            for (i = 1; i <= n; i++) //(i,j) node i and j
            {
                for (j = 1; j <= n; j++)
                {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }

        while (q--)
        {
            ll a, b;
            cin >> a >> b;
            if (g[a][b] == INF)
                g[a][b] = -1;
            cout << g[a][b] << "\n";
        }
    }

    return 0;
}