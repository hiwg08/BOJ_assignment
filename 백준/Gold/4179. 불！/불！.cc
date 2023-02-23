#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int R, C;

char Map[1001][1001]{ 0 };

bool Vis[1001][1001]{ 0 };

int Fire_Map[1001][1001]{ 0 };

int J_X, J_Y;

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, 1, 0, -1 };

vector<pair<int, int>> Fire_Pos;

void Fire_BFS()
{
	memset(Fire_Map, -1, sizeof(Fire_Map));

	for (int i = 0; i < Fire_Pos.size(); i++)
	{
		memset(Vis, false, sizeof(Vis));
		queue<pair<pair<int, int>, int>> Q;

		Q.push({ { Fire_Pos[i].first, Fire_Pos[i].second }, 0 });

		Vis[Fire_Pos[i].first][Fire_Pos[i].second] = true;
		Fire_Map[Fire_Pos[i].first][Fire_Pos[i].second] = 0;

		while (!Q.empty())
		{
			pair<pair<int, int>, int> st1 = Q.front();
			Q.pop();

			for (int dir = 0; dir < 4; dir++)
			{
				int nx = st1.first.first + dx[dir];
				int ny = st1.first.second + dy[dir];

				if (nx < 0 || ny < 0 || nx >= R || ny >= C)
					continue;
				if (Map[nx][ny] == '#')
					continue;
				if (Vis[nx][ny])
					continue;
				if (Fire_Map[nx][ny] != -1 && Fire_Map[nx][ny] < st1.second + 1)
					continue;

				Vis[nx][ny] = true;
				Fire_Map[nx][ny] = st1.second + 1;
				Q.push({ {nx, ny}, st1.second + 1 });
			}
		}
	}
}

int Jihun_BFS()
{
	memset(Vis, false, sizeof(Vis));
	queue<pair<pair<int, int>, int>> Q;

	Q.push({ { J_X, J_Y }, 0 });

	Vis[J_X][J_X] = true;

	while (!Q.empty())
	{
		pair<pair<int, int>, int> st1 = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = st1.first.first + dx[dir];
			int ny = st1.first.second + dy[dir];

			if (nx < 0 || ny < 0 || nx >= R || ny >= C)
				return st1.second + 1;
			if (Map[nx][ny] == '#')
				continue;
			if (Vis[nx][ny])
				continue;
			if (Fire_Map[nx][ny] != -1 && Fire_Map[nx][ny] <= st1.second + 1)
				continue;

			Vis[nx][ny] = true;
			Q.push({ {nx, ny}, st1.second + 1 });
		}
	}

	return -1;
}

int main()
{
	fastio;

	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		string S; cin >> S;
		for (int j = 0; j < C; j++)
		{
			Map[i][j] = S[j];
			if (Map[i][j] == 'J')
			{
				J_X = i;
				J_Y = j;
			}
			if (Map[i][j] == 'F')
				Fire_Pos.push_back({ i, j });
		}
	}

	Fire_BFS();

	int Ans = Jihun_BFS();

	if (Ans == -1)
		cout << "IMPOSSIBLE" << '\n';
	else
		cout << Ans << '\n';
}