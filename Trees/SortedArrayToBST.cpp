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

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode *helper(vector<int> &nums, int l, int r)
{
    if (l > r)
        return 0;
    TreeNode *root = new TreeNode;
    int mid = (l + r) / 2;
    root->val = nums[mid];
    root->left = helper(nums, l, mid - 1);
    root->right = helper(nums, mid + 1, r);
    return root;
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    int start = 0, end = int(nums.size() - 1);
    return helper(nums, start, end);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    {
        ll i, j, k, n, cnt = 0;
        //init tree
        //call sortedArrayToBST(root)
    }

    return 0;
}