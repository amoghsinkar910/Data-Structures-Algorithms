//https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getMinDiff(int a[], int n, int k) {
        sort(a,a+n);
        int i,mx,mn;
        int res = a[n-1]-a[0];
        for(i=1;i<n;i++)
        {
            if(a[i]>=k)
            {
                mx = max(a[i-1]+k,a[n-1]-k);
                mn = min(a[0]+k,a[i]-k);
                res = min(res,mx-mn);
            }
            else continue;
        }
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
