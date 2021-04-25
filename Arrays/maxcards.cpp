//https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

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

int maxScore(vector<int>& a, int k) 
    {
        int n = a.size(),i,j;
        int pref[k+1],suf[k+1];
        
        pref[0]=0;
        suf[0]=0;
        
        for(i=0;i<k;i++)
        {
            pref[i+1] = pref[i] + a[i];
            suf[i+1] = suf[i] + a[n-i-1];
        }
        int ans=0;
        for(i=0;i<=k;i++)
        {
            int curr = pref[i] + suf[k-i];
            ans = max(ans,curr);
        }
        return ans;
    }

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    { 
        int i,j,k,n,cnt=0;
        vector<int> a;
        cin>>n>>k;
        for0(i,n) cin>>j,a.pb(j);
        cout << maxScore(a,k);
    }
    
    return 0;
}