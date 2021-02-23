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

//2 pointer approach, map to check uniqueness
vector<vector<int>> fourSum(vector<int> &a, int target)
{
    map<vector<int>, int> mp;
    vector<vector<int>> ans;
    int i, j, l, r, n = int(a.size());
    sort(a.begin(), a.end());
    for (i = 0; i < n; i++)
    {
        for (j = n - 1; j > i; j--)
        {
            int rem = target - a[i] - a[j];
            l = i + 1;
            r = j - 1;
            while (l < r)
            {
                int sum = a[l] + a[r];
                if (sum > rem)
                    r--;
                else if (sum < rem)
                    l++;
                else
                {
                    vector<int> q{a[i], a[j], a[l], a[r]};
                    sort(q.begin(), q.end());
                    if (mp[q] < 1)
                    {
                        mp[q]++;
                        ans.push_back(q);
                    }
                    l++;
                    r--;
                }
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
        int i, j, k, n, tar;
        cin >> n >> tar;
        vector<int> a;
        for0(i, n) cin >> k, a.pb(k);

        vector<vector<int>> ans = fourSum(a, tar);
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