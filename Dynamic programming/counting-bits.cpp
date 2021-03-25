//https://leetcode.com/problems/counting-bits/

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

vector<int> countBits(int n)
{
    vector<int> dp(n + 1, 0);
    int i, x;
    dp[0] = 0;
    if (n == 0)
        return {0};
    dp[1] = 1;

    for (i = 2; i <= n; i++)
    {
        if (floor(log2(i)) == ceil(log2(i)))
        {
            dp[i] = 1;
            x = i;
        }
        else
        {
            dp[i] = dp[x] + dp[i - x];
        }
    }
    return dp;
}

vector<int> countBits1(int n)
{
    vector<int> dp(n + 1, 0);
    int i, x;

    for (i = 1; i <= n; i++)
    {
        // when the number is a power of 2
        if (floor(log2(i)) == ceil(log2(i)))
        {
            dp[i] = 1;
        }
        else
        {
            //if number is odd, we only add 1 to the prev even number
            if (i & 1)
            {
                dp[i] = dp[i - 1] + 1;
            }
            //we will use some maths here,
            //let prev odd number be 2x+2y+...+1
            //then the next even number will be 2x+2y+...+1+1 i.e 2x+2y+...+2
            //2(x+y+...+1) which is just the left shift of the i/2th number
            //so number of bits remain the same
            else
            {
                dp[i] = dp[i / 2];
            }
        }
    }
    return dp;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    {
        int n;
        cin >> n;
        vector<int> ans = countBits(n);
        for (auto it : ans)
            cout << it << " ";
        cout << "\n";
    }

    return 0;
}