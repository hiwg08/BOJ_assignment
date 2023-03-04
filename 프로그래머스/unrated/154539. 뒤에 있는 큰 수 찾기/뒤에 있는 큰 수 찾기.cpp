#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

stack<pii> S;

vector<int> V;

int N;

int Ans[1000001]{ 0 };

vector<int> solution(vector<int> numbers) { // 스택
    vector<int> answer;
    
    V = numbers;
    
    N = (int)numbers.size();
    
    memset(Ans, -1, sizeof(Ans));
    
    for (int i = 0; i < (int)V.size(); i++)
    {
        while (!S.empty() && S.top().x < V[i])
        {
            Ans[S.top().y] = V[i];
            S.pop();
        }
        S.push({V[i], i});
    }
    
    for (int i = 0; i < N; i++)
        answer.push_back(Ans[i]);
    
    return answer;
}