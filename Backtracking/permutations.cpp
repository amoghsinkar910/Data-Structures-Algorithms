//https://leetcode.com/problems/permutations/

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

vector<vector<int>> permuteSTL(vector<int> &a)
{
    vector<vector<int>> ans;
    sort(a.begin(), a.end());
    do
    {
        ans.push_back(a);
    } while (next_permutation(a.begin(), a.end()));

    return ans;
}

void rec(vector<int> &a, vector<int> v, vector<vector<int>> &ans)
{
    //base case
    if (v.size() == a.size())
    {
        ans.push_back(v);
        return;
    }
    for (int i = 0; i < a.size(); i++)
    {
        //keeping note of visited node
        if (a[i] != 1e5)
        {
            v.push_back(a[i]);
            int temp = a[i];
            a[i] = 1e5;

            rec(a, v, ans); //recursion

            a[i] = temp; //backtracking
            v.pop_back();
        }
    }
}

vector<vector<int>> permuteBacktrack(vector<int> &a)
{
    vector<int> v;
    vector<vector<int>> ans;

    rec(a, v, ans);

    return ans;
}

void rec2(int idx, vector<int> &a, vector<vector<int>> &ans)
{
    //base case
    if (idx == a.size())
    {
        ans.push_back(a);
        return;
    }

    //recursive case
    for (int i = idx; i < a.size(); i++)
    {
        swap(a[i], a[idx]);
        rec(idx + 1, a, ans);
        swap(a[i], a[idx]);
    }
}

vector<vector<int>> permute2(vector<int> &a)
{
    vector<vector<int>> ans;

    rec(0, a, ans);

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int i, j, k, n, cnt = 0;
    cin >> n;
    vector<int> a;
    for0(i, n) cin >> k, a.pb(k);

    //permuteSTL(a)
    //permuteBacktrack(a)

    return 0;
}