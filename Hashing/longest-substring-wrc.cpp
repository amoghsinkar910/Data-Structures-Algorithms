//author: _mayor
#include <bits/stdc++.h>

#define for0(i, n) for (long long i = 0; i < n; i++)
#define for1(i, n) for (long long i = 1; i <= n; i++)
#define forc(i, l, r) for (long long i = l; i <= r; ++i)
#define forr0(i, n) for (long long i = n - 1; i >= 0; i--)
#define forr1(i, n) for (long long i = n; i >= 1; i--)

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

int lengthOfLongestSubstring(string s)
{
    int n = int(s.size()), i, j;
    set<char> freq;
    i = 0, j = 0;
    int len = 0, ans = 0;
    while (i < n)
    {
        if (freq.count(s[i]))
        {
            while (s[i] != s[j] && j < i)
            {
                freq.erase(s[j]);
                j++;
            }
            freq.erase(s[j]);
            j++;
        }
        else
        {
            freq.insert(s[i]);
            ans = max(ans, int(freq.size()));
            i++;
        }
    }
    return ans;
}

int lengthOfLongestSubstringOptimised(string s) 
    {
        int n = int(s.size()),i,j;
        map<char,int> mp;
        j=0;
        int ans=0;
        for(i=0;i<n;i++)
        {
            if(mp.find(s[i])!=mp.end())
            {
                j=max(j,mp[s[i]]+1);
            }
            mp[s[i]]=i;
            ans = max(ans,i-j+1);
        }
        return ans;
    }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << lengthOfLongestSubstring(s) << "\n";
    }

    return 0;
}