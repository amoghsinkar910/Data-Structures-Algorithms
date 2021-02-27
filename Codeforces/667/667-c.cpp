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


int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    { 
        ll i,j,k,n,ans=-1,mx=-1,x,cnt=0;
        vll v;
        cin>>n;
        bool f=0;
        ll a[n];
        for0(i,n)
        {
            cin>>a[i];
            if(a[i]>mx) mx=a[i];
        }
        for(i=1;i<n;i++)
        {
            if(a[i]==a[0]) continue;
            else{
                f=1;
                break;
            }
        }
        for0(i,n)
        {
            if(a[i]==mx)
            {
                if((i>0 && a[i]>a[i-1]) || (i<n-1 && a[i]>a[i+1]))
                {
                    ans=i+1;
                    break;
                }
            }
        }
        cout<<ans<<endl;
        
    }
    
    return 0;
}