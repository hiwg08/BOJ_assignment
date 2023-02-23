#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int T, N, PreOrder[1001]{ 0 }, InOrder[1001]{0}, PostOrder[1001]{ 0 };

void For_Inorder(int S, int E, int Tree_Idx, vector<vector<int>>& Trees)
{
	if (S >= E)
		return;

	int Left_Cnt = 0, i;

	for (i = S; i <= E; i++)
	{
		if (InOrder[i] == PreOrder[Tree_Idx])
			break;
		Left_Cnt++;
	}

	if (Left_Cnt >= 1)
	{
		Trees[PreOrder[Tree_Idx]].push_back(PreOrder[Tree_Idx + 1]);
		For_Inorder(S, i - 1, Tree_Idx + 1, Trees);
	}
	if (E - S - Left_Cnt >= 1)
	{
		Trees[PreOrder[Tree_Idx]].push_back(PreOrder[Tree_Idx + 1 + Left_Cnt]);
		For_Inorder(i + 1, E, Tree_Idx + 1 + Left_Cnt, Trees);
	}
}

void Post_Order(vector<vector<int>>& Trees, int Node)
{
	if (Trees[Node].size() >= 1)
		Post_Order(Trees, Trees[Node][0]);
	if (Trees[Node].size() >= 2)
		Post_Order(Trees, Trees[Node][1]);
	cout << Node << " ";
}

int main()
{
	fastio;

	cin >> T;

	while (T--)
	{
		memset(PreOrder, 0, sizeof(PreOrder));
		memset(InOrder, 0, sizeof(InOrder));

		cin >> N;

		vector<vector<int>> Trees;

		Trees.resize(N + 1);

		for (int i = 0; i < N; i++)
			cin >> PreOrder[i];

		for (int i = 0; i < N; i++)
			cin >> InOrder[i];

		For_Inorder(0, N - 1, 0, Trees);

		Post_Order(Trees, PreOrder[0]);

		cout << '\n';
	}
}