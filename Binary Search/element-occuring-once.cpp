//https://practice.geeksforgeeks.org/problems/find-the-element-that-appears-once-in-sorted-array0624/1#

#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
  //make a partition at the sigle occuring element, so dividing arr into left & right half
  //considering left half=> even index=first occurence, odd index=second occurence
    int findOnce(int a[], int n)
    {
        int l=0,r=n-2;
        while(l<=r)
        {
            int mid = (l+r)/2;
            //if mid is odd => mid^1 gives prev even no. i.e mid-1
            //if mid is even => mid^1 gives next odd no. i.e mid+1
            if(a[mid]==a[mid^1])
                l=mid+1;
            else
                r=mid-1;
        }
        return a[l];
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
} 