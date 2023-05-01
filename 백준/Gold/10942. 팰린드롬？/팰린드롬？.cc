#include <bits/stdc++.h>

using namespace std;

int N, M, I1, I2;

int Board[2001]{ 0 };

int DP[2001][2001]{ 0 };

// 다이나믹 프로그래밍은 뭐가 됐던, 탐색한 부분과 안 한 부분을 무조건 나눠야 한다.

int Solution(int start, int end)
{
	int& ref = DP[start][end];

	if (ref != -1)
		return ref;

	if (start > end)
		return 1;

	if (start == end)
		return ref = 1;

	if (Board[start] != Board[end])
		return ref = 0;

	return ref = Solution(start + 1, end - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> Board[i];

	memset(DP, -1, sizeof(DP));
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = i; j <= N; j++)
		{
			DP[i][j] = Solution(i, j);
		}
	} // 브루트 포스 사용 (시간 제한 때문에 걱정하는 거라면 DP 특징 때문에 걱정 안 해도 된다.)

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> I1 >> I2;
		cout << DP[I1][I2] << '\n';
	}
}