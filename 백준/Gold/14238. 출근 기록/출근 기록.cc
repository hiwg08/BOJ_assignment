#include <bits/stdc++.h>

using namespace std;

string S;

int A, B, C;

int DP[50][50][50][2][3]{ 0 };

string Ans[51];

int solve(int A_C, int B_C, int C_C, int I_B, int I_C)
{
	if (A_C == 0 && B_C == 0 && C_C == 0)
		return 1;

	int& ret = DP[A_C][B_C][C_C][I_B][I_C];

	if (ret != -1)
		return ret;

	int A_able = 0, B_able = 0, C_able = 0;

	if (A_C > 0 && solve(A_C - 1, B_C, C_C, (I_B + 1) == 2 ? I_B : I_B + 1, (I_C + 1) == 3 ? I_C : I_C + 1))
	{
		Ans[(int)S.size() - A_C - B_C - C_C] = "A";
		return ret = 1;
	}
		
	if (B_C > 0 && I_B + 1 == 2 && solve(A_C, B_C - 1, C_C, 0, (I_C + 1) == 3 ? I_C : I_C + 1)) // 1, 2
	{
		Ans[(int)S.size() - A_C - B_C - C_C] = "B";
		return ret = 1;
	}

	if (C_C > 0 && I_C + 1 == 3 && solve(A_C, B_C, C_C - 1, (I_B + 1) == 2 ? I_B : I_B + 1, 0))
	{
		Ans[(int)S.size() - A_C - B_C - C_C] = "C";
		return ret = 1;
	}

	return ret = 0;
}

int main()
{
	cin >> S;

	for (auto e : S)
	{
		if (e == 'A') A++;
		if (e == 'B') B++;
		if (e == 'C') C++;
	}
	
	memset(DP, -1, sizeof(DP));

	if (solve(A, B, C, 1, 2))
	{
		for (auto e : Ans)
			cout << e;
		cout << '\n';
	}
	else
		cout << -1 << '\n';
}