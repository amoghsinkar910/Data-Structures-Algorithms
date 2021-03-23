//https://leetcode.com/problems/palindromic-substrings/submissions/


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

int countSubstrings(string s)
{
    int ans = 0;
    int i, j, n = s.size(), l;
    int dp[n][n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            dp[i][j] = 0;
    }

    for (i = 0; i < n; i++)
        dp[i][i] = 1;
    ans=n;

    for (i = 0; i < n - 1; i++)
    {
        dp[i][i + 1] = (s[i] == s[i + 1]);
        ans += dp[i][i + 1];
    }

    for (l = 3; l <= n; l++)
    {
        for (i = 0, j = i + l - 1; j < n; i++, j++)
        {
            dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
            ans += dp[i][j];
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    {
        string s;
        cin >> s;
        cout << countSubstrings(s) << "\n";
    }

    return 0;
}