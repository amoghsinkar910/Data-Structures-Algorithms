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

string replaceWords(vector<string> &mp, string s)
{
    string ans;
    int i, j;
    set<string> st;
    vector<string> v;

    for (string x : mp)
        st.insert(x);

    istringstream sp(s);
    string x;
    while (sp >> x)
    {
        v.push_back(x);
    }

    for (i = 0; i < v.size(); i++)
    {
        string pref = "";
        for (j = 1; j <= v[i].size(); j++)
        {
            pref = v[i].substr(0, j);
            if (st.find(pref) != st.end())
                break;
        }
        ans += pref + " ";
    }
    auto it = ans.end();
    it--;
    ans.erase(it);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    {
        ll i, j, k, n, cnt = 0;
    }

    return 0;
}