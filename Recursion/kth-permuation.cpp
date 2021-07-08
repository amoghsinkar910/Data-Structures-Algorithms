//https://leetcode.com/problems/permutation-sequence/

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

void nextPermutation(string &s)
{
    int i, j, n = s.size();
    int x, y;

    for (i = n - 2; i >= 0; i--)
    {
        if (s[i + 1] > s[i])
            break;
    }
    if (i < 0)
        reverse(s.begin(), s.end());
    else
    {
        for (j = n - 1; j > i; j--)
        {
            if (s[j] > s[i])
            {
                break;
            }
        }

        swap(s[i], s[j]);

        reverse(s.begin() + i + 1, s.end());
    }
}
string getPermutationBrute(int n, int k) //brute force
{
    string s, ans;
    char c = '1';
    int x = n;
    while (x--)
    {
        s += c;
        c++;
    }
    k--;
    while (k >= 1)
    {
        k--;
        nextPermutation(s);
    }

    return s;
}

string getPermutation(int n, int k)
{
    vector<int> a; //stores (1,2,...n)
    string ans = "";

    //calc (n-1)!
    int fact = 1;
    for (int i = 1; i < n; i++)
    {
        fact = fact * i;
        a.push_back(i);
    }
    a.push_back(n);

    k--; //for 0 based indexing

    // [1,2,3,4] => 4!
    // if these perms are stored in an array then there indices will be

    // 1 + [2,3,4] => 3! i.e (n-1)! index =>(0-5)
    // 2 + [1,3,4] => 3! i.e (n-1)! index =>(6-11)
    // 3 + [1,2,4] => 3! i.e (n-1)! index =>(12-17)
    // 4 + [1,2,3] => 3! i.e (n-1)! index =>(18-23)

    // so n! is divided into (n!/n) groups of size (n-1)!
    // so here 4! is divided onto 4 groups of size 6, so total of 24 permutations
    // to find in which group does K lie => k/((n-1)!)
    // find index of K in that group => k%(n-1)!

    // now again divide the array into smaller parts
    // and update factorial to (prevFact-1)!

    while (a.size())
    {
        int idx = k / fact;
        ans += to_string(a[idx]);
        a.erase(a.begin() + idx);

        k = k % fact;
        if (a.size())
            fact = fact / a.size(); // supposse fact=x! then this line is (x-1)! = x!/x i.e fact/x;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int i, j, k, n, cnt = 0;
    cin >> n >> k;

    cout << getPermutation(n, k) << "\n";
    return 0;
}