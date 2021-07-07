//https://leetcode.com/problems/combination-sum-iii/

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

vector<vector<int>> ans;
void rec(vector<int> &a, int target, int cnt, int idx, vector<int> &v)
{
    if (target == 0 && cnt == 0)
    {
        ans.push_back(v);
        return;
    }

    for (int i = idx; i < a.size(); i++)
    {
        v.push_back(a[i]);
        if (target - a[i] >= 0)
            rec(a, target - a[i], cnt - 1, i + 1, v);
        v.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{
    vector<int> a;
    for (int i = 0; i < 9; i++)
        a.push_back(i + 1);

    vector<int> v;

    rec(a, n, k, 0, v);

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> fin = combinationSum3(k, n);
    for (auto it : fin)
    {
        for (auto x : it)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}