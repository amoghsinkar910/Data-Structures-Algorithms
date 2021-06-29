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

vector<int> xorQueries(vector<int> &a, vector<vector<int>> &q)
{
    int i, n = a.size(), m = q.size(), x = 0;
    int l, r;
    vector<int> ans, pref;
    for (i = 0; i < n; i++)
    {
        x ^= a[i];
        pref.push_back(x);
    }
    for (i = 0; i < m; i++)
    {
        l = q[i][0];
        r = q[i][1];
        if (l == 0)
        {
            ans.push_back(pref[r]);
        }
        else
        {
            ans.push_back(pref[r] ^ pref[l - 1]);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll i, j, k, n, cnt = 0;
    cin >> n >> k;
    vector<int> a, fin;
    vector<vector<int>> q(k);
    for0(i, n)
    {
        cin >> j;
        a.pb(j);
    }

    for0(i, k)
    {
        int x, y;
        cin >> x >> y;
        q[i].pb(x);
        q[i].pb(y);
    }
    fin = xorQueries(a, q);
    for (auto it : fin)
        cout << it << " ";
    cout << "\n";
    return 0;
}