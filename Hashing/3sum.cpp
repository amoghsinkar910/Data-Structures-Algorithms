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

vector<vector<int>> threeSum(vector<int> &a)
{
    vector<vector<int>> ans;
    int i, j, l, r, n = int(a.size());
    sort(a.begin(), a.end());
    for (i = 0; i < n; i++)
    {
        if (i > 0 && a[i] == a[i - 1])
            continue;
        int rem = -a[i];
        l = i + 1;
        r = n - 1;
        while (l < r)
        {
            int s = a[l] + a[r];
            if (s > rem)
                r--;
            else if (s < rem)
                l++;
            else
            {
                ans.push_back({a[i], a[l], a[r]});
                while (l < r && a[l] == a[l + 1])
                    l++;
                while (l < r && a[r] == a[r - 1])
                    r--;
                l++;
                r--;
            }
        }
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
        int i, j, k, n;
        cin >> n;
        vector<int> a;
        for0(i, n) cin >> k, a.pb(k);

        vector<vector<int>> ans = threeSum(a);
        for (i = 0; i < ans.size(); i++)
        {
            for (int x : ans[i])
                cout << x << " ";
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}