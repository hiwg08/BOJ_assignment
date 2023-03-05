#include <bits/stdc++.h>

using namespace std;

vector<int> V;

int sister[10001]{ 0 }, brother[10001]{ 0 };

int sister_cnt, brother_cnt;

int solution(vector<int> topping) { // bruteforcing + implementation
    int answer = 0;
    
    V = topping;
    
    for (int i = (int)V.size() - 1; i >= 0; i--)
    {
        if (brother[V[i]] == 0)
            brother_cnt++;
        brother[V[i]]++;
    }
    
    for (int i = 1; i < (int)V.size(); i++)
    {
        if (sister[V[i - 1]] == 0)
            sister_cnt++;
        sister[V[i - 1]]++;
        
        if (brother[V[i - 1]] == 1)
            brother_cnt--;
        brother[V[i - 1]]--;
        
        if (sister_cnt == brother_cnt)
            answer++;
    }
    
    return answer;
}