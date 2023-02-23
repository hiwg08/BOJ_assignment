#include <bits/stdc++.h>

using namespace std;

int N, K, DP[101][100001]{ 0 }, total = INT_MIN;

int main()
{
	cin >> N >> K;

	memset(DP, -1, sizeof(DP));

	for (int i = 0, a, b, c, d; i < N; i++)
	{
		cin >> a >> b >> c >> d;

		if (i == 0)
		{
			int fir_s = 0, fir_m = 0, sec_s = 0, sec_m = 0;

			if (a >= c)
				fir_s = c, fir_m = d, sec_s = a, sec_m = b;
			else
				fir_s = a, fir_m = b, sec_s = c, sec_m = d;

			for (int j = fir_s; j <= K; j++)
				DP[i][j] = fir_m;
			for (int j = sec_s; j <= K; j++)
				DP[i][j] = max(fir_m, sec_m);
		}

		else
		{
			for (int j = K; j >= 0; j--)
			{
				if (j - a >= 0 && DP[i - 1][j - a] != -1)
					DP[i][j] = max(DP[i][j], DP[i - 1][j - a] + b);
				if (j - c >= 0 && DP[i - 1][j - c] != -1)
					DP[i][j] = max(DP[i][j], DP[i - 1][j - c] + d);
			}
		}
	}

	cout << DP[N - 1][K] << '\n';
}