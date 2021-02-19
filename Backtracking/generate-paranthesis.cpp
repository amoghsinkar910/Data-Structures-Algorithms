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

bool valid(string &par)
{
    stack<char> st;
    for (int i = 0; i < par.size(); i++)
    {
        if (par[i] == '(')
            st.push(par[i]);
        else
        {
            char c = st.top();
            if (!st.empty())
                st.pop();
        }
    }
    if (st.empty())
        return true;
    return false;
}
//STL solution => much slower
vector<string> generateParenthesisSTL(int n)
{
    string par;
    for (int i = 0; i < n; i++)
    {
        par.push_back('(');
    }
    for (int i = 0; i < n; i++)
    {
        par.push_back(')');
    }
    //cout<<par<<"\n";
    vector<string> ans;
    do
    {
        if (valid(par))
            ans.push_back(par);
    } while (next_permutation(par.begin(), par.end()));

    return ans;
}

vector<string> v;
//bactracking solution => faster
void rec(string s, int l, int r, vector<string> &v)
{
    if (l == 0 and r == 0)
    {
        v.push_back(s);
        return;
    }
    if (l > 0)
    {
        s += '(';
        rec(s, l - 1, r, v);
        s.pop_back();
    }
    if (r > l)
    {
        s += ')';
        rec(s, l, r - 1, v);
        s.pop_back();
    }
}
vector<string> generateParenthesis(int n)
{
    rec("", n, n, v);
    return v;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    {
        int i, n;
        cin >> n;
        vector<string> a1, a2;
        a1 = generateParenthesis(n);
        //a2 = generateParenthesisSTL(n);
        for (i = 0; i < a1.size(); i++)
            cout << a1[i] << " ";
        cout << "\n";
    }

    return 0;
}