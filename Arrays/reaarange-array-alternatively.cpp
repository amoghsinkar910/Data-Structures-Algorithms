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

void rearrange(int a[],int n)
{
    // Trick to store two values at one index- take mx = maximimum element in array + 1
    // then make a[i]= a[i]+(a[j]%mx)*mx, j={l,r}
    // if a[i]=2 and mx=9 then a[i] becomes 2 + (2%9)*9 = 20
    // and after modifying every element we will again divide them by mx, so here 20/9 becomes 2
    
    int l=0,r=n-1,i;
    int mx=a[n-1]+1;
    for(i=0;i<n;i++)
    {
        //pointer for minimum
        if(i&1)
        {
            a[i]+=(a[l]%mx)*mx;
            l++;
        }
        else //pointer for maximum
        {
            a[i]+=(a[r]%mx)*mx;
            r--;
        }
    }

    for(i=0;i<n;i++) a[i]/=mx;
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

        rearrange(a,n);

        for0(i,n) cout<<a[i]<<" ";
        cout<<"\n";
    }
    
    return 0;
}