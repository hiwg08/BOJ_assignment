#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

map<string, int> M;

map<string, int> standard;

bool check()
{
    for (auto e : standard)
    {
        if (M.find(e.x) == M.end())
            return false;
        
        if (e.y != M[e.x])
            return false;
    }
    
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) { // 1. tree_map 2. hash_map
    int answer = 0;
    
    for (int i = 0; i < (int)want.size(); i++)
        standard[want[i]] = number[i];
    
    for (int i = 0; i < (int)discount.size(); i++)
    {
        M[discount[i]]++;
        
        if (i >= 10)
        {
            if (M[discount[i - 10]] == 1)
                M.erase(discount[i - 10]);
            else
                 M[discount[i - 10]]--;
        } // ***** 인덱스 조심하자!
        
        if (check())
            answer++;
    }
    
    return answer;
}