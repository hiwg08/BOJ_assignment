#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    while(true)
    {
        int p = section.back(), interval = p - m + 1;
        
        while(!section.empty() && interval <= section.back())
            section.pop_back();
        
        answer++;
        
        if (section.empty())
            break;
    }
    
    return answer;
}