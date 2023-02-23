#include <bits/stdc++.h>

using namespace std;

int N;

bool Vis[4000001]{ 0 }; // false가 소수, true가 소수 아님

vector<int> V;

void Init()
{
	for (int i = 2; i <= (int)sqrt(N); i++)
	{
		if (Vis[i])
			continue;

		for (int j = i; j <= N; j += i)
		{
			if (j != i)
				Vis[j] = true;
		}
	}

	for (int i = 2; i <= N; i++)
	{
		if (!Vis[i])
			V.push_back(i);
	}
}

int solve()
{
	int M = (int)V.size(), Ans = 0;

	V.push_back(0);

	int lo = 0, hi = 0, Sum = V[lo];

	while (hi < M)
	{
		if (Sum <= N)
		{
			if (Sum == N)
				Ans++;
			Sum += V[++hi];
		}

		else
			Sum -= V[lo++];

		if (lo > hi)
		{
			hi = lo;
			Sum = V[hi];
		}
	}

	return Ans;
}

int main()
{
	cin >> N;

	Init();

	cout << solve() << '\n';
}