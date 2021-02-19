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

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool dfs(vector<vector<char>> &a, int st, int e, int idx, string s)
{
    int r = a.size();
    int c = a[0].size();
    int i, j, x, y;

    if (idx == s.size() - 1)
        return true;
    char ch = a[st][e];
    a[st][e] = '#';
    for (i = 0; i < 4; i++)
    {
        x = st + dx[i];
        y = e + dy[i];
        if (x >= 0 && x < r && y >= 0 && y < c && a[x][y] == s[idx + 1])
        {
            if (dfs(a, x, y, idx + 1, s))
                return true;
        }
    }
    a[st][e] = ch;
    return false;
}

bool exist(vector<vector<char>> &a, string s)
{
    int r = a.size();
    int c = a[0].size();
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (a[i][j] == s[0] && dfs(a, i, j, 0, s))
                return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    {
        ll i, j, n, m, cnt = 0;
        char ch;
        cin >> n >> m;
        vector<vector<char>> a(n, vector<char>(m, '@'));
        for0(i, n)
        {
            for0(j, m)
            {
                cin >> a[i][j];
            }
        }
        string s;
        cin >> s;
        if (exist(a, s))
            cout << "Exist" << "\n";
        else
            cout << "-1" << "\n";
    }

    return 0;
}