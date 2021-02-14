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

vll adj[N],col(N,0),pa(N,-1);
ll en,start;

int dfs(ll st,ll par)
{
    col[st]=1;
    for(ll u:adj[st])
    {
        if(u==par) continue;
        if(col[u]==0)
        {
            pa[u]=st;
            if(dfs(u,st))
                return true;
        }
        else if(col[u]==1)
        {
            start=u;            
            en=st;
            return true;
        }
    }
    col[st]=2;
    return false;
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
        ll i,n,m;
        cin>>n>>m;
        for0(i,m) 
        {
            ll a,b;
            cin>>a>>b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        start=-1;
        for(i=1;i<=n;i++)
        {
            if(col[i]==0 && dfs(i,pa[i]))
                break;
        }
        if(start==-1) 
            cout<<"IMPOSSIBLE"<<"\n";
        else
        {
            vll ans;
            ans.pb(start);
            for(i=en;i!=start;i=pa[i])
            {
                ans.pb(i);
            }
            ans.pb(start);
            reverse(all(ans));
            cout<<ans.size()<<"\n";
            for(auto it:ans)
            {
                cout<<it<<" ";
            }
            cout<<"\n";
        }   
        
    }
    
    return 0;
}