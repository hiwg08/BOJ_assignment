#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int H, W;

int Vis_F[201][201]{ 0 };

int Vis_C[201][201]{ 0 };

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, 1, 0, -1 };

char kind[]{ 'W', 'A', 'K', 'J', 'S', 'D' };

int cToin(char c)
{
	return c <= '9' ? (int)(c - 48) : (int)(c - 87);
}

void BFS(int i, int j, vector<vector<int>>& V, int cnt)
{
	Vis_F[i][j] = cnt;

	queue<pii> Q;

	Q.push({ i, j });

	while (!Q.empty())
	{
		pii T = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = T.x + dx[dir];
			int ny = T.y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= H || ny >= 4 * W)
				continue;

			if (Vis_F[nx][ny])
				continue;

			if (V[nx][ny] == 0)
				continue;

			Vis_F[nx][ny] = cnt;

			Q.push({ nx, ny });
		}
	}
}

bool another_BFS(int i, int j, int pre, vector<vector<int>>& V)
{
	bool ret = true;

	Vis_C[i][j] = -2;

	queue<pii> Q;

	Q.push({ i, j });

	while (!Q.empty())
	{
		pii T = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = T.x + dx[dir];
			int ny = T.y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= H || ny >= 4 * W)
			{
				ret = false;
				continue;
			}
			
			if (Vis_C[nx][ny])
				continue;

			if (V[nx][ny] == 1)
			{
				if (Vis_F[nx][ny] != pre)
					ret = false;
				continue;
			}	

			Vis_C[nx][ny] = -2;

			Q.push({ nx, ny });
		}
	}

	return ret;
}

int BFS_2(int i, int j, int pre, vector<vector<int>>& V)
{
	Vis_C[i][j] = -1;

	queue<pii> Q;

	Q.push({ i, j });

	int cnt = 0;

	while (!Q.empty())
	{
		pii T = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = T.x + dx[dir];
			int ny = T.y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= H || ny >= 4 * W)
				continue;

			if (Vis_C[nx][ny])
				continue;

			if (V[nx][ny] == 1)
			{
				Vis_C[nx][ny] = -1;
				Q.push({ nx, ny });
			}

			else
			{
				if (another_BFS(nx, ny, pre, V))
					cnt++;
			}
		}
	}

	return cnt;
}

int main()
{
	fastio;

	for (int T = 1;;T++)
	{
		cin >> H >> W;

		if (H == 0 && W == 0)
			break;

		vector<pii> draw_c;

		vector<vector<int>> V;

		V.resize(H);

		memset(Vis_F, 0, sizeof(Vis_F));
		memset(Vis_C, 0, sizeof(Vis_C));

		for (int i = 0; i < H; i++)
		{
			string S; cin >> S;

			for (auto& e : S)
			{
				int T = cToin(e);

				for (int j = 3; j >= 0; j--)
				{
					if ((T & (1 << j)) != 0)
					{
						T -= (1 << j);
						V[i].push_back(1);
					}
					else
						V[i].push_back(0);
				}
			}
		}

		int Q = 0;

		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < 4 * W; j++)
			{
				if (V[i][j] == 1 && !Vis_F[i][j])
				{
					draw_c.push_back({ i, j });
					BFS(i, j, V, ++Q);
				}
			}
		}

		vector<char> Ans;

		for (int i = 0; i < (int)draw_c.size(); i++)
			Ans.push_back(kind[BFS_2(draw_c[i].x, draw_c[i].y, i + 1, V)]);
		
		sort(Ans.begin(), Ans.end());

		cout << "Case " << T << ": ";

		for (auto e : Ans)
			cout << e;

		cout << '\n';
	}
}