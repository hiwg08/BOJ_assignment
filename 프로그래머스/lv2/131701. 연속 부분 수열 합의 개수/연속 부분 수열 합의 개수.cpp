#include <string>
#include <vector>

using namespace std;

bool Vis[1000001]{ 0 };

int pre_sum[2003]{ 0 };

int cnt;

vector<int> V;

int solution(vector<int> elements) { // 1. prefix_sum 2. two pointer
    
    V = elements;
    
    for (int i = 0; i < (int)elements.size(); i++)
        V.push_back(elements[i]);
    
    for (int i = 0; i < (int)V.size(); i++)
        pre_sum[i] = pre_sum[i - 1] + V[i];
    
    for (int i = 1; i <= (int)elements.size(); i++)
    { // i가 interval
        int start = 1, end = i;
        
        for (int j = 0; j < (int)elements.size(); j++)
        {
            int pre = pre_sum[end] - pre_sum[start - 1];
            
            if (!Vis[pre])
            {
                Vis[pre] = true;
                cnt++;
            }
            start++, end++;
        }
    }
    
    // 7 9 1 1 4 7 9 1 1 4
    
    return cnt;
}