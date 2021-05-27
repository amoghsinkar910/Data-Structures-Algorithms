//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

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

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node *connect(Node *root)
{
    if (root == NULL || root->left == NULL || root->right == NULL)
        return root;

    //if the subtree has only 2 levels- one is root and other has 2 children
    if (root->left->left == NULL && root->right->right == NULL)
    {
        root->left->next = root->right;
        return root;
    }

    //joining the children nodes
    Node *L = connect(root->left);
    Node *R = connect(root->right);

    //joining the nodes in diff subtrees
    //i.e joining one node form left subtree to one node from right subtree
    while (L != NULL)
    {
        L->next = R;
        L = L->right;
        R = R->left;
    }
    return root;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //connect(root);

    return 0;
}