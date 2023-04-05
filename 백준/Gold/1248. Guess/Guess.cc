#include <bits/stdc++.h>

using namespace std;

int N;

char S[101];

char Map[11][11]{ 0 };

vector<int> V;

bool switch_L_R(char giho, int& L, int& R)
{
	if (giho == '+')
	{
		if (R <= 0)
			return false;
		if (L <= 0)
			L = 1;
	}
	if (giho == '-')
	{
		if (L >= 0)
			return false;
		if (R >= 0)
			R = -1;
	}
	if (giho == '0')
	{
		if ((L > 0 && R > 0) || (L < 0 && R < 0))
			return false;
		L = 0, R = 0;
	}

	if (L < -10) L = -10;
	if (R > 10) R = 10;

	return true;
}

void solve(int Idx) // 오른쪽으로 보면서 탐색
{
	if (Idx == N)
	{
		for (auto e : V)
			printf("%d ", e);
		exit(0);
	}

	int L = 0, R = 0;

	if (Map[Idx][Idx] == '+')
		L = 1, R = 10;
	if (Map[Idx][Idx] == '-')
		L = -10, R = -1;

	int Sum = 0;

	for (int i = Idx - 1; i >= 0; i--)
	{
		Sum += V[i];
		L += V[i], R += V[i];
		if (!switch_L_R(Map[i][Idx], L, R))
			return;
	}

	for (int i = L - Sum; i <= R - Sum; i++)
	{
		V.push_back(i);
		solve(Idx + 1);
		V.pop_back();
	}
}

int main()
{
	scanf("%d", &N);

	scanf("%s", S);

	int Idx = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
			Map[i][j] = S[Idx++];
	}

	solve(0);
}