#include <bits/stdc++.h>
#define pii pair<int, int>
#define f first
#define s second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N;

vector<pii> Tree[50001];

bool Root_Vis[50001]{ 0 };

int Arr[50001]{ 0 };

int Root[50001]{ 0 };

pii DFS1(int Idx, int Before)
{
	pii ret = { 0, Idx };
	
	for (int i = 0; i < (int)Tree[Idx].size(); i++)
	{
		if (Before == Tree[Idx][i].f)
			continue;

		pii T1 = DFS1(Tree[Idx][i].f, Idx);

		if (ret.f < T1.f + Tree[Idx][i].s)
		{
			Arr[Idx] = max(Arr[Idx], T1.first + Tree[Idx][i].s);
			ret.f = T1.f + Tree[Idx][i].s;
			ret.s = T1.s;
		}
	}

	return ret;
}

bool Find_Root(int Idx, int Before, int Correct)
{
	if (Idx == Correct)
		return Root_Vis[Idx] = true;

	for (int i = 0; i < Tree[Idx].size(); i++)
	{
		if (Before == Tree[Idx][i].f)
			continue;
		if (Find_Root(Tree[Idx][i].f, Idx, Correct)) return Root_Vis[Idx] = true;
	}

	return Root_Vis[Idx] = false;
}

void Distance_To_Root(int Idx, int Before, int Distance, int Ori)
{
	if (!Root_Vis[Idx])
	{
		Arr[Idx] = Distance;
		Root[Idx] = Ori;
	}

	for (int i = 0; i < (int)Tree[Idx].size(); i++)
	{
		if (Before == Tree[Idx][i].f)
			continue;
		if (!Root_Vis[Tree[Idx][i].f])
			Distance_To_Root(Tree[Idx][i].f, Idx, Distance + Tree[Idx][i].s, Ori);
		else
			Distance_To_Root(Tree[Idx][i].f, Idx, Distance, Tree[Idx][i].f);
	}
}

int main()
{
	fastio;

	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		Tree[a].push_back({ b, c });
		Tree[b].push_back({ a, c });
	}

	pii Ans1 = DFS1(1, -1);

	pii Ans2 = DFS1(Ans1.second, -1);
	pii Ans3 = DFS1(Ans2.second, -1);

	Root_Vis[Ans2.second] = Find_Root(Ans2.second, -1, Ans1.second);

	Distance_To_Root(Ans1.second, -1, 0, Ans1.second);

	for (int i = 1; i <= N; i++)
	{
		if (Root_Vis[i])
			cout << Arr[i] << '\n';
		else
			cout << Arr[i] + Arr[Root[i]] << '\n';
	}
}