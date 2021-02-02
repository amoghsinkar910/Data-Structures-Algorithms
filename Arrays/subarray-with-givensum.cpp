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

vector<int> subarraySum(int a[], int n, int s)
{
    int i = 0, j = 0, sum = a[0];
    while (i < n && j < n)
    {
        if (sum == s)
        {
            return {i + 1, j + 1};
        }
        else if (sum > s)
        {
            sum -= a[i];
            i++;
        }
        else if (sum < s)
        {
            j++;
            sum += a[j];
        }
    }
    return {-1};
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    {
        int i, j, n, s, sum;
        cin >> n >> s;
        int a[n];
        for0(i, n) cin >> a[i];
        vector<int> ans = subarraySum(a,n,s);
        for(auto it:ans) cout<<it<<" ";
        cout<<"\n";
    }

    return 0;
}
