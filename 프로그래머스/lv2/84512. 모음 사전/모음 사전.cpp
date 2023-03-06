#include <bits/stdc++.h>

using namespace std;

char Arr[]{'A', 'E', 'I', 'O', 'U'};

int cnt, total;

string standard;

void solve(int Idx, string S)
{
    if (Idx >= 1)
    {
        cnt++;
        
        if (S == standard)
            total = cnt;
    }
        
    
    if (Idx >= 5)
        return;
    
    for (int i = 0; i < 5; i++)
        solve(Idx + 1, S + Arr[i]);
}

int solution(string word) {
    
    standard = word;
    
    solve(0, "");
    
    return total;
}