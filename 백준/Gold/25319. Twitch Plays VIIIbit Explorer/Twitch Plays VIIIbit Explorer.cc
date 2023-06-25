#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int f_x, f_y, N, M, S, limi = INT_MAX;

string matching, total;

char board[51][51]{ 0 };

int is_alpha[27]{ 0 };

int another_alpha[27]{ 0 };

deque<pii> DQ[27];

int conv(char e)
{
	return (int)(e - 'a');
}

void carve_ans(char params)
{
	// 그래서 여기는 f_x, f_y, 그리고 현재 알파벳에 대한 정보가 들어가야 한다.

	int nx = DQ[conv(params)].front().x, ny = DQ[conv(params)].front().y;

	DQ[conv(params)].pop_front();
	
	int diff_x = nx - f_x, diff_y = ny - f_y;

	for (int i = 0; i < abs(diff_x); i++)
		total += (diff_x < 0 ? 'U' : 'D');

	for (int i = 0; i < abs(diff_y); i++)
		total += (diff_y < 0 ? 'L' : 'R');

	// 얘는 마지막에.
	f_x = nx, f_y = ny;

	total += 'P';
}

void last_move()
{
	int nx = N - 1, ny = M - 1;

	int diff_x = nx - f_x, diff_y = ny - f_y;

	for (int i = 0; i < abs(diff_x); i++)
		total += (diff_x < 0 ? 'U' : 'D');

	for (int i = 0; i < abs(diff_y); i++)
		total += (diff_y < 0 ? 'L' : 'R');
}

void solve()
{
	for (int i = 0; i < limi; i++)
	{
		for (auto e : matching)
			carve_ans(e);
	}

	last_move();
}



int main()
{
	cin >> N >> M >> S;

	for (int i = 0; i < N; i++)
	{
		string iv; cin >> iv;

		for (int j = 0; j < M; j++)
		{
			board[i][j] = iv[j];
			is_alpha[conv(board[i][j])]++;
			DQ[conv(board[i][j])].push_back({ i, j });
		}
	}

	cin >> matching;

	for (auto e : matching)
		another_alpha[conv(e)]++;

	for (auto e : matching)
		limi = min(limi, is_alpha[conv(e)] / another_alpha[conv(e)]);

	solve();

	cout << limi << " " << (int)(total.length()) << '\n';

	cout << total;
}