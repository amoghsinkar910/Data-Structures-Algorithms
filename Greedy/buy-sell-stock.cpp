//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

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

int maxProfit(vector<int> &p)
{
    int i, n = p.size();
    int mn = INT_MAX, mx = 0;

    for (i = 0; i < n; i++)
    {
        if (p[i] < mn)
            mn = p[i];
        else if (p[i] - mn > mx)
            mx = p[i] - mn;
    }

    return mx;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int i, j, k, n, cnt = 0;
    cin >> n;
    vector<int> p;
    for0(i, n) cin >> k, p.pb(k);

    cout << maxProfit(p) < '\n';

    return 0;
}