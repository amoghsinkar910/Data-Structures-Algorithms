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

int isPalindrome(string s, int l, int r)
{
    while (l <= r)
    {
        if (s[l++] != s[r--])
            return false;
    }
    return true;
}

void solve(int idx, string s, vector<string> &x, vector<vector<string>> &ans)
{
    int i;
    if (idx >= s.size())
    {
        ans.push_back(x);
        return;
    }
    for (i = idx; i < s.size(); i++)
    {
        if (isPalindrome(s, idx, i))
        {
            x.push_back(s.substr(idx, i - idx + 1));
            solve(i + 1, s, x, ans);
            x.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    vector<string> x;
    solve(0, s, x, ans);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    {
        int i, j, k, n, cnt = 0;
        string s;
        cin>>s;
        vector<vector<string>> ans = partition(s);
        for(int i=0;i<ans.size();i++)
        {
            for(string x:ans[i]) cout<<x<<" ";
            cout<<"\n";
        }
    }

    return 0;
}