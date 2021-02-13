//author: _mayor
#include <bits/stdc++.h>   

#define for0(i, n) for (long long  i = 0; i < n; i++) 
#define for1(i, n) for (long long  i = 1; i <= n; i++) 
#define forc(i, l, r) for (long long  i = l; i <= r; ++i) 
#define forr0(i, n) for (long long  i = n - 1; i >= 0; i--) 
#define forr1(i, n) for (long long  i = n; i >= 1; i--) 

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


struct Node
{
    int data;
    Node* left;
    Node* right;
};

vector<int> ans;

void inorder(Node* root)
{
    if(root==NULL) return;
    inorder(root->left);
    ans.push_back(root->data);
    inorder(root->right);
}

// return true if the given tree is a BST, else return false
bool isBST(Node* root) 
{
    ans.clear();
    inorder(root);
    int f=0,i;
    if(ans.size()==1) return true;
    if(is_sorted(ans.begin(),ans.end()))
    {
        for(i=1;i<ans.size();i++){
            if(ans[0]==ans[i]) f=0;
            else{
                f=1;
                break;
            }
        }
        if(f) return true;
        return false;
    }
    return false;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    { 
        //init and call isBST()
    }
    
    return 0;
}