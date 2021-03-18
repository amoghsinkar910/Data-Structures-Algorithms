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

int minSteps(int n)
{
    int dp[1001], i, j;
    int a, b, c, d;
    dp[0] = dp[1] = 0;
    dp[2] = 2;
    dp[3] = 3;

    for (i = 4; i <= n; i++)
    {
        dp[i] = i;
        for (j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                a = i / j;
                b = j;
                c = i / a;
                d = i / b;
                dp[i] = min(dp[i], dp[a] + c);
                dp[i] = min(dp[i], dp[b] + d);
            }
        }
    }
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    {
        int i, j, k, n, cnt = 0;
        cin >> n;
        cout << minSteps(n) << "\n";
    }

    return 0;
}