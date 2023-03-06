#include <bits/stdc++.h>

using namespace std;

int N;

set<string> S;

vector<int> solution(int n, vector<string> words) { // tree_map
    
    N = n;
    
    for (int i = 0; i < (int)words.size(); i++)
    {
        int num = i % N, order = i / N;
        
        if (S.find(words[i]) != S.end())
            return {num + 1, order + 1};
        
        else if (i != 0 && words[i - 1][(int)words[i - 1].size() - 1] != words[i][0])
            return {num + 1, order + 1};
            
        S.insert(words[i]);
    }
    
    return {0, 0};
}