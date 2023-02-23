#include <bits/stdc++.h>

using namespace std;

int N, root, caution;

vector<int> Tree[51];

int DP[51]{ 0 };

int solve(int Idx, int Before)
{
	if (caution == Idx)
		return 0;

	int& ret = DP[Idx];

	if (ret != -1)
		return ret;

	ret = 0;

	for (int i = 0; i < (int)Tree[Idx].size(); i++)
	{
		if (Tree[Idx][i] == Before)
			continue;

		ret += solve(Tree[Idx][i], Idx);
	}

	if (ret == 0)
		return 1;

	return ret;
}

int main()
{
	cin >> N;

	for (int i = 0, a; i < N; i++)
	{
		cin >> a;

		if (a == -1)
			root = i;

		else
		{
			Tree[a].push_back(i);
			Tree[i].push_back(a);
		}
	}

	cin >> caution;

	memset(DP, -1, sizeof(DP));

	cout << solve(root, -1) << '\n';
}