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

vector<vector<string>> ans;
bool check(vector<string> &b, int row, int col)
{
    int i, j;
    //col
    for (i = row; i >= 0; i--)
    {
        if (b[i][col] == 'Q')
            return false;
    }

    //left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (b[i][j] == 'Q')
            return false;
    }

    //right diagonal
    for (i = row, j = col; i >= 0 && j < b.size(); i--, j++)
    {
        if (b[i][j] == 'Q')
            return false;
    }
    return true;
}

//filling row wise
void rec(vector<string> &b, int row)
{
    if (row == b.size())
    {
        ans.push_back(b);
        return;
    }

    for (int i = 0; i < b.size(); i++)
    {
        if (check(b, row, i))
        {
            b[row][i] = 'Q';
            rec(b, row + 1);
            b[row][i] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<string> b(n, string(n, '.'));
    rec(b, 0);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}