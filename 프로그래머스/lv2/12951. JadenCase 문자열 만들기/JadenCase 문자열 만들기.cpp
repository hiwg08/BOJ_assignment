#include <bits/stdc++.h>

using namespace std;

string solution(string s) { // string, parsing (**** 실수) 공백 문자가 연속으로 나올 수 있다는 점을 지나침 
    string answer = "";
    
    string tmp = "";
    
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == ' ')
        {
            if (!tmp.empty())
            {
                transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
                if (tmp[0] >= 'a' && tmp[0] <= 'z') tmp[0] -= 32;
                answer += tmp;
            }
            tmp = "";
            answer += ' ';
        }
        else
            tmp += s[i];
    }
    
      if (!tmp.empty())
      {
          transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
          if (tmp[0] >= 'a' && tmp[0] <= 'z') tmp[0] -= 32;
             answer += tmp;
      } 
    
    return answer;
}