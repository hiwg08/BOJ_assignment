#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

ll N;

vector<int> solution(int n, ll left, ll right) { // math + implementation
    vector<int> answer;
    
    N = (ll)n;
    
    for (ll i = left; i <= right; i++)
    {
        ll quo = i / N, remain = i % N;
        
        remain <= quo ? answer.pb((int)quo + 1) : answer.pb((int)remain + 1);
    }
    
    return answer;
}