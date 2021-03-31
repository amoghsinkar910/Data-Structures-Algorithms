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

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    { 
        ll i,j,k,n,x;
        cin>>n;
        if(n<=9)
        {
            cout<<1<<"\n";
            return 0;
        }

        vll dp(n+1,INT_MAX);
        for(i=0;i<=9;i++) dp[i]=1;
        for(i=10;i<=n;i++)
        {
            x=i;
            vll dig;
            while(x>0)
            {
                k=x%10;
                x/=10;
                dig.pb(k);
            }
            for(auto it:dig)
            {
                if(i-it>=0)
                {
                    dp[i]=min(dp[i],1 + dp[i-it]);
                }
            }
        }
        cout<<dp[n]<<"\n";
    }
    
    return 0;
}