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

int gap(int n)
{
    if(n<=1)
        return 0;
    return (n/2 + n%2) ;
}
void merge(int a[], int b[], int n, int m)
{
    int i,j,x=n+m;
    for(x=gap(x);x>0;x=gap(x))
    {
        for(i=0;i+x<n;i++)
        {
            if(a[i]>a[i+x])
                swap(a[i],a[i+x]);
        }

        for(j=x>n ? x-n : 0;i<n && j<m;i++,j++)
        {
            if(a[i]>b[j])
                swap(a[i],b[j]);
        }

        if(j<m)
        {
            for(j=0;j+x<m;j++)
            {
                if(b[j]>b[j+x])
                    swap(b[j],b[j+x]);
            }
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    { 
        int i,j,n,m,cnt=0;
        cin>>n>>m;
        int a[n],b[m];
        for0(i,n) cin>>a[i]; 
        for0(i,m) cin>>b[i]; 

        merge(a,b,n,m);

        for0(i,n) cout<<a[i]<<" ";
        cout<<"\n"; 
        for0(i,m) cout<<b[i]<<" ";
        cout<<"\n"; 
    }
    
    return 0;
}