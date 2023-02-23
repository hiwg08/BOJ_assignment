#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;

int N, DP[51]{ 0 };

vector<int> Tree[51];

int solve(int Idx, int Before)
{
	int& ret = DP[Idx];

	if (ret != -1)
		return ret;

	ret = 0;

	vector<int> V;

	for (int i = 0; i < (int)Tree[Idx].size(); i++)
	{
		if (Tree[Idx][i] == Before)
			continue;
		V.push_back(solve(Tree[Idx][i], Idx));
	}

	sort(all(V)); reverse(all(V));

	int Cnt = 0;

	for (auto e : V)
		ret = max(ret, e + (++Cnt));

	return ret;
}

int main()
{
	cin >> N;

	for (int i = 0, a; i < N; i++)
	{
		cin >> a;

		if (i != 0)
		{
			Tree[a].push_back(i);
			Tree[i].push_back(a);
		}
	}

	memset(DP, -1, sizeof(DP));

	cout << solve(0, -1) << '\n';
}