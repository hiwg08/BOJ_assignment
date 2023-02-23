#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int seg[210000 * 4]{ 0 };

int pos[222222]{ 0 };

int T, n, m, Idx = 101011;

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

int update(int Node, int Start, int End, int cmd)
{
	int& ret = seg[Node];

	if (cmd > End || cmd < Start)
		return ret;

	if (Start == End)
	{
		if (End == cmd)
			ret--;
		return ret;
	}

	int L = 2 * Node, R = L + 1, Mid = (Start + End) >> 1;

	return ret = update(L, Start, Mid, cmd) + update(R, Mid + 1, End, cmd);
}


int solve(int Node, int Start, int End, int cmd_a, int cmd_b)
{
	if (cmd_a > End || cmd_b < Start)
		return 0;

	if (cmd_a <= Start && End <= cmd_b)
		return seg[Node];

	int L = 2 * Node, R = L + 1, Mid = (Start + End) >> 1;

	return solve(L, Start, Mid, cmd_a, cmd_b) + solve(R, Mid + 1, End, cmd_a, cmd_b);
}

int ans[100010]{ 0 };

int main()
{
	fastio;

	cin >> T;

	while (T--)
	{
		memset(seg, 0, sizeof(seg));

		memset(ans, 0, sizeof(ans));

		memset(pos, -1, sizeof(pos));

		Init(1, 0, 202020);

		Idx = 101011;

		cin >> n >> m;

		for (int i = 0, a; i < m; i++)
		{
			cin >> a;

			if (pos[a] == -1)
			{
				ans[i] = solve(1, 0, 202020, Idx, a + 101010 - 1);
				update(1, 0, 202020, a + 101010);
			}
				
			else
			{
				ans[i] = solve(1, 0, 202020, Idx, pos[a] - 1);
				update(1, 0, 202020, pos[a]);
			}
			
			Idx--;
			pos[a] = Idx;
		}

		for (int i = 0; i < m; i++)
			cout << ans[i] << " ";
		cout << '\n';
	}
}