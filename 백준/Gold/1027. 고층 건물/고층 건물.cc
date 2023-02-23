#include <bits/stdc++.h>
#define int long long

using namespace std;

int N, Arr[51]{ 0 }, Ans, a, b, MAX = INT_MIN;

int32_t main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> Arr[i];

	for (int i = 0; i < N; i++)
	{
		Ans = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (j == i - 1)
			{
				a = 1, b = Arr[j] - Arr[i];
				Ans++;
			}
			else
			{
				int c = i - j, d = Arr[j] - Arr[i];
				if (c * b < a * d)
				{
					a = c, b = d;
					Ans++;
				}
			}
		}
		for (int j = i + 1; j < N; j++)
		{
			if (j == i + 1)
			{
				a = 1, b = Arr[j] - Arr[i];
				Ans++;
			}
			else
			{
				int c = j - i, d = Arr[j] - Arr[i];
				if (c * b < a * d)
				{
					a = c, b = d;
					Ans++;
				}
			}
		}

		MAX = max(MAX, Ans);
	}

	cout << MAX << '\n';
}