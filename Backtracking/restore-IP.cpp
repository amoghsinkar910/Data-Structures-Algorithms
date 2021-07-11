//https://leetcode.com/problems/restore-ip-addresses/

//author: _mayor
#include <bits/stdc++.h>
using namespace std;

//sub contins the substrings i.e if IP iis a.b.c.d then sub contains [a,b,c,d]
vector<string> ans, sub;

void rec(int start, int part, string &s)
{
    if (start == s.size() && part == 4)
    {
        string temp;
        //constructing the IP string from vector sub
        for (string x : sub)
        {
            temp += x + ".";
        }
        temp.pop_back(); //removing the last dot
        ans.push_back(temp);
        return;
    }

    if (part > 4)
        return;
    for (int len = 1; len < 4 && len + start - 1 < s.size(); len++)
    {
        string temp = s.substr(start, len);
        int num = stoi(temp);
        if (num > 255 || (temp.size() > 1 && temp[0] == '0')) //checking validity
            continue;
        sub.push_back(temp);
        rec(start + len, part + 1, s);
        sub.pop_back();
    }
}

vector<string> restoreIpAddresses(string s)
{
    rec(0, 0, s);
    return ans;
}

int main()
{
    string s;
    cin >> s;
    ans = restoreIpAddresses(s);
    for (auto it : ans)
        cout << it << "\n";
    return 0;
}