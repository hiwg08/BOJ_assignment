#include <bits/stdc++.h>

using namespace std;

int N;

int C;

int board[16][30000]{ 0 };

void reconstruct_o(int numb, int node, int cnt)
{
	if (cnt == C - 1)
	{
		board[C][node] = numb;
		return;
	}

	reconstruct_o(numb, node, cnt + 1);
	reconstruct_o(numb + (1 << cnt), node + (1 << (C - (cnt + 2))), cnt + 1);
}

void reconstruct_r(int numb, int node, int cnt)
{
	if (cnt == C - 1)
	{
		board[C][node] = numb;
		return;
	}

	reconstruct_r(numb, node + (1 << (C - (cnt + 2))), cnt + 1);
	reconstruct_r(numb + (1 << cnt), node, cnt + 1);
}

void preorder(int cnt, int node)
{
	cout << board[cnt][node] << " ";

	if (cnt < N)
	{
		preorder(cnt + 1, 2 * node);
		preorder(cnt + 1, 2 * node + 1);
	}
}

int main()
{
	cin >> N;

	C = N;

	reconstruct_o(1 << (N - 1), 0, 0);

	for (int i = N - 1; i >= 1; i--)
	{
		C = i;
		reconstruct_r(1 << (i - 1), 0, 0);
	}
		
	preorder(1, 0);
}