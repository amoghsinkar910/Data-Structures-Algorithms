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
typedef pair<long long,long long> pll;
typedef vector<ii> vii;
typedef long long ll;
typedef long long int lli;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;  

const ll N = 1e5 + 5;
const ll mod = 1e9 + 7;
const ll INF = 1e15;

vll dist(N,INF),vis(N,0);
vector<pll> adj[N];

void dijk()
{   
    priority_queue<pll,vector<pll>,greater<pll>> q;
    dist[1]=0;
    q.push({0,1}); //{dist,node}
    while(!q.empty())
    {
        pll p=q.top();
        q.pop();
        if(vis[p.se]) continue;
        vis[p.se]=1;
        for(auto c:adj[p.se])
        {
            if(!vis[c.fi])
            {
                if(dist[c.fi] > p.fi + c.se)
                {
                    dist[c.fi] = p.fi + c.se;
                    q.push({dist[c.fi],c.fi});
                }
            }
        }
    }
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
            ll a,b,c;
            cin>>a>>b>>c;
            adj[a].pb({b,c});
        }
        dijk();
        for(i=1;i<=n;i++) cout<<dist[i]<<" ";
        cout<<"\n";
    }
    
    return 0;
}