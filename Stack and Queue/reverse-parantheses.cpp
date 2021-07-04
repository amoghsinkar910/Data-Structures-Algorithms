//https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

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

string reverseParentheses(string s)
{
    int i, n = s.size();
    stack<char> st;
    string temp;

    for (i = 0; i < n; i++)
    {
        if (s[i] == ')')
        {
            temp = "";
            while (st.top() != '(')
            {
                temp += st.top();
                st.pop();
            }
            st.pop();
            for (char c : temp)
                st.push(c);
        }
        else
            st.push(s[i]);
    }

    string ans;
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    cout << reverseParentheses(s) << "\n";

    return 0;
}