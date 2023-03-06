#include <bits/stdc++.h>

using namespace std;

string S;

map<string, int> M;

int Idx = 26;

void Init()
{
    for (int i = 1; i <= 26; i++)
    {
        string cmp = "";
        cmp += i - 1 + 'A';
        M[cmp] = i;
    }
}

vector<int> solution(string msg) { // bruteforcing + tree_map
    vector<int> answer;
    
    Init();
    
    string tmp = "";
    
    for (int i = 0; i < (int)msg.size(); i++)
    {
        tmp += msg[i];
        
        if (M.find(tmp) == M.end())
        {
            M[tmp] = ++Idx;
            tmp.pop_back();
            answer.push_back(M[tmp]);
            tmp = ""; tmp += msg[i];
        }
    }
    
    if (M.find(tmp) == M.end())
        tmp.pop_back();
    
    answer.push_back(M[tmp]);
    
    return answer;
}