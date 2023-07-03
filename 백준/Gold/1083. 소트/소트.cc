#include <bits/stdc++.h>

using namespace std;

int N, S;

vector<int> V;

void solve()
{
	for (int start = 0; start < N; start++)
	{
		int max_value = V[start], max_Idx = start;

		int tmp = 0;

		for (int nxt = start + 1; nxt < N; nxt++)
		{
			if (tmp == S)
				break;

			if (max_value < V[nxt])
			{
				max_Idx = nxt;
				max_value = V[nxt];
			}
			tmp++;
		}

		for (int j = max_Idx; j > start; j--)
		{
			swap(V[j], V[j - 1]);
			S--;
		}
	}
}

int main()
{
	cin >> N; V.resize(N);

	for (auto& iv : V)
		cin >> iv;

	cin >> S;

	solve();

	for (auto e : V)
		cout << e << " ";
}