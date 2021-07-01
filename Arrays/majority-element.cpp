//author: _mayor
#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> &a)
{
    vector<int> v;
    int i, ele1 = 0, ele2 = 0, cnt1 = 0, cnt2 = 0, n = a.size();
    for (i = 0; i < a.size(); i++)
    {
        if (a[i] == ele1)
            cnt1++;
        else if (a[i] == ele2)
            cnt2++;
        else if (cnt1 == 0)
            ele1 = a[i], cnt1++;
        else if (cnt2 == 0)
            ele2 = a[i], cnt2++;
        else
            cnt1--, cnt2--;
    }

    cnt1 = 0, cnt2 = 0;
    for (int i : a)
    {
        if (i == ele1)
            cnt1++;
        else if (i == ele2)
            cnt2++;
    }

    if (cnt1 > n / 3)
        v.push_back(ele1);
    if (cnt2 > n / 3)
        v.push_back(ele2);
    return v;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll i, j, k, n, cnt = 0;
    cin >> n;
    vector<int> a;
    for (i = 0; i < n; i++)
    {
        cin >> j;
        a.push_back(j);
    }

    vector<int> ans = majorityElement(a);
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";

    return 0;
}