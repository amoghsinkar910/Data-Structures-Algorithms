//https://leetcode.com/problems/longest-consecutive-sequence/

//author: _mayor
#include <bits/stdc++.h>
using namespace std;

//sorting=> O(nlogn)
int longestConsecutive1(vector<int> &a)
{
    int i, len = 1, ans = 1, n = a.size();
    if (!n)
        return 0;
    sort(a.begin(), a.end());
    for (i = 0; i < n - 1; i++)
    {
        if (a[i] == a[i + 1])
            continue;
        else if (a[i + 1] - a[i] == 1)
            len++;
        else
        {
            ans = max(ans, len);
            len = 1;
        }
    }
    ans = max(len, ans);
    return ans;
}

//hashing=> O(n)
int longestConsecutive(vector<int> &a)
{
    unordered_map<int, int> mp;
    int i, n = a.size();
    for (i = 0; i < n; i++)
        mp[a[i]]++;

    int ans = 0;

    for (i = 0; i < n; i++)
    {
        int len = 0;
        if (mp[a[i] - 1] == 0)
        {
            int next = a[i] + 1;
            len = 1;
            while (mp[next])
            {
                len++;
                next++;
            }
        }
        ans = max(ans, len);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int i, j, k, n;
    cin >> n;
    vector<int> a;
    for (i = 0; i < n; i++)
        cin >> k, a.push_back(k);

    cout << longestConsecutive(a) << "\n";

    return 0;
}