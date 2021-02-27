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
        ll i,j,k,n,cnt=0;
        ll a[4]={1,2,3,4};
        string x;
        cin>>x;
        i=(x[0]-'0')*4;
        if(x.length()==1)
        {
            for0(j,i-3)
            {
                cnt+=a[j%4];
            }
            
        }
        else if(x.length()==2)
        {
            for0(j,i-2)
            {
                cnt+=a[j%4];
            }
            //cout<<i-2<<endl;
        }
        else if(x.length()==3)
        {
            for0(j,i-1)
            {
                cnt+=a[j%4];
            }
            //cout<<i-1<<endl;
        }
        else if(x.length()==4)
        {
            for0(j,i)
            {
                cnt+=a[j%4];
            }
           // cout<<i<<endl;
        }
        cout<<cnt<<endl;
    }
    
    return 0;
}