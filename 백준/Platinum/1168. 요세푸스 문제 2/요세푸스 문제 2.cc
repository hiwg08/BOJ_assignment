#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N, K, point = 1, people;

int seg[100002 * 4];

vector<int> V;

int Init(int Node, int Start, int End)
{
	int& ret = seg[Node];

	if (Start == End)
	{
		ret++;
		return ret;
	}

	int L = 2 * Node, R = L + 1, Mid = (Start + End) >> 1;

	return ret = Init(L, Start, Mid) + Init(R, Mid + 1, End);
}

int addi(int Node, int Start, int End, int cmd_a, int cmd_b)
{
	if (cmd_a > End || cmd_b < Start)
		return 0;

	if (cmd_a <= Start && End <= cmd_b)
		return seg[Node];

	int L = 2 * Node, R = L + 1, Mid = (Start + End) >> 1;

	return addi(L, Start, Mid, cmd_a, cmd_b) + addi(R, Mid + 1, End, cmd_a, cmd_b);
}

int update(int Node, int Start, int End, int cmd)
{ 
	int& ret = seg[Node];

	if (Start == End)
	{
		V.push_back(End);
		ret--;
		return ret;
	}

	int L = 2 * Node, R = L + 1, Mid = (Start + End) >> 1;

	if (seg[L] >= cmd)
		return ret = update(L, Start, Mid, cmd) + seg[R];

	return ret = seg[L] + update(R, Mid + 1, End, cmd - seg[L]);
}

int main()
{
	fastio;

	cin >> N >> K;

	seg[1] = Init(1, 1, N);

	people = N;

	for (int i = 0; i < N; i++)
	{
		int L = addi(1, 1, N, 1, point - 1), R = addi(1, 1, N, point, N);

		if (R >= K)
			update(1, 1, N, L + K);

		else
		{
			int Idx = K - R;

			Idx % people == 0 ? update(1, 1, N, people) : update(1, 1, N, Idx % people);
		}

		point = V.back() + 1;

		if (point == N + 1) point = 1;

		people--;
	}

	cout << "<";

	for (int i = 0; i < (int)V.size(); i++)
	{
		cout << V[i];

		i == (int)V.size() - 1 ? cout << ">" << '\n' : cout << ", ";
	}

}