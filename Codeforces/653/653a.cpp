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


int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll i,j,k,n,x,y;
        cin>>x>>y>>n;
        ll fac,rem,mul;
        fac=n/x;
        mul=fac*x;
        if(mul+y<=n)
        {
            cout<<mul+y<<endl;
        }
        else
        {
            cout<<mul-x+y<<endl;
        }
        
    }
    
    return 0;
}