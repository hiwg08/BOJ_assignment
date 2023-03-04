#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

vector<pii> V;

int cnt;

// 실수한 부분! --> 16:58분에서 10분 증가 시 17:08이 되야 한다는 점을 잊지 말자.

priority_queue<int, vector<int>, greater<int>> PQ;

int solution(vector<vector<string>> book_time) { // 그리디 + 우선순위 큐
    
    for (int i = 0; i < (int)book_time.size(); i++)
    {
        string start = book_time[i][0], end = book_time[i][1];
        
        string conv_start = start.substr(0, 2) + start.substr(3, 2);
        
        string conv_end = end.substr(0, 2) + end.substr(3, 2);
        
        int c_end = stoi(conv_end);
        
        
        if (end.substr(3, 2) >= "50")
            c_end += 50;
        else
            c_end += 10;
        
        // 실수한 부분! --> 16:58분에서 10분 증가 시 17:08이 되야 한다는 점을 잊지 말자.
        
        V.push_back({stoi(conv_start), c_end});
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