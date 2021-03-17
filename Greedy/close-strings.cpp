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

bool closeStrings(string a, string b)
{
    int n = a.size(), m = b.size(), i;
    if (m != n)
        return false;

    vector<int> c(26, 0);
    vector<int> d(26, 0);
    vector<int> e(26, 0);
    vector<int> f(26, 0);

    for (i = 0; i < n; i++)
    {
        c[a[i] - 'a']++;
        d[a[i] - 'a'] = 1;
    }

    for (i = 0; i < m; i++)
    {
        e[b[i] - 'a']++;
        f[b[i] - 'a'] = 1;
    }

    sort(c.begin(), c.end());
    sort(e.begin(), e.end());
    if (c == e && d == f)
        return true;
    return false;
}

bool pqcloseStrings(string a, string b)
{
    int n = a.size(), m = b.size(), i;
    if (m != n)
        return false;

    unordered_map<char, int> m1, m2;
    priority_queue<pair<int, char>> p1, p2;

    for (i = 0; i < n; i++)
    {
        m1[a[i]]++;
        m2[b[i]]++;
    }

    for (auto x : m1)
        p1.push({x.second, x.first});

    for (auto x : m2)
        p2.push({x.second, x.first});

    while (p1.size() > 0 && p2.size() > 0)
    {
        if (m1[p2.top().second] == 0)
            return false;
        if (p1.top().first != p2.top().first)
            return false;
        p1.pop();
        p2.pop();
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
        string a, b;
        cin >> a >> b;
        cout << closeStrings(a, b) << "\n";
        cout << pqcloseStrings(a, b) << "\n";
    }

    return 0;
}