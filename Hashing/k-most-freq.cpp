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

vector<ll> kMostFreq(ll a[], ll n, ll k)
{
    vector<ll> ans;
    int br = 0;
    ll cnt = 0;
    unordered_map<int, int> m;
    ll i;
    for0(i, n)
    {
        m[a[i]]++;
    }
    vector<ll> f[n + 1];
    for (auto it : m)
    {
        f[it.second].push_back(it.first);
    }
    for (i = n; i >= 0; i--)
    {
        for (auto x : f[i])
        {
            ans.pb(x);
            cnt++;
            if (cnt == k)
            {
                br = 1;
                break;
            }
        }
        if (br == 1)
            break;
    }
    return ans;
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
        ll i, j, k, n, cnt = 0;
        cin >> n >> k;
        ll a[n];
        for0(i, n) cin >> a[i];
        vector<ll> ans = kMostFreq(a, n, k);
        for (auto it : ans)
            cout << it << " ";
        cout << "\n";
    }

    return 0;
}