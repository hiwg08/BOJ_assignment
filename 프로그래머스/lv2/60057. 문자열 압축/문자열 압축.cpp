#include <bits/stdc++.h>

using namespace std;

int ans = INT_MAX;

void solve(string params)
{
    int st = (int)params.size() % 2 == 0 ? (int)params.size() / 2 : (int)params.size() / 2 + 1;
    for (int i = 1; i <= st; i++)
    {
        int Idx = 0, cnt = 0;
        
        string tmp = "", total = "";
        
        while(Idx < (int)params.size())
        {
            if (tmp == "" || tmp == params.substr(Idx, i))
                cnt++;
            else
            {
                cnt == 1 ? total += tmp : total += to_string(cnt) + tmp;
                cnt = 1;
            }
            
            tmp = params.substr(Idx, i);
            Idx += i;
        }
        
        cnt == 1 ? total += tmp : total += to_string(cnt) + tmp;
        
        ans = min(ans, (int)total.size());
    }
}

int solution(string s) {
    
    solve(s);
    
    return ans;
}