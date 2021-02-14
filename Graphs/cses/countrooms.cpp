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

const ll N = 1e3 + 5;
const ll mod = 1e9 + 7;
const ll INF = 1e9;
char a[N][N];
ll vis[N][N],n,m;
ll dx[4]={1,-1,0,0};
ll dy[4]={0,0,1,-1};

void dfs(ll x,ll y)
{
    //cout<<x<<" "<<y<<endl;
    ll i;
    vis[x][y]=1;
    for(i=0;i<4;i++)
    {
        ll X=x+dx[i],Y=y+dy[i];
        if(X<n && X>=0 && Y<m && Y>=0 && a[X][Y]=='.' && vis[X][Y]==0)
        {
            dfs(X,Y);
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
    // ll t;
    // cin>>t;
    // while(t--)
    { 
        ll i,j,k,cnt=0;
        cin>>n>>m;
        for0(i,n) 
            for0(j,m) cin>>a[i][j];
        
        for0(i,n)
        {
            for0(j,m)
            {
                if(a[i][j]=='.' && vis[i][j]==0)
                {
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        cout<<cnt<<endl;
    }
    
    return 0;
}