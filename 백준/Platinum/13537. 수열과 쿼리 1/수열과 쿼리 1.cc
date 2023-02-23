#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

vector<vector<int>> Tree;

int N, M, Arr[100001]{ 0 };

vector<int> merge(vector<int> L, vector<int> R)
{
	vector<int> par;

	int L_Ptr = 0, R_Ptr = 0;

	int L_S = (int)L.size() - 1, R_S = (int)R.size() - 1;

	while (L_Ptr <= L_S && R_Ptr <= R_S)
		(L[L_Ptr] < R[R_Ptr]) ? par.push_back(L[L_Ptr++]) : par.push_back(R[R_Ptr++]);

	if (L_Ptr > L_S)
	{
		for (int i = R_Ptr; i <= R_S; i++)
			par.push_back(R[i]);
	}

	else
	{
		for (int i = L_Ptr; i <= L_S; i++)
			par.push_back(L[i]);
	}

	return par;
}

vector<int> Init(int Tree_Node, int Start, int End)
{
	if (Start == End)
		return Tree[Tree_Node] = { Arr[Start] };

	int L = 2 * Tree_Node, R = L + 1, Mid = (Start + End) >> 1;

	vector<int> L_V = Init(L, Start, Mid);
	vector<int> R_V = Init(R, Mid + 1, End);

	return Tree[Tree_Node] = merge(L_V, R_V);
}

int Query(int Tree_Node, int Start, int End, int Cmd_A, int Cmd_B, int standard)
{
	if (Cmd_A <= Start && End <= Cmd_B)
		return (int)Tree[Tree_Node].size() - (int)(upper_bound(Tree[Tree_Node].begin(), Tree[Tree_Node].end(), standard) - Tree[Tree_Node].begin());

	if (Cmd_B < Start || Cmd_A > End)
		return 0;

	int L = 2 * Tree_Node, R = L + 1, Mid = (Start + End) >> 1;

	int A = Query(L, Start, Mid, Cmd_A, Cmd_B, standard);
	int B = Query(R, Mid + 1, End, Cmd_A, Cmd_B, standard);

	return A + B;
}

int main()
{
	fastio;

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> Arr[i];

	int Tree_Height = (int)ceil(log2(N));

	Tree.resize(static_cast<std::vector<std::vector<int, std::allocator<int>>, std::allocator<std::vector<int, std::allocator<int>>>>::size_type>(1) << (Tree_Height + 1));

	Init(1, 0, N - 1);

	cin >> M;

	for (int i = 0, a, b, c; i < M; i++)
	{
		cin >> a >> b >> c;
		cout << Query(1, 0, N - 1, a - 1, b - 1, c) << '\n';
	}
}