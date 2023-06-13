#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll N, M, v_cnt, total = LLONG_MAX;

ll board[51][51]{ 0 };

bool vis[51][51]{ 0 };

vector<pll> initial;

vector<pll> active;

ll dx[]{ 1, 0, -1, 0 };
ll dy[]{ 0, 1, 0, -1 };

ll bfs()
{
	ll ret = 0;

	pair<bool, ll> present[51][51];

	for (auto& e : active)
	{
		memset(vis, 0, sizeof(vis));

		ll ni = e.x, nj = e.y;

		queue<pair<pll, ll>> Q;

		Q.push({ {ni, nj}, 0 });

		vis[ni][nj] = true;

		while (!Q.empty())
		{
			auto T1 = Q.front();

			if (!present[T1.x.x][T1.x.y].x)
			{
				present[T1.x.x][T1.x.y].x = true;
				present[T1.x.x][T1.x.y].y = T1.y;
			}
			else
				present[T1.x.x][T1.x.y].y = min(present[T1.x.x][T1.x.y].y, T1.y);

			Q.pop();

			for (ll dir = 0; dir < 4; dir++)
			{
				ll nx = T1.x.x + dx[dir], ny = T1.x.y + dy[dir];

				if (nx < 0 || ny < 0 || nx >= N || ny >= N)
					continue;

				if (vis[nx][ny])
					continue;

				if (board[nx][ny] == 1)
					continue;

				// 바이러스 통과가 불가능한 상황을 모두 적어주자.

				vis[nx][ny] = true;
				Q.push({ {nx, ny}, T1.y + 1 });
			}
		}
	}

	// 일단은... 비활성 바이러스까지 전부 시간으로 간주를 했기 때문에...

	for (ll i = 0; i < N; i++)
	{
		for (ll j = 0; j < N; j++)
		{
			if (board[i][j] == 0)
			{
				if (present[i][j].x)
					ret = max(ret, present[i][j].y);
				else
					return -1;
			}
		}
	}

	return ret;
}

void solve(ll Idx, ll cnt)
{
	if (cnt == M)
	{
		ll T = bfs();

		if (T != -1)
			total = min(total, bfs());
		return;
	}

	if (Idx >= v_cnt)
		return;

	active.push_back(initial[Idx]);
	solve(Idx + 1, cnt + 1);

	active.pop_back();
	solve(Idx + 1, cnt);
}

int main()
{
	cin >> N >> M;

	for (ll i = 0; i < N; i++)
	{
		for (ll j = 0; j < N; j++)
		{
			cin >> board[i][j];

			if (board[i][j] == 2)
			{
				initial.push_back({ i, j });
				v_cnt++;
			}
		}
	}

	solve(0, 0);

	if (total == LLONG_MAX)
		total = -1;
	cout << total;
}