#include <bits/stdc++.h>

using namespace std;

deque<int> first;

stack<int> second;

int Idx = 0;

int solution(vector<int> order) { // data structure(deque + stack)
    int answer = 0;
    
    for (int i = 0; i < (int)order.size(); i++)
        first.push_back(i + 1);
    
    while(Idx < (int)order.size())
    {
        if (!second.empty() && second.top() == order[Idx])
        {
            second.pop();  
            Idx++;
            continue;
        }
        
        while(!first.empty() && first.front() != order[Idx])
        {
            second.push(first.front());
            first.pop_front();
        }
        
        if (first.empty())
            break;
        else
        {
            first.pop_front();
            Idx++;
        }
    }
    
    return Idx;
}

// 4 3 1 2 5

// 1 2 3 4 5