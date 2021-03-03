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

void rec(vector<int> &a, vector<vector<int>> &ans, vector<int> &s, int idx)
{
    ans.push_back(s);
    for (int i = idx; i < a.size(); i++)
    {
        s.push_back(a[i]);
        rec(a, ans, s, i + 1);
        s.pop_back();
    }
    return;
}

vector<vector<int>> subsets(vector<int> &a)
{
    vector<vector<int>> ans;
    vector<int> s;
    rec(a, ans, s, 0);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    {
        int i, j, k, n, cnt = 0;
        cin >> n;
        vector<int> a;
        for0(i, n)
        {
            cin >> k;
            a.pb(k);
        }
        vector<vector<int>> ans = subsets(a);
        for (i = 0; i < ans.size(); i++)
        {
            for (auto it : ans[i])
                cout << it << " "; 
            cout << "\n";
        }
    }

    return 0;
}