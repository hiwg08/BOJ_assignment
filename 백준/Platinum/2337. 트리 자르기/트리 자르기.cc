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
				DP[Idx][cnt][i + 1] = DP[e][T1][i]; // 미리 루트 노드 한 개를 추가해줘야 나중에 구현이 꼬이지 않는다.
		}
		else
		{
			for (int i = 150; i >= 0; i--) // DP e // 서브 트리에서 나오는 가짓수 중 ****반 드 시 하나는 선택해야 하는**** 냅색.... 너무 어려웠다.
			{
				for (int j = 150; j >= 0; j--) // DP Idx
				{
					if (i + j <= 150)
						DP[Idx][cnt][i + j] = min(DP[Idx][cnt][i + j], DP[e][T1][i] + DP[Idx][cnt - 1][j]); // DP[Idx][cnt][i + j]하고 DP[e][T1][i], DP[Idx][cnt - 1][j]는 완전히 다른 배열이다. 따라서 배열의 값이 오염될 염려가 전혀 없다.
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
