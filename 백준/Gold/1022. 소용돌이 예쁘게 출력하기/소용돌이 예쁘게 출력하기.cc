#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int r1, c1, r2, c2, Total, Inc = 1, Interval = 0;

int Board[61][61]{ 0 };

bool calculate_and_check(int x, int y, int &Idx)
{
	if ((x >= r1 && x <= r2) && (y >= c1 && y <= c2))
	{
		Idx++;
		Board[x - r1][y - c1] = Inc;
	}

	return Idx == Total;
}

void solve()
{
	int x = 0, y = 0;

	int Idx = 0, Cnt = 1;

	bool flag = true;

	if (calculate_and_check(x, y, Idx))
		return;

	while (true)
	{
		for (int j = 0; j < Cnt; j++) // y좌표만
		{
			flag ? y++ : y--;

			Inc++;

			if (calculate_and_check(x, y, Idx))
				return;
		}

		for (int j = 0; j < Cnt; j++) // x좌표만
		{
			flag ? x-- : x++;

			Inc++;

			if (calculate_and_check(x, y, Idx))
				return;
		}

		flag = !flag;
		Cnt++;
	}
}

int main()
{
	fastio;

	cin >> r1 >> c1 >> r2 >> c2;

	Total = ((abs(r2 - r1) + 1) * (abs(c2 - c1) + 1));

	solve();

	while (Inc > 0)
		Inc /= 10, Interval++;

	for (int i = 0; i <= r2 - r1; i++)
	{
		for (int j = 0; j <= c2 - c1; j++)
		{
			int tmp = Board[i][j], tmp_Interval = 0;

			while (tmp > 0)
				tmp /= 10, tmp_Interval++;

			for (int k = 0; k < Interval - tmp_Interval; k++)
				cout << " ";

			cout << Board[i][j];

			if (j != c2 - c1)
				cout << " ";
		}

		cout << '\n';
	}
}