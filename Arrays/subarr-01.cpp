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

int maxLen(int a[], int n)
{
    unordered_map<int, int> mp;
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == 0)
            a[i] = -1;
    }

    int sum = 0, mx = 0;
    for (i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum == 0)
        {
            mx = max(mx, i + 1);
        }
        if (mp.find(sum) == mp.end())
        {
            mp[sum] = i;
        }
        else
        {
            mx = max(mx, i - mp[sum]);
        }
    }
    return mx;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        int i, j, k, n, cnt = 0;
        cin >> n;
        int a[n];
        for0(i, n) cin >> a[i];
        cout << maxLen(a, n) << "\n";
    }

    return 0;
}