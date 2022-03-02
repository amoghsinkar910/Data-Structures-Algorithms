//https://leetcode.com/problems/rotting-oranges/submissions/

//author: _mayor
#include <bits/stdc++.h>   
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& a) {
        
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,-1,0,1};
        int i,j,k,r=a.size(),c=a[0].size(),cnt=0;
        queue<pair<int,int>> q;
        
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++) 
            {
                cnt+=(a[i][j]==1 || a[i][j]==2);
                if(a[i][j]==2) q.push({i,j});
            }    
        }
        
        int days=-1;
        while(!q.empty())
        {
            days++;
            int sz=q.size();
            for(i=0;i<sz;i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                cnt--;
                q.pop();
                for(k=0;k<4;k++)
                {
                    int X = x+dx[k];
                    int Y = y+dy[k];
                    if(X>=0 && X<r && Y>=0 && Y<c && a[X][Y]==1)
                    {
                        a[X][Y]=2;
                        q.push({X,Y});
                    }
                }
            }
        }
        
        if(cnt==0) return max(0,days);
        return -1;
        
        
        
    }
};

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    return 0;
}

