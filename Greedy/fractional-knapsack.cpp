#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

class Solution
{
    static bool cmp(Item x, Item y)
    {
        double a = double(x.value) / double(x.weight);
        double b = double(y.value) / double(y.weight);
        return a > b;
    }

public:
    double fractionalKnapsack(int W, Item a[], int n)
    {
        double ans = 0;
        sort(a, a + n, cmp);
        int cur = 0, i;
        for (i = 0; i < n; i++)
        {
            if (cur + a[i].weight <= W)
            {
                ans += a[i].value;
                cur += a[i].weight;
            }
            else
            {
                int rem = W - cur;
                double x = (double(rem) / double(a[i].weight)) * a[i].value;
                ans += x;
                break;
            }
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    cout << setprecision(2) << fixed;
    while (t--)
    {
        int n, W;
        cin >> n >> W;

        Item arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].value >> arr[i].weight;
        }

        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}