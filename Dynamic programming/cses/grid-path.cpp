//author: _mayor
#include <bits/stdc++.h>   
 
#define for0(i, n) for (long long  i = 0; i < n; i++) 
#define for1(i, n) for (long long  i = 1; i <= n; i++) 
#define forc(i, l, r) for (long long  i = l; i <= r; ++i) 
#define forr0(i, n) for (long long  i = n - 1; i >= 0; i--) 
#define forr1(i, n) for (long long  i = n; i >= 1; i--)
#define show(n,m,a) for1(i,n){ for1(j,m) { cout<<a[i][j]<<" ";}cout<<endl;} 
 
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
 
int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    { 
        ll i,j,n,m;
        cin>>n;
        char a[n+1][n+1];
        ll dp[n+1][n+1];
    
        for1(i,n)
        {
            for1(j,n)
            {
                dp[i][j]=0;
                cin>>a[i][j];
            }
        }
 
        if(a[1][1]=='*') 
        {
            cout<<0<<endl;
            return 0;
        }
 
        for(i=1;i<=n;i++)
        {
            if(a[1][i]=='.') dp[1][i]=1;
            else break;
        }
        
        for(i=1;i<=n;i++)
        {
            if(a[i][1]=='.') dp[i][1]=1;
            else break;
        }
        dp[1][1]=1;
        for(i=2;i<=n;i++)
        {
            for(j=2;j<=n;j++)
            {
                if(a[i][j]=='.') 
                    dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
            }
        }
        cout<<dp[n][n]<<endl;
    }
    
    return 0;
}