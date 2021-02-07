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

int romanToInt(string s)
{
    int i, n = s.size(), ans = 0;
    for (i = 0; i < n;)
    {
        if (s[i] == 'I')
        {
            if (s[i + 1] == 'V')
                ans += 4, i += 2;
            else if (s[i + 1] == 'X')
                ans += 9, i += 2;
            else
                ans += 1, i++;
        }
        else if (s[i] == 'X')
        {
            if (s[i + 1] == 'L')
                ans += 40, i += 2;
            else if (s[i + 1] == 'C')
                ans += 90, i += 2;
            else
                ans += 10, i++;
        }
        else if (s[i] == 'C')
        {
            if (s[i + 1] == 'D')
                ans += 400, i += 2;
            else if (s[i + 1] == 'M')
                ans += 900, i += 2;
            else
                ans += 100, i++;
        }
        else if (s[i] == 'V')
            ans += 5, i++;
        else if (s[i] == 'L')
            ans += 50, i++;
        else if (s[i] == 'D')
            ans += 500, i++;
        else if (s[i] == 'M')
            ans += 1000, i++;
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
        cin>>s;
        cout << romanToInt(s) << "\n";
    }

    return 0;
}