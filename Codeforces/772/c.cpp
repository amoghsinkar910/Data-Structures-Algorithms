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

const ll MAXN = 1e5 + 5;
const ll mod = 1e9 + 7;
const ll INF = 1e9;

vector<int> gr[MAXN];
int L[MAXN], R[MAXN];

ll dp[MAXN][2];

void dfs(int node, int par = -1)
{
    dp[node][0] = dp[node][1] = 0;
    for (int nxt : gr[node])
    {
        if (nxt == par)
            continue;

        dfs(nxt, node);

        dp[node][0] += max(abs(L[node] - L[nxt]) + dp[nxt][0], abs(L[node] - R[nxt]) + dp[nxt][1]);
        dp[node][1] += max(abs(R[node] - L[nxt]) + dp[nxt][0], abs(R[node] - R[nxt]) + dp[nxt][1]);
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
    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            gr[i].clear();
            cin >> L[i] >> R[i];
        }

        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            gr[u].pb(v);
            gr[v].pb(u);
        }
        dfs(0);

        cout << max(dp[0][0], dp[0][1])<<"\n";
    }

    return 0;
}