//https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

//author: _mayor
#include <bits/stdc++.h>   
using namespace std;

int maxLen(int a[], int n)
{
    int i,sum=0,ans=0;
    unordered_map<int,int> mp; //{sum,i}
    for(i=0;i<n;i++)
    {
        sum+=a[i];
        if(a[i]==0 && ans==0) ans=1;
        if(sum==0) ans=i+1;
        if(mp.find(sum)!=mp.end())
        {
            ans=max(ans,i-mp[sum]);
        }
        else
        {
            mp[sum]=i;
        }
    }
    return ans;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];
        cout << maxLen(A, N) << endl;
    }
}