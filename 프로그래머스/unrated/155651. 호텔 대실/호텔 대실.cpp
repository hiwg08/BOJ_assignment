#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

vector<pii> V;

int cnt;

priority_queue<int, vector<int>, greater<int>> PQ;

int solution(vector<vector<string>> book_time) {
    
    for (int i = 0; i < (int)book_time.size(); i++)
    {
        string start = book_time[i][0], end = book_time[i][1];
        
        string conv_start = start.substr(0, 2) + start.substr(3, 2);
        
        string conv_end = end.substr(0, 2) + end.substr(3, 2);
        
        int chk_end = stoi(conv_end);
        
        if (end.substr(3, 2) >= "50")
            chk_end += 50;
        else
            chk_end += 10;
        
        V.push_back({stoi(conv_start), chk_end});
    }
    
    // 959
    // 1559 -> 1609 1659 - 50
    
    sort(V.begin(), V.end());
    
    for (auto e : V)
    {
        if (!PQ.empty() && e.x >= PQ.top())
            PQ.pop();
        else
            cnt++;
        PQ.push(e.y);
    }
    
    return cnt;
}