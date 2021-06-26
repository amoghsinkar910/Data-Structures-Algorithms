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


    void rotate(vector<int>& a, int k) 
    {
        int i,j;
        k=k%a.size();
        vector<int> ans = a;
        for(i=0;i<a.size();i++)
        {
            ans[(i+k)%(a.size())] = a[i];
        }
        a=ans;
    }
    
    void rotate1(vector<int>& a, int k) 
    {
        int i,j;
        k=k%a.size();
        reverse(a.begin(),a.end());
        reverse(a.begin(),a.begin()+k);
        reverse(a.begin()+k,a.end());
    }


int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    { 
        ll i,j,k,n,cnt=0;
        cin>>n>>k;
        vector<int> a;
        for(i=0;i<n;i++) cin>>j,a.pb(j);

        rotate(a,k);
        //rotate1(a,k);
        for(auto it:a) cout<<it<<" ";
        cout<<"\n";
    }
    
    return 0;
}