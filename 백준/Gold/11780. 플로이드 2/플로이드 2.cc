#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF (int)(1e9 + 7)

using namespace std;

int N, M;

int DP[101][101]{ 0 };

vector<int> trace[101][101];

vector<int> reconstruct(const vector<int>& params1, const vector<int>& params2)
{
	vector<int> ret = params1;

	for (int i = 0; i < (int)params2.size(); i++)
	{
		if (i != 0)
			ret.push_back(params2[i]);
	}

	return ret;
}

int main()
{
	fastio;

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			DP[i][j] = INF;
	}

	for (int i = 0, a, b, c; i < M; i++)
	{
		cin >> a >> b >> c;
		DP[a][b] = min(DP[a][b], c);
		trace[a][b] = { a, b };
	}

	for (int i = 1; i <= N; i++)
		DP[i][i] = 0;

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (DP[i][j] > DP[i][k] + DP[k][j])
				{
					DP[i][j] = DP[i][k] + DP[k][j];
					trace[i][j] = reconstruct(trace[i][k], trace[k][j]);
				}
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			DP[i][j] == INF ? cout << 0 : cout << DP[i][j];
			cout << " ";
		}
		cout << '\n';
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (trace[i][j].empty())
			{
				cout << 0 << '\n';
				continue;
			}

			cout << (int)trace[i][j].size() << " ";
				
			for (auto e : trace[i][j])
				cout << e << " ";
			cout << '\n';
		}
	}
}