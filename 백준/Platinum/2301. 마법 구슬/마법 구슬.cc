#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

// 실제 위치를 기억해야 할 듯?

pll solve(ll space, ll pos, ll inner_add, ll outer_add)
{
	if (space == 2)
	{
		if (pos == 1)
		{
			cout << 1 + inner_add << " ";
			cout << 2 + inner_add + outer_add << " ";
			return { 2 + inner_add + outer_add, 2 };
		}
		cout << 2 + inner_add + outer_add << " ";
		cout << 1 + inner_add << " ";
		return { 1 + inner_add, 1 };
	}

	ll half = space >> 1, dd_half = half >> 1;

	if (pos <= dd_half) // 바깥쪽 먼저
	{
		pll last = solve(space >> 1, pos, inner_add, outer_add + half);

		ll nj = last.x;

		if (last.y == 2)
			nj -= outer_add;

		if (nj - inner_add + half <= space)
			return solve(space >> 1, nj - inner_add + half - dd_half, inner_add + dd_half, outer_add);

		return solve(space >> 1, nj - inner_add - half - dd_half, inner_add + dd_half, outer_add);
	}

	else if (pos >= dd_half + 1 && pos <= half + dd_half) // 일단 안쪽부터 해볼까...
	{
		pll last = solve(space >> 1, pos - dd_half, inner_add + dd_half, outer_add);

		ll nj = last.x;

		if (last.y == 2)
			nj -= outer_add;

		if (nj - inner_add + half <= space)
			return solve(space >> 1, nj - inner_add, inner_add, outer_add + half);

		return solve(space >> 1, nj - inner_add - half, inner_add, outer_add + half);
	}

	pll last = solve(space >> 1, pos - half, inner_add, outer_add + half); // 바깥쪽 먼저 x2

	ll nj = last.x;

	if (last.y == 2)
		nj -= outer_add;

	if (nj - inner_add + half <= space)
		return solve(space >> 1, nj - inner_add + half - dd_half, inner_add + dd_half, outer_add);

	return solve(space >> 1, nj - inner_add - half - dd_half, inner_add + dd_half, outer_add);
}

int main()
{
	ll N, M;

	cin >> N >> M;

	solve(N, M, 0, 0);
}