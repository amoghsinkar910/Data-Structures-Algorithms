// //author: _mayor
#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define pi (3.141592653589)
#define mod 1000000007
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define rrep(i, n) for(int i=n-1;i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

vector<string> v;
int n, m;


int dist[1001][1001];
int d[1001][1001];
int dx[4] = { 0, 0, -1, 1 }; 
int dy[4] = { -1, 1, 0, 0 };

int main() {
    fast
    int t = 1;
    // cin >> t;
    while(t--) {
        rep(i, 1001)rep(j, 1001)dist[i][j]=-1;
        cin>>n>>m;
        for(int i = 0; i < n; i++){
        	string x;cin>>x;
            v.pb(x);
        }
        int x,y,c1,c2;
        queue<vector<int>>q;
        rep(i, n){
        	rep(j, m){
        		if(v[i][j]=='M')q.push({i, j, 0});
        		if(v[i][j]=='A')c1=i, c2=j;
			}
		}
		x=c1, y=c2;
        while(!q.empty()) 
        {
            auto curr= q.front();
            q.pop();
            int x=curr[0], y=curr[1], steps=curr[2];
            if(x < 0 || x > n - 1 || y < 0 || y > m - 1 || v[x][y]=='#' || dist[x][y]!=-1)continue;
            dist[x][y]=steps;
            rep(i, 4){
                int cx=x+dx[i], cy=y+dy[i];
                q.push({ cx, cy, steps+1});
            }
        }
        string ans;
        while(!q.empty())   q.pop();
        q.push({ x, y, 0, 0 });
        rep(i, 1001)rep(j, 1001)d[i][j]=-1;
        bool c = false;
        int p[n + 1][m + 1];
        memset(p, 0, sizeof(p));
        while(!q.empty()) 
        {
            auto curr=q.front();
            q.pop();
            int x =curr[0], y =curr[1], steps =curr[2], dir =curr[3];
            if(x < 0 || x > n - 1 || y < 0 || y > m - 1 || v[x][y] == '#' || d[x][y] != -1 || (dist[x][y] >= 0 and dist[x][y] <= steps))
                continue;
            if(x == n - 1 || y == m - 1 || x == 0 || y == 0) 
            {
                p[x][y] = dir;
                while(x != c1 or y != c2) {
                    cout<<x<<" "<<y<<"\n";
                    if(p[x][y] == 0)    ans += 'L', y++;// path is from (x, y) to (x, y-1) so ans+='L' and (0=> {0, -1}) thats why y++.
                    else if(p[x][y] == 1) ans += 'R', y--;
                    else if(p[x][y] == 2)  ans += 'U', x++;
                    else    ans += 'D', x--;	
                }
                reverse(ans.begin(), ans.end());
                c=true;
                break;
            }
            d[x][y] = steps;
            p[x][y] = dir;
            rep(i, 4){
                int cx=x+dx[i], cy=y+dy[i];
                q.push({ cx, cy, steps + 1, i });
            }
        }
        if(c){
            cout<<"YES"<<endl<<ans.size()<<endl<<ans;
        }
        else
            cout << "NO"<<endl;
    }
	return 0;
}
// #include <bits/stdc++.h>   

// #define for0(i, n) for (long long  i = 0; i < n; i++) 
// #define for1(i, n) for (long long  i = 1; i <= n; i++) 
// #define forc(i, l, r) for (long long  i = l; i <= r; ++i) 
// #define forr0(i, n) for (long long  i = n - 1; i >= 0; i--) 
// #define forr1(i, n) for (long long  i = n; i >= 1; i--) 

// #define pb push_back
// #define fi first
// #define se second

// #define all(x) (x).begin(), (x).end() 
// #define rall(x) (x).rbegin, (x).rend() 

// using namespace std;

// typedef vector<int> vi;
// typedef vector<vi> vvi;
// typedef pair<int, int> ii;
// typedef vector<ii> vii;
// typedef long long ll;
// typedef long long int lli;
// typedef vector<ll> vll;
// typedef vector<vll> vvll;
// typedef double ld;  

// const ll N = 1e5 + 5;
// const ll mod = 1e9 + 7;
// const ll INF = 1e9;

// ll mon[1005][1005],pla[1005][1005];
// ll dx[4]={0,0,-1,1};
// ll dy[4]={-1,1,0,0};

// int main() 
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt", "r", stdin);
//         freopen("output.txt", "w", stdout);
//     #endif
//     ll t=1;
//     while(t--)
//     { 
//         ll i,j,n,m,si,sj;
//         cin>>n>>m;
//         vector<string> v;
//         queue<vector<ll>> q;
//         for0(i,1001) for0(j,1001) mon[i][j]=-1;
//         for0(i,n){
//             string s;
//             cin>>s;
//             v.pb(s);
//         }
//         for0(i,n){
//             for0(j,m){
//                 if(v[i][j]=='M') q.push({i,j,0});
//                 if(v[i][j]=='A') si=i,sj=j;
//             }
//         }

//         //bfs for all monsters
//         while(!q.empty())
//         {
//             auto e=q.front();
//             q.pop();
//             ll x=e[0],y=e[1],steps=e[2];
//             if(x<0 || x>n-1 || y<0 || y>m-1 || v[x][y]=='#' || mon[x][y]!=-1)
//                 continue;
//             mon[x][y]=steps;
//             for0(i,4)
//             {
//                 q.push({x+dx[i],y+dy[i],steps+1});
//             }
//         }

//         //bfs for player
//         string ans;
//         while(!q.empty()) q.pop();

//         q.push({si,sj,0,0});
//         ll path[1005][1005];
//         for0(i,1001) for0(j,1001) pla[i][j]=-1,path[i][j]=0;
//         int f=0;
        
//         while(!q.empty())
//         {
//             auto e=q.front();
//             q.pop();
//             ll x=e[0],y=e[1],steps=e[2],dir=e[3];
//             if(x<0 || x>n-1 || y<0 || y>m-1 || v[x][y]=='#' || pla[x][y]!=-1 || (mon[x][y]>0 && mon[x][y]<=steps))
//                 continue;
            
//             if(x==n-1 || x==0 || y==m-1 || y==0)
//             {
//                 path[x][y]=dir;
//                 while(x!=si || y!=sj)
//                 {
//                     if(path[x][y]==0) ans+='L',y++;
//                     else if(path[x][y]==1) ans+='R',y--;
//                     else if(path[x][y]==2) ans+='U',x++;
//                     else ans+='D',x--;
//                 }
//                 reverse(all(ans));
//                 f=1;
//                 break;
//             }
//             pla[x][y]=steps;
//             path[x][y]=dir;
//             for0(i,4){
//                 q.push({x+dx[i],y+dy[i],steps+1,i});
//             }
//         }
//         if(f){
//             cout<<"YES"<<"\n"<<ans.size()<<"\n"<<ans<<"\n";
//         }
//         else cout<<"NO"<<"\n";
//     }
    
//     return 0;
// }

