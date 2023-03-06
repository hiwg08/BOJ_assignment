#include <bits/stdc++.h>

using namespace std;

string standard;

bool chk(string T1)
{
    stack<char> S;
    
    for (auto e : T1)
    {
        if (!S.empty())
        {
            char c = S.top();
            
            if (c == '[' && e == ']')
                S.pop();
            else if (c == '{' && e == '}')
                S.pop();
            else if (c == '(' && e == ')')
                S.pop();
            else
                S.push(e);
        }
        else
            S.push(e);
    }
    
    return S.empty();
}

int solution(string s) { // bruteforcing + stack
    int answer = 0;
    
    standard = s + s;
    
    for (int i = 0; i < (int)s.size(); i++)
    {
        string T1 = standard.substr(i, (int)s.size());
        
        if (chk(T1))
            answer++;
    }
    
    return answer;
}