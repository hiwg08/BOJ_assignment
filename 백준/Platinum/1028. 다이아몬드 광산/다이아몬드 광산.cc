#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int pre_sum_nw[753][753]{ 0 };
int pre_sum_ne[753][753]{ 0 };
int pre_sum_sw[753][753]{ 0 };
int pre_sum_se[753][753]{ 0 };

int Arr[753][753]{ 0 };

int R, C, total = 0;

void init_1()
{
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			pre_sum_nw[i][j] = Arr[i][j] + pre_sum_nw[i - 1][j + 1];
			pre_sum_ne[i][j] = Arr[i][j] + pre_sum_ne[i - 1][j - 1];
		}
	}
}

void init_2()
{
	for (int i = R; i >= 1; i--)
	{
		for (int j = 1; j <= C; j++)
		{
			pre_sum_sw[i][j] = Arr[i][j] + pre_sum_sw[i + 1][j + 1];
			pre_sum_se[i][j] = Arr[i][j] + pre_sum_se[i + 1][j - 1];
		}
	}
}

// 1 ~ R이면....
// 1 ~ C이면....

void solve()
{
	for (int k = 380; k >= 1; k--)
	{
		for (int i = 1 + k; i <= R - k; i++)
		{
			for (int j = 1 + k; j <= C - k; j++)
			{ // 아! 그냥 여기서 하면 되는구나!
				int x = i, W = j - k, E = j + k;

				int NW = pre_sum_nw[x][W] - pre_sum_nw[x - k - 1][W + k + 1];

				int NE = pre_sum_ne[x][E] - pre_sum_ne[x - k - 1][E - k - 1];

				int SW = pre_sum_sw[x][W] - pre_sum_sw[x + k + 1][W + k + 1];

				int SE = pre_sum_se[x][E] - pre_sum_se[x + k + 1][E - k - 1];

				if (NW == k + 1 && (NW == NE && NE == SW && SW == SE && NW == SE))
				{
					cout << k + 1;
					exit(0);
				}
			}
		}
	}
}

void input()
{
	cin >> R >> C;

	for (int i = 1; i <= R; i++)
	{
		string S; cin >> S;

		for (int j = 1; j <= C; j++)
		{
			Arr[i][j] = (int)(S[j - 1] - '0');

			if (Arr[i][j] == 1)
				total = 1;
		}
	}
}

int main()
{
	fastio;

	input();

	init_1();

	init_2();

	solve();

	cout << total;
}