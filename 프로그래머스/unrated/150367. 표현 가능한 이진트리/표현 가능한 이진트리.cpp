#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool check(ll L, ll R, string S, bool flag)
{
    if (L == R)
    {
        if (S[L] == '1')
            return flag ? false : true;
        return true;
    }
    
    ll mid = (L + R) >> 1;
    
    if (S[mid] == '1')
    {
        if (flag) // flag가 켜져 있으면 1이 나오면 안 된다.
            return false;
        return check(L, mid - 1, S, false) && check(mid + 1, R, S, false);
    }
    else
        return check(L, mid - 1, S, true) && check(mid + 1, R, S, true);
    
}

string conv(ll params)
{
    string ans = "";
    
    while(params > 0)
    {
        if (params % 2 == 0)
            ans += '0';
        else
            ans += '1';
        
        params /= 2;
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
}

vector<ll> coll;

void init()
{
    for (int i = 1; i <= 63; i++)
        coll.push_back((ll)pow(2, i) - 1);
}

vector<int> solution(vector<ll> numbers) {
    vector<int> answer;
    
    init();
    
    for (ll i = 0; i < (ll)numbers.size(); i++)
    {
        string a = conv(numbers[i]);
        
        ll Idx = (ll)(lower_bound(coll.begin(), coll.end(), (ll)a.size()) - coll.begin());
        ll interval = coll[Idx] - (ll)a.size();
        
        string qq = "";
        
        while(interval--)
            qq += '0';
        
        a = qq + a;
        
        check(0, (ll)a.size() - 1, a, false) ? answer.push_back(1) : answer.push_back(0);
    }
    
    return answer;
}