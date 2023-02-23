#include <bits/stdc++.h>

using namespace std;

int T, N;

int DP[101][51][2]{ 0 };

int Trace[101][51][2]{ 0 };

int Arr[]{ 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

int solve(int Cnt, int Idx, int Chk)
{
	if (Cnt < 0)
		return 0;

	if (Idx == 0)
	{
		if (Cnt == 0)
			return 1;
		return 0;
	}

    int& ret = DP[Cnt][Idx][Chk];

	if (ret != -1)
		return ret;

	for (int i = 0; i <= 9; i++)
	{
		if (i == 0 && !Chk)
			continue;

		int Q = solve(Cnt - Arr[i], Idx - 1, true);

		if (Q == 1)
		{
			Trace[Cnt][Idx][Chk] = i;
			return ret = 1;
		}
	}

	return ret = 0;
}

void Init()
{
	for (int j = 1; j <= 100; j++)
	{
		for (int i = 1; i < 51; i++)
			solve(j, i, false);
	}
}

void print(int N, int Idx, int Chk)
{
	while (N != 0)
	{
		cout << Trace[N][Idx][Chk];
		N -= Arr[Trace[N][Idx][Chk]];
		if (Chk == false) Chk = true;
		Idx--;
	}
	cout << " ";
}

int main()
{
	cin >> T;

	memset(DP, -1, sizeof(DP));

	Init();

	while (T--)
	{
		cin >> N;

		for (int i = 1; i < 50; i++)
		{
			if (DP[N][i][0] == 1)
			{
				print(N, i, 0);
				break;
			}
		}	

		if (N % 2 != 0)
		{
			cout << 7;
			N -= 3;
		}
		while (N != 0)
		{
			cout << 1;
			N -= 2;
		}

		cout << '\n';
	}
}