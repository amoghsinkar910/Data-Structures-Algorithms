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

int countSubstrings(string s, string t)
{
    int i = 0, j = 0, n = s.size(), m = t.size();
    int ans = 0, diff = 0;
    int x, y;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            x = i;
            y = j;
            diff = 0;
            while (x < n && y < m && diff <= 1)
            {
                if (s[x] != t[y])
                    diff++;
                if (diff == 1)
                    ans++;

                x++;
                y++;
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll T;
    cin >> T;
    while (T--)
    {
        ll i, j, k, n, cnt = 0;
        string s, t;
        cin >> s >> t;
        cout << countSubstrings(s, t) << "\n";
    }

    return 0;
}