#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int c_x, c_y;

double pre_sum[10001]{ 0 };

vector<double> solution(int k, vector<vector<int>> ranges) { // prefix_sum + math
    vector<double> answer;
    
    c_x = 0, c_y = k;
    
    int Idx = 1;
    
    while(true)
    {
        int nx = c_x + 1, ny = c_y % 2 != 0 ? (c_y * 3) + 1 : c_y / 2;
        
        double calc_area = (c_y + ny) / (double)2;
        
        pre_sum[Idx] = pre_sum[Idx - 1] + calc_area; 
        
        Idx++;
        
        c_y = ny, c_x = nx;
        
        if (ny == 1)
            break;
    }
    
    for (int i = 0; i < (int)ranges.size(); i++)
    {
        int start = ranges[i][0], end = Idx - 1 + ranges[i][1];
        
        if (start > end) // ****실수.... 유효하지 않은 구간, 즉 start가 end보다 클 때는 -1이다.
            answer.push_back((double)-1);
        
        else
            answer.push_back(pre_sum[end] - pre_sum[start]);
    }
    
    return answer;
}