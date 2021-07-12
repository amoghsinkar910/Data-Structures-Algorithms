//https://practice.geeksforgeeks.org/problems/find-nth-root-of-m5843/1

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

ll fastPower(ll base, ll pow)
{
    ll ans = 1;
    while (pow > 0)
    {
        if (pow & 1)
            ans = ans * base;
        base = base * base;
        pow = pow / 2;
    }
    return ans;
}

int NthRoot(int n, int m) //ans^n = m i.e ans = nth root of m
{
    ll ans = -1;
    ll l = 1LL, r = m, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        ll x = mid;
        for (int i = 1; i < n; i++)
        {
            x = x * mid;
            if (x > m * 1LL)
                break;
        }
        if (x == m * 1LL)
        {
            ans = mid;
            break;
        }
        else if (x < m)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return int(ans);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    cout << NthRoot(n, m) << "\n";

    return 0;
}