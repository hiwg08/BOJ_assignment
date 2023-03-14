#include <bits/stdc++.h>
#define MAX 987654321

using namespace std;

int DP[101]{ 0 };

int N, M;

int six[101]{ 0 }, one[101]{ 0 };

void solve()
{
	for (int i = 0; i <= 100; i++)
		DP[i] = MAX;

	DP[0] = 0;

	for (int i = 0; i < M; i++)
	{
		for (int j = 1; j <= 100; j++)
		{
			if (j % 6 != 0)
			{
				int quo = 6 * ((j / 6) + 1);
				DP[j] = min(DP[j], DP[quo - 6] + six[i]);
			}
			else
				DP[j] = min(DP[j], DP[j - 6] + six[i]);
		}
	}


	for (int i = 0; i < M; i++)
	{
		for (int j = 1; j <= 100; j++)
			DP[j] = min(DP[j], DP[j - 1] + one[i]);
	}

}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
		cin >> six[i] >> one[i];

	solve();

	cout << DP[N] << '\n';
}