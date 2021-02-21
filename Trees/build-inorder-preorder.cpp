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

unordered_map<int, int> mp;
int idx = 0;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *rec(int st, int end, vector<int> &preorder)
{
    if (st > end)
        return NULL;
    TreeNode *node = new TreeNode(preorder[idx++]);
    if (st == end)
        return node;
    int i = mp[node->val];
    node->left = rec(st, i - 1, preorder);
    node->right = rec(i + 1, end, preorder);
    return node;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int n = preorder.size();
    for (int i = 0; i < n; i++)
    {
        mp[inorder[i]] = i;
    }
    TreeNode *root = rec(0, n - 1, preorder);
    return root;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    {
        int i, j, k, n, cnt = 0;
        cin>>n;
        vector<int> preorder,inorder;
        for0(i,n)
        {
            cin>>k;
            preorder.pb(k);
        }
        for0(i,n)
        {
            cin>>k;
            inorder.pb(k);
        }
        TreeNode* root = buildTree(preorder,inorder);
    }

    return 0;
}