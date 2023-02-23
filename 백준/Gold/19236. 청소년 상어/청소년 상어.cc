#include <bits/stdc++.h>
#define pii pair<int, int>
#define MOD 8
#define f first
#define s second
using namespace std;

int dx[8]{ -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8]{ 0, -1, -1, -1, 0, 1, 1, 1 };

vector<vector<pii>> B;

int MAX = INT_MIN, ini = 0;

void Fish_Move(vector<vector<pii>>& B)
{
	for (int num = 1; num <= 16; num++)
	{
		for (int i = 0; i < 4; i++)
		{
			bool CHK = false;
			for (int j = 0; j < 4; j++)
			{
				if (B[i][j].f == num)
				{
					CHK = true;
					for (int loop = 0; loop < 8; loop++)
					{
						int dir = (B[i][j].s + loop) % MOD;
						int nx = i + dx[dir], ny = j + dy[dir];
						if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4)
							continue;
						if (B[nx][ny].f == -1)
							continue;
						pii tmp = B[nx][ny];
						B[nx][ny] = { B[i][j].f, dir };
						B[i][j] = tmp;
						break;
					}
					break;
				}
			}
			if (CHK) break;
		}
	}
}

void solve(int Cnt, vector<vector<pii>> B) // 물고기 이동 후 상어 이동 순으로 구현하자.
{
	Fish_Move(B);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (B[i][j].f == -1)
			{
				int loop = 0;
				bool CHK = false;
				while (true)
				{
					loop++;
					int nx = i + (dx[B[i][j].s] * loop), ny = j + (dy[B[i][j].s] * loop);

					if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4)
						break;
					if (B[nx][ny].f >= 1)
					{
						CHK = true;
						pii Shark_tmp = B[i][j], Fish_tmp = B[nx][ny];
						B[nx][ny] = { -1, Fish_tmp.s };
						B[i][j] = { 0, 0 };
						solve(Cnt + Fish_tmp.f, B);
						B[nx][ny] = Fish_tmp;
						B[i][j] = Shark_tmp;
					}
				}
				if (!CHK)
					MAX = max(MAX, Cnt);
			}
		}
	}
}

void Input()
{
	B.resize(4);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int a, b; cin >> a >> b;
			B[i].push_back({ a, b - 1 });
			if (i == 0 && j == 0)
			{
				ini = a;
				B[i][j].f = -1;
			}
		}
	}
}

int main()
{
	Input();

	solve(0, B);

	cout << MAX + ini << '\n';
}