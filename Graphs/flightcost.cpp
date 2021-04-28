//https://leetcode.com/problems/cheapest-flights-within-k-stops/

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

int ans = INT_MAX;
void dfs(int s, int d, int k, int n, int cost, vector<int> &vis, vector<pair<int, int>> adj[])
{
    if (ans < cost)
        return;
    if ((s == d) || (s == d && k == -1))
        ans = cost;
    if (k < 0)
        return;
    vis[s] = 1;
    for (auto v : adj[s])
    {
        if (!vis[v.first])
        {
            dfs(v.first, d, k - 1, n, cost + v.second, vis, adj);
        }
    }
    vis[s] = 0;
}

int findCheapestPrice(int n, vector<vector<int>> &a, int src, int dst, int k)
{
    vector<pair<int, int>> adj[n];
    vector<int> vis(n, 0);
    for (int i = 0; i < a.size(); i++)
    {
        adj[a[i][0]].push_back({a[i][1], a[i][2]});
    }
    dfs(src, dst, k, n, 0, vis, adj);
    if (ans == INT_MAX)
        return -1;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    {
        ll i, j, k, n, cnt = 0;
        //findCheapestPrice()
    }

    return 0;
}