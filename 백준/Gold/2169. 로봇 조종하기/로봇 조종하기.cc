#include <bits/stdc++.h>

using namespace std;

int N, M;

int DP_L[1002][1002]{ 0 }, DP_R[1002][1002]{ 0 }, DP[1002][1002]{ 0 };

int Arr[1002][1002]{ 0 };

int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			cin >> Arr[i][j];
	}

	for (int j = 1; j <= M; j++)
		DP[1][j] = Arr[1][j] + DP[1][j - 1]; // 1행은 단순 누적 합 

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= M; j++) // L부터 탐색
		{
			if (j == 1)
				DP_L[i][j] = DP[i - 1][j] + Arr[i][j]; // 바로 아래의 것을 끌고오자
			else
				DP_L[i][j] = max(DP_L[i][j - 1] + Arr[i][j], DP[i - 1][j] + Arr[i][j]);
		}

		for (int j = M; j >= 1; j--) // r부터 탐색
		{
			if (j == M)
				DP_R[i][j] = DP[i - 1][j] + Arr[i][j]; // 바로 아래의 것을 끌고오자
			else
				DP_R[i][j] = max(DP_R[i][j + 1] + Arr[i][j], DP[i - 1][j] + Arr[i][j]);
		}

		for (int j = 1; j <= M; j++) // L부터 탐색
			DP[i][j] = max({ DP_L[i][j], DP_R[i][j], DP[i - 1][j] + Arr[i][j] });
	}

	cout << DP[N][M];
}