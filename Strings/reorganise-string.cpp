//https://leetcode.com/problems/reorganize-string/


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

string reorganizeString(string s) 
    {
        unordered_map<char,int> mp;
        int i,j,k;
        int n = int(s.size());
        string ans(n,'$');
        
        for(i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        int mx=0;
        char cmx;
        for(auto it:mp) 
        {
            if(it.second>mx)
            {
                mx=it.second;
                cmx=it.first;
            }
        }
        
        if(mx>((n+1)/2)) return "";
        
        i=0;
        while(mp[cmx])
        {
            ans[i]=cmx;
            i+=2;
            mp[cmx]--;
        }
        
        for(j=0;j<26;j++)
        {
            while(mp[j+'a'])
            {
                if(i>=n) i=1;
                ans[i]=j+'a';
                mp[j+'a']--;
                i+=2;
            }
        }
        return ans;
    }

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s;
    cin>>s;
    cout << reorganizeString(s) << "\n";
    
    return 0;
}