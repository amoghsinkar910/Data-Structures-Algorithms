//https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

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

int sum = 0;
void rec(TreeNode *root)
{
    if (root == NULL)
        return;
    if (root->left != NULL && root->left->left != NULL && !((root->val) & 1))
    {
        sum += (root->left->left->val);
    }
    if (root->left != NULL && root->left->right != NULL && !((root->val) & 1))
    {
        sum += (root->left->right->val);
    }
    if (root->right != NULL && root->right->right != NULL && !((root->val) & 1))
    {
        sum += (root->right->right->val);
    }
    if (root->right != NULL && root->right->left != NULL && !((root->val) & 1))
    {
        sum += (root->right->left->val);
    }
    rec(root->left);
    rec(root->right);
}

int sumEvenGrandparent(TreeNode *root)
{
    rec(root);
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //sumEvenGrandparent()

    return 0;
}