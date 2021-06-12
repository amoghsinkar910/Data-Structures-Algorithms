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

void rec(TreeNode *root, int &sum, int lev, int &mx)
{
    if (root == NULL)
        return;
    if (lev > mx)
    {
        mx = lev;
        sum = root->val;
    }
    else if (lev == mx)
    {
        sum += root->val;
    }
    rec(root->left, sum, lev + 1, mx);
    rec(root->right, sum, lev + 1, mx);
}
int deepestLeavesSum(TreeNode *root)
{
    int sum = 0, lev = 0, mx = 0;
    rec(root, sum, lev, mx);
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    {
        ll i, j, k, n, cnt = 0;
        //deepestLeavesSum()
    }

    return 0;
}