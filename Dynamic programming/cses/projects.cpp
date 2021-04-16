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

struct project
{
    ll s,e,m;
};

bool cmp(project a,project b)
{
    return (a.e < b.e);
}

//binary search to find the largest index whose end is less than the start of the ith project
ll bs(project a[],ll idx) 
{
    ll l=0,r=idx-1;
    while(l<=r)
    {
        ll mid = (l+r)/2;
        if(a[mid].e < a[idx].s)
        {
            if(a[mid+1].e < a[idx].s)
            {
                l=mid+1;
            }
            else return mid;
        }
        else r=mid-1;
    }
    return -1;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    { 
        ll i,n;
        cin>>n;
        project a[n];
        for0(i,n)
        {
            cin>>a[i].s>>a[i].e>>a[i].m;
        }
        sort(a,a+n,cmp);
        ll dp[n];
        dp[0]=a[0].m;
        for(i=1;i<n;i++)
        {
            ll incl = a[i].m; //if we include ith project
            ll idx = bs(a,i);
            if(idx!=-1)
            {
                incl += dp[idx]; 
            }
            dp[i] = max(dp[i-1],incl); //max(include,not include)
        }
        cout<<dp[n-1]<<"\n";
    }
    
    return 0;
}