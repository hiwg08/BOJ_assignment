#include <bits/stdc++.h>

using namespace std;

string S;

bool check_correct(string params)
{
    stack<char> S;
    
    for (int i = 0; i < (int)params.size(); i++)
    {
        if (S.empty())
            S.push(params[i]);
        else
        {
            if (S.top() == '(' && params[i] == ')')
                S.pop();
            else
                S.push(params[i]);
        }
    }
    
    return S.empty();
}

string solve(string params)
{
    if (params == "")
        return params;
    
    string ft = "";
    
    int L = 0, R = 0, i = 0;
    
    for (i = 0; i < (int)params.length(); i++)
    {
        params[i] == '(' ? L++ : R++;
        ft += params[i];
        
        if (L == R)
            break;
    }
    
    string nxt = params.substr(i + 1);
    
    if (check_correct(ft))
        return ft + solve(nxt);
    
    string another_new = ft.substr(1);
    another_new.pop_back();
    
    for (auto& e : another_new)
    {
        if (e == '(') e = ')';
        else e = '(';
    }
    
    return "(" + solve(nxt) + ")" + another_new;
}

string solution(string p) { // implementation (+ recursion)
    
    return solve(p);
}