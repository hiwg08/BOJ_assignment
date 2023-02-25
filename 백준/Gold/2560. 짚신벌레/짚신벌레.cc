#include <bits/stdc++.h>
#define MOD 1000
#define MAX 30000

using namespace std;

int a, b, d, N;

int DP[1050001][2]{ 0 }; // 0 -> 그냥 총 개체 수 1 -> 현재 날에 만들어진 새로운 개체 수

int S[1050001]{ 0 };

void sub_mod(int& ret, int params)
{
	ret = (ret - params + MOD) % MOD;
}

void add_mod(int& ret, int params)
{
	ret += params;
	ret %= MOD;
}

int main()
{
	cin >> a >> b >> d >> N;

	DP[MAX][0] = 1, DP[MAX][1] = 1; S[MAX] = 1;

	for (int i = MAX + 1; i <= N + MAX; i++)
	{
		int A = S[i - a]; 
		sub_mod(A, S[i - b]);

		DP[i][1] = A;

		A = DP[i - 1][0];
		add_mod(A, DP[i][1]);

		DP[i][0] = A;

		if (i >= d)
			sub_mod(DP[i][0], DP[i - d][1]);

		A = S[i - 1]; 
		add_mod(A, DP[i][1]);

		S[i] = A;
	}

	cout << DP[N + MAX][0] << '\n';
}