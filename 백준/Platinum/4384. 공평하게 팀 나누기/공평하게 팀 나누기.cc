#include <bits/stdc++.h>

using namespace std;

int DP[101][45001]{ 0 };

int roun, N, Arr[101];

int total, sub = INT_MAX;

int a, b;

int main()
{
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> Arr[i];
		total += Arr[i];
	}

	roun = N / 2;

	DP[0][0] = 1;

	for (int i = 0; i < N; i++)
	{
		for (int j = 45000; j >= 0; j--)
		{
			for (int k = roun; k >= 1; k--)
			{
				if (j + Arr[i] > 45000)
					continue;
				DP[k][j + Arr[i]] |= DP[k - 1][j];
			}
		}
	}

	for (int j = 0; j <= 45000; j++)
	{
		if (DP[roun][j])
		{
			if (abs(2 * j - total) < sub)
			{
				sub = abs(2 * j - total);
				a = min(abs(total - j), j), b = max(abs(total - j), j);
			}
		}
	}

	cout << a << " " << b;
}