#include <bits/stdc++.h>

using namespace std;

string conv(int convert)
{
    string ret = "";
    
    int C = convert;
    
    while(C > 0)
    {
        ret += ((C % 2) + '0');
        
        C /= 2;
    }
    
    return ret;
}

pair<int, int> solve(string params)
{
    string S = params;
    
    int t = 0;
    
    int second = 0;
    
    for (t = 0;; t++)
    {
        if (S == "1")
            break;
        
        int o_cnt = 0, z_cnt = 0;
        
        for (int i = 0; i < (int)S.length(); i++)
        {
            if (S[i] == '1') o_cnt++;
            else z_cnt++;
        }
        
        second += z_cnt;
        
        S = conv(o_cnt);
    }
    
    return {t, second};
}


vector<int> solution(string s) {
    vector<int> answer;
    
    pair<int, int> ans = solve(s);
    
    return {ans.first, ans.second};
}