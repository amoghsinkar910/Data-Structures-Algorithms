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

bool static cmp(string a, string b)
{
    return a + b > b + a;
}

string largestNumber(vector<int> &a)
{
    if (a.size() == 0)
        return "";
    int i, n = a.size();
    string ans;
    vector<string> x;
    for (i = 0; i < n; i++)
        x.push_back(to_string(a[i]));
    sort(x.begin(), x.end(), cmp);

    if (x[0] == "0")
        return "0";
    for (i = 0; i < n; i++)
    {
        ans += x[i];
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    {
        ll i, j, k, n, cnt = 0;
        cin >> n;
        vector<int> a;
        for0(i, n)
        {
            cin >> k;
            a.pb(k);
        }
        cout << largestNumber(a) << "\n";
    }

    return 0;
}