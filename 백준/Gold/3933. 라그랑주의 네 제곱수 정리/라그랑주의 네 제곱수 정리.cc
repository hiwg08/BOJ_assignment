#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 32768

using namespace std;

int N, DP[MAX + 1][5];

vector<int> V;

void solve()
{
	for (int i = 1; i <= 181; i++)
		V.push_back(i * i);

	DP[0][0] = 1;

	for (int i = 0; i < (int)V.size(); i++)
	{
		for (int j = V[i]; j <= MAX; j++)
		{
			for (int k = 1; k <= 4; k++)
				DP[j][k] += DP[j - V[i]][k - 1];
		}
	}
}

int main()
{
	fastio;

	solve();

	while (true)
	{
		cin >> N;

		if (N == 0)
			break;

		cout << DP[N][1] + DP[N][2] + DP[N][3] + DP[N][4] << '\n';
	}
}