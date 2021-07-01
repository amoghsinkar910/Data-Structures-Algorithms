//author: _mayor
#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &a, int l, int mid, int r)
{
    vector<int> v;
    int cnt = 0;
    int j = mid + 1;
    for (int i = l; i <= mid; i++)
    {
        while (j <= r && a[i] > 2LL * a[j])
            j++;
        cnt += (j - mid - 1);
    }

    int i = l;
    j = mid + 1;

    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
        {
            v.push_back(a[i++]);
        }
        else
            v.push_back(a[j++]);
    }

    while (i <= mid)
        v.push_back(a[i++]);
    while (j <= r)
        v.push_back(a[j++]);

    for (i = l; i <= r; i++)
        a[i] = v[i - l];
    return cnt;
}

int mergesort(vector<int> &a, int x, int y)
{
    if (x >= y)
        return 0;
    int inv = 0;
    int mid = (x + y) / 2;
    inv += mergesort(a, x, mid);
    inv += mergesort(a, mid + 1, y);
    inv += merge(a, x, mid, y);
    return inv;
}

int reversePairs(vector<int> &a)
{
    int ans = mergesort(a, 0, a.size() - 1);
    return ans;
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

    cout << reversePairs(a) << "\n";

    return 0;
}