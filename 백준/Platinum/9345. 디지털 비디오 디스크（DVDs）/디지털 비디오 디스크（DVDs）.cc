#include <bits/stdc++.h>
#define pii pair<int, int>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N, K, T, Arr[100001]{ 0 };

vector<pii> Tree;

pii Init(int Tree_Node, int Start, int End)
{
	if (Start == End)
	{
		Arr[Start] = Start;
		return Tree[Tree_Node] = { Start, End };
	}

	int L = 2 * Tree_Node, R = L + 1, Mid = (Start + End) / 2;

	pii P_F = Init(L, Start, Mid);
	pii P_S = Init(R, Mid + 1, End);

	return Tree[Tree_Node] = { max(P_F.first, P_S.first), min(P_F.second, P_S.second) };
}

pii Update(int Tree_Node, int Start, int End, int Target, int Value)
{
	if (Target < Start || Target > End)
		return Tree[Tree_Node];

	if (Start == End)
	{
		if (Target == Start)
			return Tree[Tree_Node] = { Value, Value };
		return Tree[Tree_Node];
	}

	int L = 2 * Tree_Node, R = L + 1, Mid = (Start + End) / 2;

	pii P_F = Update(L, Start, Mid, Target, Value);
	pii P_S = Update(R, Mid + 1, End, Target, Value);

	return Tree[Tree_Node] = { max(P_F.first, P_S.first), min(P_F.second, P_S.second) };
}

pii Solve(int Tree_Node, int Start, int End, int Cmd_A, int Cmd_B)
{
	if (Cmd_A <= Start && End <= Cmd_B)
		return Tree[Tree_Node];
	if (End < Cmd_A || Start > Cmd_B)
		return { INT_MIN, INT_MAX };

	int L = 2 * Tree_Node, R = L + 1, Mid = (Start + End) / 2;

	pii P_F = Solve(L, Start, Mid, Cmd_A, Cmd_B);
	pii P_S = Solve(R, Mid + 1, End, Cmd_A, Cmd_B);

	return { max(P_F.first, P_S.first), min(P_F.second, P_S.second) };
}

int main()
{
	fastio;

	cin >> T;
	
	while (T--)
	{
		cin >> N >> K;

		vector<pii>().swap(Tree);
		Tree.clear();

		int Tree_Height = (int)ceil(log2(N));

		Tree.resize(1 << (1 + Tree_Height));

		Tree[1] = Init(1, 0, N - 1);

		for (int i = 0; i < K; i++)
		{
			int a, b, c; cin >> a >> b >> c;

			if (a == 0)
			{
				swap(Arr[b], Arr[c]);
				Tree[1] = Update(1, 0, N - 1, b, Arr[b]);
				Tree[1] = Update(1, 0, N - 1, c, Arr[c]);
			}
			else
			{
				pii Ans = Solve(1, 0, N - 1, b, c);
				if (Ans.second != b || Ans.first != c)
					cout << "NO" << '\n';
				else
					cout << "YES" << '\n';
			}
		}
	}
}