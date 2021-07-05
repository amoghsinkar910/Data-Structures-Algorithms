//https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

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

struct job
{
    int id;
    int dead;
    int profit;
};

bool cmp(job x, job y)
{
    return (x.profit > y.profit);
    // if(x.d==y.d && x.pr>y.pr) return true;
    // else if(x.d<y.d) return true;
    // return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int i, j, k, n;
    cin >> n;
    job a[n];
    for0(i, n)
    {
        cin >> a[i].id >> a[i].dead >> a[i].profit;
    }
    sort(a, a + n, cmp);
    // cout << "sort\n";
    // for0(i, n) cout << a[i].id << " " << a[i].dead << " " << a[i].profit << "\n";

    vector<int> vis(105, 0);
    int cnt = 0, pr = 0;
    for (i = 0; i < n; i++)
    {
        if (vis[a[i].dead] == 0)
        {
            cnt++;
            pr += a[i].profit;
            vis[a[i].dead]++;
        }
        else
        {
            for (j = a[i].dead; j >= 1; j--)
            {
                if (vis[j] == 0)
                {
                    cnt++;
                    pr += a[i].profit;
                    vis[j]++;
                    break;
                }
            }
        }
    }
    cout << cnt << " " << pr << "\n";

    return 0;
}