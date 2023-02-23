#include <bits/stdc++.h>
#define int long long
#define psi pair<string, int>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int M, S;

int smell[4][4]{ 0 };

pii s_pos;

int f_dx[]{ 0, -1, -1, -1, 0, 1, 1, 1 };
int f_dy[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
int s_dx[]{ -1, 0, 1, 0 };
int s_dy[]{ 0, -1, 0, 1 };

bool Vis[4][4]{ 0 };

deque<int> DQ[4][4], copy_DQ[4][4];

vector<int> V;

vector<psi> SV;

void copy_fish()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (!DQ[i][j].empty())
				copy_DQ[i][j] = DQ[i][j];
		}
	}
}

void move_fish()
{
	deque<int> tmp_DQ[4][4];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			while (!DQ[i][j].empty())
			{
				int dir = DQ[i][j].front();
				DQ[i][j].pop_front();

				int f_limit = 0;

				while (true)
				{
					int nx = i + f_dx[dir], ny = j + f_dy[dir];

					if ((nx < 0 || ny < 0 || nx >= 4 || ny >= 4) || (smell[nx][ny] != 0 || (nx == s_pos.x && ny == s_pos.y)))
					{
						f_limit++;
						dir--;
						if (dir == -1) dir = 7;

						if (f_limit == 8)
						{
							tmp_DQ[i][j].push_back(dir);
							break;
						}
							
						continue;
					}

					tmp_DQ[nx][ny].push_back(dir);
					break;
				}
			} 
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			DQ[i][j] = tmp_DQ[i][j];
	}
}

bool cmp(psi p1, psi p2)
{
	if (p1.y == p2.y)
		return p1.x < p2.x;
	return p1.y > p2.y;
}

void solve(int Cnt, string S)
{
	if (Cnt == 3)
	{
		memset(Vis, false, sizeof(Vis));

		int t_x = s_pos.x, t_y = s_pos.y;
		bool CHK = true;
		int coll = 0;

		for (auto e : V)
		{
			t_x += s_dx[e], t_y += s_dy[e];

			if (t_x < 0 || t_y < 0 || t_x >= 4 || t_y >= 4)
			{
				CHK = false;
				break;
			}

			if ((int)DQ[t_x][t_y].size() != 0 && !Vis[t_x][t_y])
			{
				Vis[t_x][t_y] = true;
				coll += (int)DQ[t_x][t_y].size();
			}

		}
		
		if (CHK)
			SV.push_back({ S, coll });

		return;
	}
	for (int i = 0; i < 4; i++)
	{
		V.push_back(i);
		solve(Cnt + 1, S + to_string(i));
		V.pop_back();
	}
}

void move_shark()
{
	while (!SV.empty())
		SV.pop_back();

	solve(0, "");

	sort(SV.begin(), SV.end(), cmp);

	for (auto e : SV[0].x)
	{
		s_pos.x += s_dx[(int)(e - '0')], s_pos.y += s_dy[(int)(e - '0')];

		if ((int)DQ[s_pos.x][s_pos.y].size() != 0)
		{
			while (!DQ[s_pos.x][s_pos.y].empty())
				DQ[s_pos.x][s_pos.y].pop_back();
			
			smell[s_pos.x][s_pos.y] = 2;
		}
	}
}

void paste_fish()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			while (!copy_DQ[i][j].empty())
			{
				DQ[i][j].push_back(copy_DQ[i][j].front());
				copy_DQ[i][j].pop_front();
			}
		}
	}
}

void delete_smell_at_once()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (smell[i][j] != 0)
				smell[i][j]--;
		}
	}
}

int32_t main()
{
	cin >> M >> S;

	for (int i = 0, a, b, c; i < M; i++)
	{
		cin >> a >> b >> c;

		DQ[a - 1][b - 1].push_back(c - 1);
	}

	cin >> s_pos.x >> s_pos.y;
	s_pos.x--, s_pos.y--;

	for (int i = 0; i < S; i++)
	{
		copy_fish();

		move_fish();

		delete_smell_at_once(); 

		move_shark();

		paste_fish();
	}

	int total = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			total += (int)DQ[i][j].size();
	}

	cout << total << '\n';
}
