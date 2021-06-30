//https://leetcode.com/problems/next-permutation/

//author: _mayor
#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &a)
{
    int i, j, n = a.size();
    int x, y;

    for (i = n - 2; i >= 0; i--)
    {
        if (a[i + 1] > a[i])
            break;
    }
    if (i < 0)
        reverse(a.begin(), a.end());
    else
    {
        for (j = n - 1; j > i; j--)
        {
            if (a[j] > a[i])
            {
                break;
            }
        }

        swap(a[i], a[j]);

        reverse(a.begin() + i + 1, a.end());
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll i, j, k, n, cnt = 0;
    cin >> n;
    vector<int> a;
    for0(i, n) cin >> j, a.pb(j);
    nextPermutation(a);
    for (auto it : a)
        cout << it << " ";
    cout << "\n";

    return 0;
}