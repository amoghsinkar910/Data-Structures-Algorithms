//https://leetcode.com/problems/next-greater-element-ii/

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

vector<int> nextGreaterElements(vector<int> &a)
{
    stack<int> s;
    vector<int> ans;
    int n = a.size();
    for (int i = n - 1; i >= 0; i--)
        s.push(a[i]);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && a[i] >= s.top())
            s.pop();

        if (s.empty())
            ans.push_back(-1);
        else
            ans.push_back(s.top());

        s.push(a[i]);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> a;
    int i, n, x;
    cin >> n;
    for0(i, n) cin >> x, a.pb(x);

    vector<int> ans = nextGreaterElements(a);
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";

    return 0;
}