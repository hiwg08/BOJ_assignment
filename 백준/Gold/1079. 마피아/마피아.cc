#include <bits/stdc++.h>

using namespace std;

int N, mafia, total = 0;

int score[21]{ 0 };

int death[21][21]{ 0 };

int vis[21]{ 0 };

void solve(bool morning, int last, int cnt) // 밤을 0, 낮을 1로 해야겠다
{
	if (!morning) // 밤일 때
	{
		for (int i = 0; i < N; i++)
		{
			if (i == mafia)
				continue;
			if (vis[i])
				continue;
			vis[i] = true;
			solve(!morning, i, cnt);
			vis[i] = false;
		}
	}
	else // 낮일 때 게임 종료?
	{
		for (int i = 0; i < N; i++) // 마피아도 포함해서 점수를 낮춰야 한다
		{
			if (vis[i])
				continue;
			if (last != -1)
				score[i] += (death[last][i]);
		}

		int max_score = -1, max_index = -1;

		for (int i = 0; i < N; i++) // 마피아도 포함해서 점수를 낮춰야 한다
		{
			if (vis[i])
				continue;
			if (max_score < score[i])
			{
				max_score = score[i];
				max_index = i;
			}
		}

		// 게임을 계속 진행하기 위해서는 마파아가 안 죽으면 된다.

		if (max_index != -1 && max_index != mafia) // max_index == -1 --> 더 이상 죽일 사람 x / max_index == mafia --> 죽는 사람이 마피아
		{
			vis[max_index] = true;
			solve(!morning, -1, cnt + 1);
			vis[max_index] = false;
		}

		for (int i = 0; i < N; i++)
		{
			if (vis[i])
				continue;
			if (last != -1)
				score[i] -= (death[last][i]);
		}
	}

	total = max(total, cnt);
}

// 그래서 밤일 때와 낮일 때를 따로 구별

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> score[i];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> death[i][j];
	}

	cin >> mafia;
	
	solve(N % 2, -1, !(N % 2));

	cout << total;
}