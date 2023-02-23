#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N, Arr[402][402]{ 0 }, ori_sum[402][402]{ 0 }, rev_sum[402][402]{ 0 }, Ans = INT_MIN;

void origin_init()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			ori_sum[i][j] = ori_sum[i - 1][j - 1] + Arr[i][j];
	}
}
void reverse_init()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			rev_sum[i][j] = rev_sum[i - 1][j + 1] + Arr[i][j];
	}
}

int main()
{
	fastio;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			cin >> Arr[i][j];
	}

	origin_init();

	reverse_init();

	for (int k = 1; k <= N; k++)
	{
		int par = N - k;

		for (int i = 1; i <= k; i++)
		{
			for (int j = 1; j <= k; j++)
			{
				int fir = ori_sum[i + par][j + par] - ori_sum[i - 1][j - 1];
				int sec = rev_sum[i + par][j] - rev_sum[i - 1][j + par + 1];
				Ans = max(Ans, fir - sec);
			}
		}
	}

	cout << Ans << '\n';
}