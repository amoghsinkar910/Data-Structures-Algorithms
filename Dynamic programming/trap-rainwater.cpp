//https://leetcode.com/problems/trapping-rain-water/

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

int trap(vector<int> &a)
{
    int i, j, n = a.size();
    if (!n)
        return 0;
    int l[n], r[n];
    l[0] = a[0];
    r[n - 1] = a[n - 1];

    for (i = 1; i < n; i++)
    {
        l[i] = max(a[i], l[i - 1]);
    }

    for (i = n - 2; i >= 0; i--)
    {
        r[i] = max(a[i], r[i + 1]);
    }

    int ans = 0;
    for (i = 1; i < n - 1; i++)
    {
        ans += min(l[i], r[i]) - a[i];
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll i, j, k, n, cnt = 0;
    vector<int> a;
    for (i = 0; i < n; i++)
    {
        cin >> j;
        a.push_back(j);
    }
    cout << trap(a) << "\n";

    return 0;
}