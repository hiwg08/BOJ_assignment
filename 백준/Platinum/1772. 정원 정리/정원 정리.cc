#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int N, M, total = INT_MAX;

vector<int> Tree[151];

int DP[151][151][151]{ 0 };

int solve(int Idx, int before)
{
	int cnt = 0;

	for (auto e : Tree[Idx])
	{
		if (e == before)
			continue;

		int T1 = solve(e, Idx); // T1이 곧 서브 트리에서의 dp 인덱스가 된다.

		cnt++;

		if (cnt == 1)
		{
			for (int i = 149; i >= 0; i--)
				DP[Idx][cnt][i + 1] = DP[e][T1][i];
		}
		else
		{
			for (int i = 0; i <= 150; i++)
			{
				for (int j = 0; j <= 150; j++)
				{
					if (i + j <= 150)
						DP[Idx][cnt][i + j] = min(DP[Idx][cnt][i + j], DP[e][T1][i] + DP[Idx][cnt - 1][j]); 
				}
			}
		}
	}

	DP[Idx][cnt][0] = 1;

	DP[Idx][cnt][1] = min(DP[Idx][cnt][1], cnt);

	int comp = DP[Idx][cnt][M];

	if (Idx != 1)
		comp++;

	total = min(total, comp);

	return cnt;
}

void input()
{
	cin >> N >> M;

	for (int i = 0, a, b; i < N - 1; i++)
	{
		cin >> a >> b;

		Tree[a].push_back(b);
		Tree[b].push_back(a);
	}

	for (int i = 0; i <= 150; i++)
	{
		for (int j = 0; j <= 150; j++)
		{
			for (int k = 0; k <= 150; k++)
				DP[i][j][k] = 99999;
		}
	}
}

int main()
{
	input();

	solve(1, -1);

	if (total >= 99999)
		total = -1;

	cout << total;
}