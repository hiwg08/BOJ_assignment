#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pii pair<int, int>
#define f first
#define s second
#define all(x) (x).begin(), (x).end()

using namespace std;

int N, Ans[500001]{ 0 };

vector<pii> Arr;

vector<int> Tree;

int Init(int Tree_Node, int Start, int End)
{
	if (Start == End)
		return Tree[Tree_Node] = 1;
	
	int L = 2 * Tree_Node, R = L + 1, Mid = (Start + End) >> 1;

	return Tree[Tree_Node] = Init(L, Start, Mid) + Init(R, Mid + 1, End);
}

int Query(int Tree_Node, int Start, int End, int Cmd_A, int Cmd_B)
{
	if (Start > Cmd_B || End < Cmd_A)
		return 0;

	if (Cmd_A <= Start && End <= Cmd_B)
		return Tree[Tree_Node];

	int L = 2 * Tree_Node, R = L + 1, Mid = (Start + End) >> 1;

	return Query(L, Start, Mid, Cmd_A, Cmd_B) + Query(R, Mid + 1, End, Cmd_A, Cmd_B);
}

int Update(int Tree_Node, int Start, int End, int Cmd)
{
	if (Start > Cmd || End < Cmd)
		return Tree[Tree_Node];

	if (Start == End && End == Cmd)
		return Tree[Tree_Node] = 0;

	int L = 2 * Tree_Node, R = L + 1, Mid = (Start + End) >> 1;
		
	return Tree[Tree_Node] = Update(L, Start, Mid, Cmd) + Update(R, Mid + 1, End, Cmd);
}

int main()
{
	fastio;

	cin >> N;

	int tree_height = (int)ceil(log2(N));

	Tree.resize(static_cast<std::vector<int, std::allocator<int>>::size_type>(1) << (1 + tree_height));

	for (int i = 0, a; i < N; i++)
	{
		cin >> a;
		Arr.push_back({ a, i });
	}

	sort(all(Arr));

	Tree[1] = Init(1, 0, N - 1);

	for (auto iv : Arr)
	{
		Ans[iv.s] = Query(1, 0, N - 1, 0, iv.s);
		Tree[1] = Update(1, 0, N - 1, iv.s);
	}

	for (int i = 0; i < N; i++)
		cout << Ans[i] << '\n';
}