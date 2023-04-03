#include <bits/stdc++.h>

using namespace std;

string today, u = "";

vector<string> privacies;

int date[26]{ 0 };

vector<int> solution(string t, vector<string> te, vector<string> pri) {
    vector<int> answer;
    
    today = t;
    privacies = pri;
    
    for (auto& e : today)
    {
        if (e == '.')
            e = ' ';
    }
    
    for (auto e : te)
    {
        stringstream ss(e);
        string tmp;
        
        int j = -1;
        
        while (ss >> tmp)
        {
            if (tmp >= "A" && tmp <= "Z")
                j = (int)(tmp[0] - 65);
            else
                date[j] = stoi(tmp);
        }
    } // 기간 구하기
    
    for (int i = 0; i < (int)privacies.size(); i++)
    {
        for (int j = 0; j < (int)privacies[i].size(); j++)
        {
            if (privacies[i][j] == '.')
                privacies[i][j] = ' ';
        }
    }
    
    string tmp;
    
    stringstream ss(today);
    
    while(ss >> tmp)
        u += tmp;
    today = u;
    
    for (int i = 0; i < (int)privacies.size(); i++)
    {
        int arr[3]{ 0 };
        int Idx = 0;
        char chk = '.';
        stringstream ss(privacies[i]);
        string tmp;
        
        while(ss >> tmp)
        {
            if (Idx == 3)
                chk = tmp[0];
            else
                arr[Idx++] = stoi(tmp); 
        }
        
        int nxt = date[(int)(chk - 65)];
        
        if (arr[2] == 1)
        {
            arr[2] = 28;
            nxt--;
        }
           
        else
            arr[2]--;
        
        if (arr[1] + nxt > 12)
        {
            if ((arr[1] + nxt) % 12 == 0)
            {
                arr[0] += (arr[1] + nxt) / 12 - 1;
                arr[1] = 12;
            }
            else
            {
                arr[0] += (arr[1] + nxt) / 12;
                arr[1] = (arr[1] + nxt) % 12;
            }
           
        }
        else
        {
            arr[1] += nxt;
        }
        
        tmp = "";
        
        for (int k = 0; k < 3; k++)
        {
            if (k >= 1 && (arr[k] >= 1 && arr[k] <= 9))
                tmp += ('0' + to_string(arr[k]));
            else
                tmp += to_string(arr[k]);
        }
           
        if (tmp < today)
            answer.push_back(i + 1);
    }
    
    return answer;
}