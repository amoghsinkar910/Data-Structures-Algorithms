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

ll merge(ll a[],ll b[],ll left,ll mid,ll right)
{
    ll i,j,k;
    ll c=0;
    i=left;
    j=mid;
    k=left;
    while(i<=mid-1 && j<=right)
    {
        if(a[i]<=a[j])
            b[k++]=a[i++];
        else
        {
            b[k++]=a[j++];
            c+=(mid-i);
        }
    }
    while(i<=mid-1) b[k++]=a[i++];
    while(j<=right) b[k++]=a[j++];
    for(i=left;i<=right;i++)
        a[i]=b[i];
    
    return c;
}

ll mergesort(ll a[],ll b[],ll left,ll right)
{
    ll inv=0;
    if(left<right)
    {
        ll mid = (left+right)/2;
        inv+=mergesort(a,b,left,mid);
        inv+=mergesort(a,b,mid+1,right);
        inv+=merge(a,b,left,mid+1,right);
    }
    return inv;
}

ll inversionCount(ll a[], ll n)
{
    ll cnt;
    ll b[n];
    cnt = mergesort(a,b,0,n-1);
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    {
        ll i, j, k, n, cnt = 0;
        cin >> n;
        ll a[n];
        for0(i, n) cin >> a[i];
        cout << inversionCount(a, n) << "\n";
    }

    return 0;
}