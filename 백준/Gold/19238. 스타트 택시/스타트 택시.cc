#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pii pair<int, int>
#define f first
#define s second

using namespace std;

int N, M, Oil, taxi_x, taxi_y, Cnt;

int Board[21][21]{ 0 };

bool Vis[21][21]{ 0 };

pair<int, int> Dest[401];

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, 1, 0, -1 };

bool cmp(pair<pii, int> a, pair<pii, int> b)
{
	if (a.s == b.s)
	{
		if (a.f.f == b.f.f)
			return a.f.s < b.f.s;
		return a.f.f < b.f.f;
	}
	return a.s < b.s;
}

bool solve()
{
	while (true)
	{
		if (Cnt == 0)
			break;

		vector<pair<pii, int>> Person;

		queue<pair<pii, int>> Q;

		memset(Vis, false, sizeof(Vis));

		Q.push({ {taxi_x, taxi_y}, 0 });

		Vis[taxi_x][taxi_y] = true;

		while(!Q.empty())
		{
			pair<pii, int> T1 = Q.front();
			Q.pop();

			if (Board[T1.f.f][T1.f.s] > 0)
				Person.push_back({ {T1.f.f, T1.f.s}, T1.s });
				
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = T1.f.f + dx[dir];
				int ny = T1.f.s + dy[dir];

				if (nx < 0 || ny < 0 || nx >= N || ny >= N)
					continue;

				if (Vis[nx][ny])
					continue;

				if (Board[nx][ny] == -1)
					continue;

				Vis[nx][ny] = true;
				Q.push({ {nx, ny}, T1.s + 1 });
			}
		}

		if (Person.empty())
			return false;

		sort(Person.begin(), Person.end(), cmp);

		if (Oil - Person[0].s < 0)
			return false;

		Oil -= Person[0].s;

		taxi_x = Person[0].f.f, taxi_y = Person[0].f.s;

		int Person_Info = Board[taxi_x][taxi_y], Dist = -1;

		Board[taxi_x][taxi_y] = 0;

		memset(Vis, false, sizeof(Vis));

		Q.push({ {taxi_x, taxi_y}, 0 });

		Vis[taxi_x][taxi_y] = true;

		while (!Q.empty())
		{
			pair<pii, int> T1 = Q.front();
			Q.pop();

			if (T1.f.f == Dest[Person_Info].f && T1.f.s == Dest[Person_Info].s)
			{
				Dist = T1.s;
				break;
			}

			for (int dir = 0; dir < 4; dir++)
			{
				int nx = T1.f.f + dx[dir];
				int ny = T1.f.s + dy[dir];

				if (nx < 0 || ny < 0 || nx >= N || ny >= N)
					continue;

				if (Vis[nx][ny])
					continue;

				if (Board[nx][ny] == -1)
					continue;

				Vis[nx][ny] = true;
				Q.push({ {nx, ny}, T1.s + 1 });
			}
		}

		if (Dist == -1 || Oil - Dist < 0)
			return false;

		Board[taxi_x][taxi_y] = 0;

		taxi_x = Dest[Person_Info].f, taxi_y = Dest[Person_Info].s;

		Oil -= Dist;
		Oil += (2 * Dist);

		Cnt--;
	}

	return true;
}

void Input()
{
	cin >> N >> M >> Oil;

	Cnt = M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> Board[i][j];

			if (Board[i][j] == 1)
				Board[i][j] = -1;
		}
	}

	cin >> taxi_x >> taxi_y;

	taxi_x--, taxi_y--;

	for (int i = 1, a, b, c, d; i <= M; i++)
	{
		cin >> a >> b >> c >> d;
		Board[a - 1][b - 1] = i;
		Dest[i] = { c - 1, d - 1 };
	}
}

int main()
{
	fastio;

	Input();

	!solve() ? cout << -1 << '\n' : cout << Oil << '\n';
}