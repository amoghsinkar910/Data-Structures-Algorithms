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
        ll i,j,k,n,cnt=0;
        cin>>n;
        while(n!=1 && n%3==0)
        {
            if(n%6==0) n=n/6;
            else n=n*2;
            cnt++;    
        }
        if(n==1) cout<<cnt<<endl;
        else cout<<-1<<endl;
    }
    
    return 0;
}