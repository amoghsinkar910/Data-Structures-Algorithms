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

//gives TLE though

int partition(int a[], int l, int r) //fining pivot element by first taking it as 
//the last element then finding its correct posn
{
    int x = a[r], i, j;
    i = l;
    for (j = l; j < r; j++)
    {
        if (a[j] <= x)
        {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[r]);
    return i;
}

//using concept of mergesort, find pivot element unti; it is equal to k
int kthSmallest(int a[], int l, int r, int k) 
{
    if (k > 0 && k <= r - l + 1)
    {
        int piv = partition(a, l, r);
        if (piv - l + 1 == k)
        {
            return a[piv];
        }
        else if (piv - l + 1 > k)
        {
            return kthSmallest(a, l, piv - 1, k);
        }
        else
            return kthSmallest(a, piv + 1, r, k - piv + l - 1);
    }

    return INT_MAX;
}

//using max heap => priority queue
int kthSmallestpq(int a[], int l, int r, int k) 
{
    priority_queue<int> pq;
    for(int i=l;i<=r;i++)
    {
        pq.push(a[i]);
        if(pq.size()>k){
            pq.pop();
        }
    }
    return pq.top();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int i, n, k;
    cin >> n >> k;
    int a[n];
    for0(i, n) cin >> a[i];

    cout << kthSmallestpq(a, 0, n - 1, k) << "\n";

    return 0;
}