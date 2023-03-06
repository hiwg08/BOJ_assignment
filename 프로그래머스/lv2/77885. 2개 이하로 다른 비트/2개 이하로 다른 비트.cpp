#include <bits/stdc++.h>
#define ll long long
#define o (ll)1

using namespace std;

vector<ll> solution(vector<ll> numbers) { // bitmask + greedy
    vector<ll> answer;
    
    for (ll i = 0; i < (ll)numbers.size(); i++)
    {
        ll standard = numbers[i];
        
        ll j = 0;
        
        while(standard & (o << j))
            j++;
        
        standard += (o << j);
        
        if (j - 1 >= 0)
            standard -= (o << (j - 1));
        
        answer.push_back(standard);
    }
    
    return answer;
}

// 1 -> 0, 0 -> 1

// 1을 xor 시키면 비트 반전이다.