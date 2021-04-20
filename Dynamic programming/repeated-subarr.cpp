//https://leetcode.com/problems/maximum-length-of-repeated-subarray/

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

int findLength(vector<int> &a, vector<int> &b)
{
    int i, j, n1 = a.size(), n2 = b.size();
    int dp[n1 + 1][n2 + 1];
    int ans = 0;

    for (i = 0; i <= n1; i++)
    {
        for (j = 0; j <= n2; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (i = 1; i <= n1; i++)
    {
        for (j = 1; j <= n2; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                ans = max(ans, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    {
        ll i, j, k, n, m, cnt = 0;
        cin >> n >> m;
        vector<int> a, b;
        for0(i, n) cin >> j, a.pb(j);
        for0(i, m) cin >> j, b.pb(j);
        cout << findLength(a, b) << "\n";
    }

    return 0;
}