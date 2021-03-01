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

bool canReach(vector<int> &gas, vector<int> &cost, int idx)
{
    int n = gas.size();
    int fin = idx;
    int x = gas[idx] - cost[idx] + gas[(idx + 1) % n];
    idx = (idx + 1) % n;
    while (idx != fin)
    {
        if (x < cost[idx])
            return false;
        x = x - cost[idx] + gas[(idx + 1) % n];
        idx = (idx + 1) % n;
    }
    return true;
}

int bruteForce(vector<int> &gas, vector<int> &cost)
{
    vector<int> valid;
    int i, n = gas.size();
    for (i = 0; i < n; i++)
    {
        if (gas[i] >= cost[i])
        {
            valid.push_back(i);
        }
    }

    for (i = 0; i < valid.size(); i++)
    {
        if (canReach(gas, cost, valid[i]))
            return valid[i];
    }
    return -1;
}

int sum(vector<int> v)
{
    int s = 0;
    for (int x : v)
        s += x;
    return s;
}

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    if (sum(gas) < sum(cost))
        return -1;

    int len = 0, n = gas.size(), fuel = 0, start = 0, i = 0;

    while (len != n)
    {
        if (fuel + gas[i] >= cost[i])
        {
            len++;
            fuel += gas[i] - cost[i];
            if (start == -1)
                start = i;
        }
        else
        {
            len = 0;
            fuel = 0;
            start = -1;
        }
        i = (i + 1) % n;
    }
    return start;
}

int trick(vector<int> &gas, vector<int> &cost)
{
    int mn = 0, idx = 0, fuel = 0, i;
    for (i = 0; i < gas.size(); i++)
    {
        fuel += gas[i] - cost[i];
        if (fuel < mn)
        {
            mn = fuel;
            idx = i + 1;
        }
    }
    return fuel >= 0 ? idx : -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    {
        int i, j, k, n, cnt = 0;
        cin >> n;
        vector<int> gas, cost;
        for0(i, n)
        {
            cin >> j;
            gas.pb(j);
        }
        for0(i, n)
        {
            cin >> j;
            cost.pb(j);
        }
        cout << bruteForce(gas, cost) << "\n";
        cout << canCompleteCircuit(gas, cost) << "\n";
        cout << trick(gas, cost) << "\n";
    }

    return 0;
}