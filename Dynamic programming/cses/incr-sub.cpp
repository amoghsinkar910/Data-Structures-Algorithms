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

//n^2 approach
ll LIS(ll a[], ll n)
{
    ll dp[n], i, j;
    dp[0] = 1;
    for (i = 1; i < n; i++)
    {
        dp[i] = 1;
        for (j = 0; j < i; j++)
        {
            if (a[i] > a[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
    }
    return *max_element(dp, dp + n);
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
        ll i, j, n;
        cin >> n;
        ll a[n];
        for0(i, n) cin >> a[i];

        //nlogn approach using binary seacrh
        //place the minimum element possible on its posn
        vll dp;
        for (i = 0; i < n; i++)
        {
            auto lb = lower_bound(dp.begin(), dp.end(), a[i]);
            if (lb == dp.end())
            {
                dp.pb(a[i]);
            }
            else
            {
                *lb = a[i];
            }
        }
        cout << dp.size() << "\n";
        //cout << LIS(a,n) << "\n";
    }

    return 0;
}