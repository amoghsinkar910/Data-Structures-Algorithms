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

string mergeAlternately(string s1, string s2)
{
    int i, j, n = s1.size(), m = s2.size();
    i = 0, j = 0;
    string ans;
    while (i < n && j < m)
    {
        ans.push_back(s1[i++]);
        ans.push_back(s2[j++]);
    }
    if (i < n)
    {
        while (i < n)
        {
            ans.push_back(s1[i]);
            i++;
        }
    }
    if (j < m)
    {
        while (j < m)
        {
            ans.push_back(s2[j]);
            j++;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll i, j, k, n, cnt = 0;
        string s1, s2;
        cin >> s1 >> s2;
        cout << mergeAlternately(s1, s2) << "\n";
    }

    return 0;
}