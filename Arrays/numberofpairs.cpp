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

int helper(int x, int y[], int n, int excep[])
{
    if (x == 0)
        return 0;
    if (x == 1)
        return excep[0];
    int *it = upper_bound(y, y + n, x);
    int cnt = (y + n) - it;
    cnt += excep[0] + excep[1];

    if (x == 2)
        cnt -= (excep[3] + excep[4]);
    if (x == 3)
        cnt += excep[2];
    return cnt;
}

ll countPairs(int x[], int y[], int m, int n)
{
    // x^y > y^x iff x<y, but it has some exceptions such as 1^0 > 0^1 whereas 1>0
    // so we subtract such exceptions {(1,0),(2,3),(2,4)}
    int excep[5] = {0};
    int i = 0;
    for (i = 0; i < n; i++)
        if (y[i] < 5)
            excep[y[i]]++;

    sort(y, y + n);
    ll ans = 0;
    for (i = 0; i < m; i++)
    {
        ans += helper(x[i], y, n, excep);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    {
        int i, j, k, m, n, cnt = 0;
        cin>>m>>n;
        int a[m], b[n];
        for0(i, m) cin >> a[i];
        for0(i, n) cin >> b[i];

        cout << countPairs(a, b, m, n) << "\n";
    }

    return 0;
}