#include <bits/stdc++.h>

using namespace std;

int N, K, Arr[101]{ 0 }, DP[10001]{ 0 };

int main()
{
	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> Arr[i];

	memset(DP, 0x3f, sizeof(DP));

	DP[0] = 0;

	for (int i = 1; i <= K; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i - Arr[j] >= 0 && DP[i - Arr[j]] != 0x3f3f3f3f)
				DP[i] = min(DP[i], DP[i - Arr[j]] + 1);
		}
	}

	if (DP[K] == 0x3f3f3f3f) cout << -1 << '\n';
	else cout << DP[K] << '\n';

}