//https://leetcode.com/problems/delete-and-earn/

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

int deleteAndEarn(vector<int> &a)
{
    
    int i, mx = 0;
    unordered_map<int, int> mp;

    for (int x : a)
    {
        mp[x]++;
        mx = max(mx, x);
    }

    int dp[mx + 1];
    for (i = 0; i <= mx; i++)
        dp[i] = 0;

    dp[1] = mp[1];
    for (i = 2; i <= mx; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + mp[i] * i);
    }
    for (int x : dp)
        cout << x << " ";
    return dp[mx];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll n, i, j;
    vector<int> a;
    cin >> n;
    for0(i, n) cin >> j, a.pb(j);
    cout << deleteAndEarn(a) << "\n";

    return 0;
}