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

vector<vector<int>> merge(vector<vector<int>> &a)
{
    vector<vector<int>> ans;
    int i, l, r;
    sort(a.begin(), a.end());
    l = a[0][0];
    r = a[0][1];
    for (i = 1; i < a.size(); i++)
    {
        if (a[i][0] <= r)
        {
            r = max(r, a[i][1]);
        }
        else
        {
            vector<int> x;
            x.push_back(l);
            x.push_back(r);
            ans.push_back(x);
            l = a[i][0];
            r = a[i][1];
        }
    }
    ans.push_back({l, r});
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    {
        int i, j, k, n, cnt = 0;
        cin>>n;
        vector<vector<int>> a(n),ans;
        for0(i,n)
        {
            cin>>j>>k;
            a[i].push_back(j);
            a[i].push_back(k);
        }
        ans = merge(a);
        for0(i,ans.size())
        {
            for(auto it:ans[i]) cout<<it<<" ";
            cout<<"\n";
        }
    }

    return 0;
}