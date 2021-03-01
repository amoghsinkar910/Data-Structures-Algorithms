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

bool increasingTriplet(vector<int> &a)
{
    int n = int(a.size());
    int left = INT_MAX, mid = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < left)
        {
            left = a[i];
        }
        else if (a[i] > left && a[i] < mid)
        {
            mid = a[i];
        }
        else if (a[i] > mid)
        {
            return true;
        }
    }
    return false;
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
        vector<int> a;
        for0(i, n) cin >> k, a.pb(k);
        cout << increasingTriplet(a) << "\n";
    }

    return 0;
}