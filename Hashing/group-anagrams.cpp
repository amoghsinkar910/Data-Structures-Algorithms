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
const ll mod = 1e9 + 9;
const ll INF = 1e9;

vector<vector<string>> groupAnagrams(vector<string> &s)
{
    unordered_map<string, vector<string>> mp;
    vector<vector<string>> ans;
    int i, n = s.size();
    for (i = 0; i < n; i++)
    {
        string x = s[i];
        sort(x.begin(), x.end());
        mp[x].push_back(s[i]);
    }

    for (auto it : mp)
    {
        ans.push_back(it.second);
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
        cin >> n;
        vector<string> s;
        for0(i, n)
        {
            string x;
            cin >> x;
            s.pb(x);
        }
        vector<vector<string>> ans = groupAnagrams(s);
        for (i = 0; i < ans.size(); i++)
        {
            for (j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}