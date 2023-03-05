#include <bits/stdc++.h>

using namespace std;

vector<int> A, B;

int ans_a = -1, ans_b = -1;

int get_gcd(int a, int b)
{
    if (b == 0)
        return a;
    return get_gcd(b, a % b);
}

bool chk(vector<int> params, int standard)
{
    for (auto e : params)
    {
        if (e % standard == 0)
            return false;
    }
    
    return true;
}

int solution(vector<int> arrayA, vector<int> arrayB) { // 어차피 최대공약수의 '약수'들은 죄다 나눠 떨어지기 때문에 맘 편하게 최대 공약수를 구하면 된다.
    int answer = 0;
    
    A = arrayA, B = arrayB;
    
    int gcd_a = A[0];
    
    for (int i = 1; i < (int)A.size(); i++)
        gcd_a = get_gcd(gcd_a, A[i]);
    
    int gcd_b = B[0];
    
    for (int i = 1; i < (int)B.size(); i++)
        gcd_b = get_gcd(gcd_b, B[i]);
    
    if (chk(A, gcd_b))
        ans_b = gcd_b;
    
    if (chk(B, gcd_a))
        ans_a = gcd_a;
    
    if (ans_b == -1 && ans_a == -1)
        return 0;
    
    return max(ans_a, ans_b);
}