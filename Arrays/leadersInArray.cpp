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

vector<int> leaders(int a[], int n)
{
    vector<int> ans;
    if(n==1) {
        ans.push_back(a[0]);
        return ans;
    }
    int mx=a[n-1],i;
    ans.push_back(mx);
    for(i=n-2;i>=0;i--)
    {
       if(a[i]>=mx){
           ans.push_back(a[i]);
           mx=a[i];
       }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    { 
        int i,j,k,n,cnt=0;
        cin>>n;
        int a[n];
        for0(i,n) cin>>a[i]; 
        vector<int> ans =  leaders(a,n);
        for(auto it:ans) cout<<it<<" ";
        cout<<"\n";
    }
    
    return 0;
}