#include <bits/stdc++.h>

using namespace std;

vector<int> V;

string solution(string s) { // string + parsing
    string tmp;
    
    istringstream ss(s);
    
    while(ss >> tmp)
        V.push_back(stoi(tmp));
    
    sort(V.begin(), V.end());
    
    return to_string(V[0]) + " " + to_string(V[(int)V.size() - 1]);
}