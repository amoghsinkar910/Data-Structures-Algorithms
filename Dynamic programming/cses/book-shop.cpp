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
        int i, j, n, tot;
        cin >> n >> tot;
        int c[n], pg[n]; //c->cost, p->pages
        for0(i, n) cin >> c[i];
        for0(i, n) cin >> pg[i];
        vector<vector<int>> dp(n + 1, vector<int>(tot + 1, 0));

        for (i = 0; i < n; i++)
        {
            for (j = 0; j <= tot; j++)
            {
                dp[i + 1][j] = dp[i][j];
                if (j - c[i] >= 0)
                {
                    dp[i + 1][j] = max(dp[i + 1][j], pg[i] + dp[i][j - c[i]]);
                }
            }
        }
        int ans = 0;
        for (i = 1; i <= tot; i++)
        {
            ans = max(ans, dp[n][i]);
        }
        cout << ans << "\n";
    }

    return 0;
}