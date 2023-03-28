#include <bits/stdc++.h>

using namespace std;

bool Vis[21]{ 0 };

double A, B;

double DP[20][20][20]{ 0 };

void eratos()
{
	Vis[0] = true, Vis[1] = true;

	for (int i = 2; i <= (int)sqrt(20); i++)
	{
		if (Vis[i])
			continue;
		for (int j = i; j <= 20; j += i)
		{
			if (j == i)
				continue;
			Vis[j] = true;
		}
	}
}


void init()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			for (int k = 0; k < 20; k++)
				DP[i][j][k] = -1;
		}
	}
}

double solve(int Idx, int a, int b)
{
	if (Idx >= 18)
	{
		if (!Vis[a] || !Vis[b])
			return 1;
		return 0;
	}

	double& ret = DP[Idx][a][b];

	if (ret != -1)
		return ret;

	ret = 0;

	ret += solve(Idx + 1, a + 1, b) * A * (1 - B);
	ret += solve(Idx + 1, a, b) * (1 - A) * (1 - B);
	ret += solve(Idx + 1, a, b + 1) * (1 - A) * B;
	ret += solve(Idx + 1, a + 1, b + 1) * A * B;

	return ret;
}


int main()
{
	cin >> A >> B;

	A /= (double)100, B /= (double)100;

	eratos();

	init();

	cout.precision(6);

	cout << fixed << solve(0, 0, 0);
}