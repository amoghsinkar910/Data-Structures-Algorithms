//https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/



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

int numberOfSubstrings(string s)
{
    int i, j, n = s.size(), ans = 0;
    vector<int> f(3, 0);
    j = 0;

    for (i = 0; i < n; i++)
    {
        f[s[i] - 'a']++;
        while (f[0] > 0 && f[1] > 0 && f[2] > 0 && j <= i)
        {
            ans += n - i;
            f[s[j] - 'a']--;
            j++;
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
        cout << numberOfSubstrings(s) << "\n";
    }

    return 0;
}