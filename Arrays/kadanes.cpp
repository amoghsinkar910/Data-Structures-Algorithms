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

int maxSubarraySum(int a[],int n)
{
    int mx=0,global_mx=INT_MIN,i;
    for(i=0;i<n;i++)
    {
        mx+=a[i];
        if(mx>global_mx)
            global_mx=mx;
        if(mx<0)
            mx=0;
    }
    return global_mx;
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
        cout << maxSubarraySum(a,n) <<"\n";
    }
    
    return 0;
}