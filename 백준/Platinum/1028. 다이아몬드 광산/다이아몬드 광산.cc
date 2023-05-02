#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int pre_sum_nw[753][753]{ 0 };
int pre_sum_ne[753][753]{ 0 };
int pre_sum_sw[753][753]{ 0 };
int pre_sum_se[753][753]{ 0 };

int Arr[753][753]{ 0 };

int R, C;

int total = 0;

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

bool monge_in(int params, int left)
{
	if (left == 1)
		return params >= 1 && params <= C; // 동, 서

	return params >= 1 && params <= R; // 남, 북
}

void solve()
{
	for (int i = 2; i <= R - 1; i++)
	{
		for (int j = 2; j <= C - 1; j++)
		{
			// i, j가 중심이 된다.

			for (int k = 1;; k++)
			{
				int N = i - k, S = i + k, W = j - k, E = j + k;

				if (monge_in(E, 1) && monge_in(W, 1) && monge_in(S, 0) && monge_in(N, 0))
				{
					int NW = pre_sum_nw[i][W] - pre_sum_nw[i - k - 1][W + k + 1];

					int NE = pre_sum_ne[i][E] - pre_sum_ne[i - k - 1][E - k - 1];

					int SW = pre_sum_sw[i][W] - pre_sum_sw[i + k + 1][W + k + 1];

					int SE = pre_sum_se[i][E] - pre_sum_se[i + k + 1][E - k - 1];

					if (NW == k + 1 && (NW == NE && NE == SW && SW == SE && NW == SE))
						total = max(total, k + 1);
				}
				else
					break;
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