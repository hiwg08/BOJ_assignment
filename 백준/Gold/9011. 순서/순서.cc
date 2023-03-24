#include <bits/stdc++.h>

using namespace std;

int T, N;

int Arr[110]{ 0 };

bool Vis[110]{ 0 };

vector<int> V;

void solve(int Idx)
{
	if (Idx == -1)
		return;

	int cnt = 0;
	
	for (int i = 1; i <= Arr[Idx]; i++)
	{
		if (Vis[i])
			cnt++;
	}

	for (int i = Arr[Idx] + 1; i <= N; i++)
	{
		if (Vis[i])
		{
			cnt++;
			continue;
		}

		if (i - cnt - 1 == Arr[Idx])
		{
			Vis[i] = true;
			V.push_back(i);
			solve(Idx - 1);
			return;
		}
	}
}

int main()
{
	cin >> T;

	while (T--)
	{
		cin >> N;

		V.clear();

		memset(Vis, false, sizeof(Vis));

		for (int i = 0; i < N; i++)
			cin >> Arr[i];

		solve(N - 1);

		reverse(V.begin(), V.end());

		if ((int)V.size() != N)
			cout << "IMPOSSIBLE" << '\n';
		else
		{
			for (auto e : V)
				cout << e << " ";
			cout << '\n';
		}
	}
}