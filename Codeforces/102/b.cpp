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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t;
    cin >> t;
    while (t--)
    {
        ll i;
        string a, b, c, d;
        set<char> s1, s2;
        cin >> a >> b;
        ll n = a.size(), m = b.size();
        for0(i, n) s1.insert(a[i]);
        for0(i, m) s2.insert(b[i]);
        if (s1.size() == 1 && s2.size() == 1 && *s1.begin() == *s2.begin())
        {
            ll N = (n * m) / (__gcd(n, m));
            for0(i, N) cout << *s1.begin();
            cout << "\n";
        }
        else
        {
            ll gc = __gcd(n, m);
            ll lc = (n * m) / gc;
            ll mx = max(n, m);
            ll mn = min(n, m);
            if (mx % mn != 0)
            {
                for0(i, lc / n) c += a;
                for0(i, lc / m) d += b;
                if (c == d)
                {
                    cout << c << "\n";
                }
                else
                    cout << -1 << "\n";
            }
            else
            {

                ll len = mx / mn;
                string c, temp;

                if (n > m)
                {
                    //cout<<"NGR"<<"\n";
                    for0(i, len)
                    {
                        temp += b;
                    }
                    if (temp == a)
                        cout << temp << "\n";
                    else
                        cout << -1 << "\n";
                }
                else
                {
                    //cout<<"MGR"<<"\n";
                    for0(i, len)
                    {
                        temp += a;
                    }
                    if (temp == b)
                        cout << temp << "\n";
                    else
                        cout << -1 << "\n";
                }
            }
        }
    }

    return 0;
}

// //author: _mayor
// #include <bits/stdc++.h>

// #define for0(i, n) for (long long  i = 0; i < n; i++)
// #define for1(i, n) for (long long  i = 1; i <= n; i++)
// #define forc(i, l, r) for (long long  i = l; i <= r; ++i)
// #define forr0(i, n) for (long long  i = n - 1; i >= 0; i--)
// #define forr1(i, n) for (long long  i = n; i >= 1; i--)

// #define pb push_back
// #define fi first
// #define se second

// #define all(x) (x).begin(), (x).end()
// #define rall(x) (x).rbegin, (x).rend()

// using namespace std;

// typedef vector<int> vi;
// typedef vector<vi> vvi;
// typedef pair<int, int> ii;
// typedef vector<ii> vii;
// typedef long long ll;
// typedef long long int lli;
// typedef vector<ll> vll;
// typedef vector<vll> vvll;
// typedef double ld;

// const ll N = 1e5 + 5;
// const ll mod = 1e9 + 7;
// const ll INF = 1e9;

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt", "r", stdin);
//         freopen("output.txt", "w", stdout);
//     #endif
//     ll t;
//     cin>>t;
//     while(t--)
//     {
//         ll i;
//         string a,b,c,d;
//         cin>>a>>b;
//         ll n=a.size(),m=b.size();
//         ll lcm=(n*m)/(__gcd(n,m));
//         while(c.size()<lcm)
//             c+=a;
//         while(d.size()<lcm)
//             d+=b;

//         if(c==d)
//             cout<<c<<"\n";
//         else
//             cout<<-1<<"\n";
//     }

//     return 0;
// }

