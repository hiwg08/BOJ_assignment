#include <bits/stdc++.h>

using namespace std;

int N, K, night_cnt;

int Arr[17][17]{ 0 };

bool Vis[17]{ 0 };

vector<int> life;

void solve(int Idx, int mafia, vector<int> life, bool chk, int last)
{
	if (!chk) // 밤일 때 (0)
	{
		for (int i = 0; i < N; i++)
		{
			if (Vis[i])
				continue;

			Vis[i] = true;
			solve(Idx, mafia, life, !chk, i);
			Vis[i] = false;
		}
	}
	else // 낮일 때 (1)
	{
		int nxt_Idx = -1, nxt_value = INT_MIN;

		if (last == -1)
		{
			for (int i = 0; i < N; i++)
			{
				if (i == mafia)
				{
					if (nxt_value < life[i])
					{
						nxt_value = life[i];
						nxt_Idx = i;
					}
				}
				if (Vis[i])
					continue;

				if (nxt_value < life[i])
				{
					nxt_value = life[i];
					nxt_Idx = i;
				}
			}
		}
		else
		{
			for (int i = 0; i < N; i++)
			{
				if (i == mafia)
				{
					life[i] += Arr[last][i];

					if (nxt_value < life[i])
					{
						nxt_value = life[i];
						nxt_Idx = i;
					}
				}
				if (Vis[i])
					continue;

				life[i] += Arr[last][i];

				if (nxt_value < life[i])
				{
					nxt_value = life[i];
					nxt_Idx = i;
				}
			}

		}

		if (nxt_Idx != -1 && nxt_Idx != mafia)
		{
			Vis[nxt_Idx] = true;
			solve(Idx + 1, mafia, life, !chk, -1);
			Vis[nxt_Idx] = false;
		}
	}

	night_cnt = max(night_cnt, Idx);
}

int main()
{
	cin >> N; life.resize(N);

	for (auto& iv : life)
		cin >> iv;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> Arr[i][j];
	}

	cin >> K;

	Vis[K] = true;
	solve(!(N % 2), K, life, N % 2, -1);

	cout << night_cnt << '\n';
}