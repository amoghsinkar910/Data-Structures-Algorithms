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

bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    stack<int> st;
    int n = pushed.size();
    int i, j = 0;
    for (i = 0; i < n; i++)
    {
        st.push(pushed[i]);
        while (!st.empty() && j < n && st.top() == popped[j])
        {
            st.pop();
            j++;
        }
    }

    return st.size() == 0;
}

int main()
{
    int i, n, x;
    vector<int> pushed, popped;   
    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>x;
        pushed.push_back(x);
    }
    for(i=0;i<n;i++)
    {
        cin>>x;
        popped.push_back(x);
    }

    cout << validateStackSequences(pushed, popped) << "\n";

    return 0;
}