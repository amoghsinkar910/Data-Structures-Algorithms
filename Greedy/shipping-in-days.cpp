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

//fn to check if packages can be shipped in "days" with max capacity as maxw
bool check(vector<int> &w, int days, int maxw)
{
    int cnt = 1, sum = 0, i;
    for (i = 0; i < w.size(); i++)
    {
        if (sum + w[i] > maxw)
        {
            cnt++; //increase days as max capacity is reached
            sum = w[i];
        }
        else
            sum += w[i];
    }
    return cnt <= days;
}

int shipWithinDays(vector<int> &w, int days)
{
    int i, n = w.size();
    //l- max weight in arr will be min weight
    //r- sum of all weights as all ccan be shipped in one day only
    int l = 0, r = 0;
    for (i = 0; i < n; i++)
    {
        l = max(l, w[i]);
        r += w[i];
    }

    //binary search for the least weight possible
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (check(w, days, mid))
        {
            r = mid; //possibilty of reducing the curr weight
        }
        else
        {
            l = mid + 1; //not able to ship in "days" so increase capacity
        }
    }
    return l;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll i, k, n, days;
    cin >> days >> n;
    vector<int> w;
    for0(i, n) cin >> k, w.pb(k);

    cout << shipWithinDays(w, days) << "\n";

    return 0;
}