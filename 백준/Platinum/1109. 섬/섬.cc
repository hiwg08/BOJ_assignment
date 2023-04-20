#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int N, M, mask, mask_ori; // N은 행, M은 열

char Arr[51][51]{ 0 };

int vis[51][51]{ 0 };

bool ano_vis[3000]{ 0 };

vector<pii> start[3000];

vector<int> tree[3000];

int ans[3001]{ 0 };

int dx[]{ 1, 0, -1, 0, -1, -1, 1, 1 };
int dy[]{ 0, 1, 0, -1, 1, -1, 1, -1 };

int dfs(int Idx)
{
	ano_vis[Idx] = true;

	bool chk = false;

	int ret = 0;

	for (auto e : tree[Idx])
	{
		chk = true;
		ret = max(ret, dfs(e));
	}

	!chk ? ret = 0 : ret = ret + 1;

	if (ans[ret] == -1)
		ans[ret] = 0;

	ans[ret]++;

	return ret;
}

void bfs(int px, int py, int d, char same)
{
	vis[px][py] = mask;

	queue<pii> Q;

	Q.push({ px, py });

	while (!Q.empty())
	{
		pii T1 = Q.front();
		Q.pop();

		if (mask > 0)
			start[mask].push_back({ T1.x, T1.y });

		for (int dir = 0; dir < d; dir++)
		{
			int nx = T1.x + dx[dir], ny = T1.y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue;

			if (vis[nx][ny] != 0)
				continue;

			if (Arr[nx][ny] != same)
				continue;

			vis[nx][ny] = mask;

			Q.push({ nx, ny });
		}
	}
}

set<int> make_sima(int px, int py, int standard)
{
	vis[px][py] = mask;

	set<int> ret;

	queue<pii> Q;

	Q.push({ px, py });

	while (!Q.empty())
	{
		pii T1 = Q.front();
		Q.pop();

		vis[T1.x][T1.y] = mask;

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = T1.x + dx[dir], ny = T1.y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue;

			if (vis[nx][ny] > 0 && vis[nx][ny] != standard)
			{
				ret.insert(vis[nx][ny]);
				continue;
			}

			if (vis[nx][ny] != 0)
				continue;

			if (Arr[nx][ny] != '.')
				continue;

			vis[nx][ny] = mask;

			Q.push({ nx, ny });
		}
	}

	return ret;
}

void is_cycle(int standard)
{
	for (auto e : start[standard])
	{
		auto ni = e.x, nj = e.y;

		for (int dir = 0; dir < 8; dir++)
		{
			int nx = ni + dx[dir], ny = nj + dy[dir];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue;

			if (vis[nx][ny] != 0)
				continue;

			set<int> ss = make_sima(nx, ny, standard);

			for (auto e : ss)
				tree[standard].push_back(e);
		}
	}
}

void input()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> Arr[i][j];
	} // 입력 on

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (vis[i][j] == 0 && Arr[i][j] == 'x')
			{
				mask++;
				bfs(i, j, 8, 'x');
			}
		}
	} // 1. 우선 섬들을 flood_fill로 채워주자.

	mask_ori = mask;

	mask = -1;

	for (int i = 0; i < M; i++) // 0행, 마지막 행을 기준
	{
		if (vis[0][i] == 0 && Arr[0][i] == '.') // 외곽 
			bfs(0, i, 4, '.');
		if (vis[N - 1][i] == 0 && Arr[N - 1][i] == '.') // 외곽 
			bfs(N - 1, i, 4, '.');
	} // 2. 0행, 마지막 행에서, 맵에서의 가장 '최외각'인 곳을 전부 flood_fill

	for (int i = 0; i < N; i++) // 0열, 마지막 열을 기준
	{
		if (vis[i][0] == 0 && Arr[i][0] == '.') // 외곽 
			bfs(i, 0, 4, '.');
		if (vis[i][M - 1] == 0 && Arr[i][M - 1] == '.') // 외곽 
			bfs(i, M - 1, 4, '.');
	} // 3. 0열, 마지막 열에서, 맵에서의 가장 '최외각'인 곳을 전부 flood_fill
}

int main()
{
	input();

	for (int i = 1; i <= mask_ori; i++)
		is_cycle(i);

	memset(ans, -1, sizeof(ans));

	for (int i = 1; i <= mask_ori; i++) // 모든 섬에 대해 트리 dfs를 수행한다. 섬 A가 B를 감싸고 있다면, 섬 A - B는 부모 - 자식 관계라고 생각하는 거다. 
	{
		if (!ano_vis[i])
			dfs(i);
	}

	if (mask_ori == 0) // 섬이 하나라도 없다면 -1
		cout << -1;

	for (int i = 0; i <= 3000; i++)
	{
		if (ans[i] == -1)
			break;
		cout << ans[i] << " ";
	}
}