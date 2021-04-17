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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll T;
    cin >> T;
    while (T--)
    {
        ll i, j, k, n, t = 0, m = 0;
        cin >> n;
        string s;
        cin >> s;
        ll f = 1;
        for0(i, n)
        {
            if (s[i] == 'T')
                t++;
            else
                m++;

            if (m > t)
            {
                f = 0;
                break;
            }
        }
        if (f)
        {
            t = 0, m = 0;
            forr0(i, n)
            {
                if (s[i] == 'T')
                    t++;
                else
                    m++;

                if (m > t)
                {
                    f = 0;
                    break;
                }
            }
        }
        if (t != 2 * m)
            f = 0;
        if (f)
            cout << "YES"
                 << "\n";
        else
            cout << "NO"
                 << "\n";
    }

    return 0;
}