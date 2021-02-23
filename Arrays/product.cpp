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

vector<int> productExceptSelf(vector<int> &a)
{
    int n = a.size();
    int left[n], right[n];

    int p = 1;
    for (int i = 0; i < n; i++)
    {
        p = p * a[i];
        left[i] = p;
    }

    p = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        p = p * a[i];
        right[i] = p;
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (i - 1 < 0 && i + 1 >= 0)
        {
            ans.push_back(right[i + 1]);
        }
        else if (i - 1 < n && i + 1 >= n)
        {
            ans.push_back(left[i - 1]);
        }
        else
            ans.push_back(left[i - 1] * right[i + 1]);
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
        int i, j, k, n, cnt = 0;
        cin >> n;
        vector<int> a;
        for0(i, n)
        {
            cin >> k;
            a.pb(k);
        }
        vector<int> ans = productExceptSelf(a);
        for (auto it : ans)
            cout << it << " ";
        cout << "\n";
    }

    return 0;
}