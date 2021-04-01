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

ll a[5005][5005];

//top-down
ll rec(string s1, string s2, ll i, ll j)
{
    ll ans;
    if (i == s1.size())
        return int(s2.size()) - j;
    if (j == s2.size())
        return int(s1.size()) - i;
    if (i == s1.size() && j == s2.size())
        return 0;

    if (a[i][j] != -1)
        return a[i][j];
    if (s1[i] == s2[j])
        return rec(s1, s2, i + 1, j + 1);
    else
    {
        ll x = rec(s1, s2, i + 1, j);
        ll y = rec(s1, s2, i, j + 1);
        ll z = rec(s1, s2, i + 1, j + 1);
        ans = 1 + min(x, min(y, z));
    }
    return a[i][j] = ans;
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
    {
        ll i, j, n, m;
        string s1, s2;
        cin >> s1 >> s2;
        n = s1.size(), m = s2.size();
        ll dp[n + 1][m + 1];
        memset(a, -1, sizeof(a));

        //bottom-up
        for (i = 0; i <= n; i++)
        {
            for (j = 0; j <= m; j++)
            {
                if (i == 0)
                    dp[i][j] = j;
                else if (j == 0)
                    dp[i][j] = i;
                else if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                {
                    dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
                }
            }
        }

        cout << dp[n][m] << "\n";
        //cout << rec(s1, s2, 0, 0) << "\n";
    }

    return 0;
}