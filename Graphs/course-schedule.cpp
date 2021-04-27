//https://leetcode.com/problems/course-schedule/

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

//here we have to check for cycles in directed graph using dfs
bool dfs(int i, int n, vector<bool> &vis, vector<int> &ans, vector<int> g[n])
{
    vis[i] = true;
    ans[i] = true;
    for (auto node : g[i])
    {
        if (!vis[node])
        {
            if (dfs(node, n, vis, ans, g))
                return true;
        }
        else if (ans[node])
            return true;
    }
    ans[i] = false;
    return false;
}
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    int n = numCourses;
    vector<int> g[n];
    for (int i = 0; i < prerequisites.size(); i++)
        g[prerequisites[i][1]].push_back(prerequisites[i][0]);
    vector<bool> vis(n, false);
    vector<int> ans(n, false);
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, n, vis, ans, g))
            {
                flag = true;
                break;
            }
        }
    }
    return !flag;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //init

    return 0;
}