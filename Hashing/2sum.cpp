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

vector<int> twoSum1(vector<int> &a, int target)
{
    unordered_map<int, int> mp, idx;
    vector<int> ans;
    int i, j, n = int(a.size());
    for (i = 0; i < n; i++)
    {
        idx[a[i]] = i;
    }

    for (i = 0; i < n; i++)
    {
        int rem = target - a[i];
        if (idx.count(rem) && idx[rem] != i)
        {
            ans.push_back(i);
            ans.push_back(idx[rem]);
            break;
        }
    }
    return ans;
}

vector<int> twoSum(vector<int> &a, int target)
{
    unordered_map<int, int> idx;
    for (int i = 0; i < a.size(); i++)
    {
        auto it = idx.find(target - a[i]);
        if (it != idx.end())
        {
            return {i, idx[target - a[i]]};
        }
        idx[a[i]] = i;
    }
    return {};
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
        int i, j, k, n, tar;
        cin >> n >> tar;
        vector<int> a;
        for0(i, n) cin >> k, a.pb(k);

        vector<int> ans = twoSum(a, tar);

        for (int x : ans)
            cout << x << " ";
        cout << "\n";

        cout << "\n";
    }

    return 0;
}