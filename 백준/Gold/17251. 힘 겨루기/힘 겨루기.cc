#include <bits/stdc++.h>

using namespace std;

int N;

int MAX = 0;

vector<int> V, ans;

int main()
{
	cin >> N; V.resize(N);

	for (auto& iv : V)
	{
		cin >> iv;
		MAX = max(MAX, iv);
	}

	if (N == 1)
	{
		cout << 'X' << '\n';
		exit(0);
	}

	for (int i = 0; i < N; i++)
	{
		if (V[i] == MAX)
			ans.push_back(i);
	}

	int L = ans[0], R = N - 1 - ans.back();

	if (L == R)
		cout << 'X';
	else if (L > R)
		cout << 'B';
	else
		cout << 'R';
	cout << '\n';
}

// 왼쪽이 더 많다 --> B, 오른 쪽이 더 많다 --> R