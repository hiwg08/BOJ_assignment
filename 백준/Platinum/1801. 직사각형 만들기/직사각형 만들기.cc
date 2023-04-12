#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int N;

int Arr[20]{ 0 };

bool DP[20][200]{ 0 };

vector<pii> mark{ {0, 1}, {1, 2}, {1, 3}, {2, 4} }; // 36, 14, 11, 7

int vis[20]{ 0 };

int yy[20]{ 0 };

int total = -1;

int calc = 0;

bool chk = false;

void solve()
{
	DP[0][0] = 1;

	for (int i = 1; i <= N; i++)
	{
		for (int j = calc; j >= 0; j--)
		{
			DP[i][j + Arr[i]] |= DP[i - 1][j];
			DP[i][j] |= DP[i - 1][j];
		}
	}
}

void reconstruct(int Idx, int sum, int stage)
{
	if (stage == 4)
	{
		total = max(total, yy[2] * yy[3]);
		chk = true;
		return;
	}

	while (Idx >= 1 && vis[Idx] != mark[stage].x)
		Idx--;

	if (Idx == 0)
	{
		if (sum == 0)
			reconstruct(N, yy[stage + 1], stage + 1);
		return;
	}

	if (DP[Idx][sum] && DP[Idx - 1][sum])
		reconstruct(Idx - 1, sum, stage);

	if (chk)
		return;

	if (DP[Idx][sum - Arr[Idx]] && DP[Idx - 1][sum - Arr[Idx]])
	{
		vis[Idx] = mark[stage].y;
		reconstruct(Idx - 1, sum - Arr[Idx], stage);
		vis[Idx] = mark[stage].x;
	}
}

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> Arr[i];
		calc += Arr[i];
	}

	solve();

	for (int i = 1; i <= 40; i++)
	{
		for (int j = i; j <= 80 - i; j++)
		{
			int L = i, R = j;

			int L_2 = 2 * L, R_2 = 2 * R;

			if (total > L * R)
				continue;

			if (L_2 + R_2 > calc)
				continue;

			if (!DP[N][L_2 + R_2] || !DP[N][L_2] || !DP[N][R_2] || !DP[N][L] || !DP[N][R])
				continue;

			chk = false;

			memset(vis, 0, sizeof(vis));

			yy[0] = L_2 + R_2;
			yy[1] = L_2;
			yy[2] = R;
			yy[3] = L;

			reconstruct(N, yy[0], 0);
		}
	}

	cout << total;
}