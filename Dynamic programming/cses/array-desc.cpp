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

ll dp[N][105];

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
        ll i, j, n, m;
        cin >> n >> m;
        ll a[n]; // 0<=a[i]<=m
        for0(i, n) cin >> a[i];

        if (a[0] == 0)
        {
            fill(dp[0], dp[0] + 101, 1);
        }
        else
        {
            dp[0][a[0]] = 1;
        }

        for (i = 1; i < n; i++)
        {
            if (a[i] == 0)
            {
                for (j = 1; j <= m; j++)
                {
                    dp[i][j] += dp[i - 1][j];
                    if (j - 1 > 0)
                        dp[i][j] += dp[i - 1][j - 1];
                    if (j + 1 <= m)
                        dp[i][j] += dp[i - 1][j + 1];
                    dp[i][j] %= mod;
                }
            }
            else
            {
                dp[i][a[i]] += dp[i - 1][a[i]];
                if (a[i] - 1 > 0)
                    dp[i][a[i]] += dp[i - 1][a[i] - 1];
                if (a[i] + 1 <= m)
                    dp[i][a[i]] += dp[i - 1][a[i] + 1];
                dp[i][a[i]] %= mod;
            }
        }
        ll ans = 0;
        for (i = 1; i <= m; i++)
        {
            ans += dp[n - 1][i];
            ans %= mod;
        }
        cout << ans << "\n";
    }

    return 0;
}