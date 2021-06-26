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

void rec(vector<int> &a, int target, int idx, vector<vector<int>> &ans, vector<int> &temp)
{
    if (target < 0)
        return;
    if (target == 0)
        ans.push_back(temp);

    for (int i = idx; i < a.size(); i++)
    {
        temp.push_back(a[i]);
        if (target >= a[i])
            rec(a, target - a[i], i, ans, temp);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &a, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;
    rec(a, target, 0, ans, temp);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);

    {
        ll i, j, k, n, cnt = 0;
        cin >> n >> k;
        vector<int> a;
        for (i = 0; i < n; i++)
        {
            cin >> j;
            a.push_back(j);
        }
        vector<vector<int>> fin = combinationSum(a, k);
        for (auto it : fin)
        {
            for (auto x : it)
                cout << x << " ";
            cout << "\n";
        }
    }

    return 0;
}