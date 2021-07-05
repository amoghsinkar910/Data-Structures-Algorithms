#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct meeting
    {
        int start;
        int end;
        int pos;
    };

    static bool cmprt(meeting m1, meeting m2)
    {
        if (m1.end < m2.end)
            return true;
        else if (m1.end > m2.end)
            return false;
        else if (m1.pos < m2.pos)
            return true;
        return false;
    }

    int maxMeetings(int start[], int end[], int n)
    {
        meeting a[n];
        int i;
        for (i = 0; i < n; i++)
        {
            a[i].start = start[i];
            a[i].end = end[i];
            a[i].pos = i + 1;
        }

        sort(a, a + n, cmprt);

        int last = a[0].end, ans = 1;

        for (i = 1; i < n; i++)
        {
            if (a[i].start > last)
            {
                last = a[i].end;
                ans++;
            }
        }
        return ans;
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
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}