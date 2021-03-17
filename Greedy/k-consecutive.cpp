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

bool isPossibleDivide(vector<int> &a, int k)
{
    int n = int(a.size()), i, j, c;
    unordered_map<int, int> mp;
    for (i = 0; i < n; i++)
    {
        mp[a[i]]++;
    }

    sort(a.begin(), a.end());
    for (i = 0; i < n; i++)
    {
        if (!mp[a[i]])
            continue;
        j = 1;
        c = 1;
        while (c < k)
        {
            if (mp[a[i] + j] == 0)
                return false;
            mp[a[i] + j]--;
            j++;
            c++;
        }
        mp[a[i]]--;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    {
        int i, j, k, n, cnt = 0;
        vector<int> a;
        cin >> n >> k;
        for0(i, n) cin >> j, a.pb(j);
        cout << isPossibleDivide(a, k) << "\n";
    }

    return 0;
}