#include <bits/stdc++.h>

using namespace std;

int N, total = 0;

int arr[60][20]{ 0 };

int order[20]{ 0 };

int Vis[20]{ 0 };

int match()
{
	int cnt = 0;

	int k = -1;

	for (int i = 1; i <= N; i++)
	{
		int out_count = 0; // 이닝이 시작할 때 아웃 카운트는 초기화

		deque<int> DQ;

		if (k == -1)
			k = 1;
		else
		{
			if (k == 9)
				k = 1;
			else
				k++;
		}

		for (int j = k; j <= 9; j++)
		{
			int player = order[j];

			if (arr[i][player] == 0)
				out_count++;
			else
			{
				for (int k = (int)DQ.size() - 1; k >= 0; k--)
				{
					DQ[k] += arr[i][player];

					if (DQ[k] >= 4)
						cnt++;
				}

				if (arr[i][player] == 4)
					cnt++;
				else
					DQ.push_front(arr[i][player]);

				while (!DQ.empty() && DQ.back() >= 4)
					DQ.pop_back();
			}

			if (out_count == 3)
			{
				k = j;
				break;
			}

			if (j == 9)
				j = 0;
		}
	}
	
	return cnt;
}

void solve(int Idx)
{
	if (Idx == 10)
	{
		total = max(total, match());
		return;
	}

	if (Idx == 4) // 4번 타석은 이미 1번 타자 고정이다.
	{
		solve(Idx + 1);
		return;
	}

	for (int i = 2; i <= 9; i++)
	{
		if (Vis[i])
			continue;
		Vis[i] = true;
		order[Idx] = i;
		solve(Idx + 1);
		order[Idx] = 0;
		Vis[i] = false;
	}
}

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= 9; j++)
			cin >> arr[i][j];
	}

	order[4] = 1; // 4번은 1번 타자가

	solve(1); // 1(Idx)번 order부터 9번 order까지 브루트포스로 정하기

	cout << total;
}