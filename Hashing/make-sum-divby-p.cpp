//https://leetcode.com/problems/make-sum-divisible-by-p/

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

// we want to make sum divisible by p :-

// Calculate total sum of array
// a. if sum already divisible by p , return 0
// b. calculate remainder ( rem = total_sum % p )
// Now we need to find smallest subarray which gives remainder 'rem' on division by p
// To find such subarray we'll use prefix sum array % p
// idea behind step 3 is -> if ( S1 - S2 )%p = rem then subarray between S1 and S2 is our desried array
// to handle negative result of (S1-S2) cases we will add 'p' to result of (S1-S2)%p
// Conclusion - on prefix sum array look for 3 things
// a. element = nums[i]-rem
// b. element = nums[i]+k-rem (for negative case)
// c. if current element in prefix sum array = rem only
// if final length calculated = INT_MAX (initial set value) or = length of nums , then return -1 , otherwise ans .

int minSubarray(vector<int> &a, int p)
{
    int i, n = a.size(), cur = 0, s = 0;
    unordered_map<int, int> mp;

    for (i = 0; i < n; i++)
        s = (s + a[i]) % p;

    int ans = INT_MAX;
    if (s == 0)
        return 0;
    int need = s;
    mp[0] = -1;
    for (i = 0; i < n; i++)
    {
        cur = (cur + a[i]) % p;
        int rem = (cur - need + p) % p;
        if (mp.find(rem) != mp.end())
            ans = min(ans, i - mp[rem]);
        mp[cur] = i;
    }

    return (ans >= n ? -1 : ans);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll i, j, p, n, cnt = 0;
    cin >> n >> p;
    vector<int> a;
    for0(i, n) cin >> j, a.pb(j);

    cout << minSubarray(a, p) << "\n";

    return 0;
}