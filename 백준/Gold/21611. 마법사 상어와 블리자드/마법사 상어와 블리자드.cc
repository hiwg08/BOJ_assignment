#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int N, M, Arr[51][51]{ 0 }, d, s;

deque<int> DQ;

int ans_arr[4]{ 0 };

vector<pii> info;

int dir_info[5]{ 0 };

void destroy(int i)
{
	int start = 1;

	int interval = 2;

	int Idx = info[i].y;

	while (Idx--)
	{
		int q = start + info[i].x * interval;

		DQ[q - 1] = -1;

		int end = start + 3 * interval;

		start = end + interval + 1;

		interval += 2;
	}
}

int s_x, s_y;

int dx[]{ 0, 1, 0, -1 };
int dy[]{ -1, 0, 1, 0 };  

void init()
{
	int Idx = 1;

	while (true)
	{
		int chk = Idx - 1;

		int dir = chk % 4;

		int distance = (Idx + 1) / 2;

		while (distance--)
		{
			s_x += dx[dir];
			s_y += dy[dir];

			DQ.push_back(Arr[s_x][s_y]);

			if (s_x == 0 && s_y == 0)
				break;
		}

		if (s_x == 0 && s_y == 0)
			break;

		Idx++;
	}
}

void empty_move()
{
	deque<int> cpy;

	int cnt = 0;

	for (int i = 0; i < (int)DQ.size(); i++)
	{
		if (DQ[i] == -1)
		{
			cnt++;
			continue;
		}
		cpy.push_back(DQ[i]);
	}

	while (cnt--)
		cpy.push_back(0);

	DQ = cpy;
}

bool real()
{
	bool ans = false;

	int fir = DQ[0], cnt = 1;

	for (int i = 1; i < (int)DQ.size(); i++)
	{
		if (DQ[i] == fir)
			cnt++;
		else
		{
			if (cnt >= 4)
			{
				ans_arr[fir] += cnt;
				ans = true;
				for (int j = i - 1; cnt > 0; cnt--, j--)
					DQ[j] = -1;
			}
			cnt = 1;
			fir = DQ[i];
		}
	}

	return ans;
}

void explode()
{
	while (true)
	{
		empty_move();

		if (!real())
			break;

		empty_move();
	}
}

void change()
{
	deque<int> cpy;

	int fir = DQ[0], cnt = 1;

	for (int i = 1; i < (int)DQ.size(); i++)
	{
		if (DQ[i] == fir)
			cnt++;

		else
		{
			if ((int)cpy.size() < N * N - 1) cpy.push_back(cnt);
			if ((int)cpy.size() < N * N - 1) cpy.push_back(fir);
			
			fir = DQ[i];
			cnt = 1;
		}
	}

	while ((int)cpy.size() < N * N - 1)
		cpy.push_back(0);

	DQ = cpy;
}

void Input()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> Arr[i][j];
	}

	dir_info[1] = 3, dir_info[2] = 1, dir_info[3] = 0, dir_info[4] = 2;

	for (int i = 0; i < M; i++)
	{
		cin >> d >> s;

		info.push_back({ dir_info[d], s});
	}

	s_x = N / 2, s_y = N / 2;
}

int main()
{
	Input();

	init();

	for (int i = 0; i < M; i++)
	{
		destroy(i);
		explode();
		change();
	}

	cout << 1 * ans_arr[1] + 2 * ans_arr[2] + 3 * ans_arr[3] << '\n';
}