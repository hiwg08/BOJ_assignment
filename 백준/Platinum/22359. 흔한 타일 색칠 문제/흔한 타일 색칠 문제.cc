#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define o (ll)1

using namespace std;

string ST[4][4][4], ano[2][2][2];

ll N, a, b;

void precomp()
{
	ano[0][0][0] = "@a";
	ano[0][0][1] = "aa";

	ano[0][1][0] = "a@";
	ano[0][1][1] = "aa";

	ano[1][0][0] = "aa";
	ano[1][0][1] = "@a";

	ano[1][1][0] = "aa";
	ano[1][1][1] = "a@";

	///////////////////////////

	ST[0][0][0] = ".acc";
	ST[0][0][1] = "aabc";
	ST[0][0][2] = "cbba";
	ST[0][0][3] = "ccaa";

	ST[0][1][0] = "a.cc";
	ST[0][1][1] = "aabc";
	ST[0][1][2] = "cbba";
	ST[0][1][3] = "ccaa";

	ST[0][2][0] = "aa.c";
	ST[0][2][1] = "abcc";
	ST[0][2][2] = "cbba";
	ST[0][2][3] = "ccaa";

	ST[0][3][0] = "aac.";
	ST[0][3][1] = "abcc";
	ST[0][3][2] = "cbba";
	ST[0][3][3] = "ccaa";

	////////////////////////////////////

	ST[1][0][0] = "aacc";
	ST[1][0][1] = ".abc";
	ST[1][0][2] = "cbba";
	ST[1][0][3] = "ccaa";

	ST[1][1][0] = "aacc";
	ST[1][1][1] = "a.bc";
	ST[1][1][2] = "cbba";
	ST[1][1][3] = "ccaa";

	ST[1][2][0] = "aacc";
	ST[1][2][1] = "ab.c";
	ST[1][2][2] = "cbba";
	ST[1][2][3] = "ccaa";

	ST[1][3][0] = "aacc";
	ST[1][3][1] = "abc.";
	ST[1][3][2] = "cbba";
	ST[1][3][3] = "ccaa";

	////////////////////////////////////

	ST[2][0][0] = "aacc";
	ST[2][0][1] = "abbc";
	ST[2][0][2] = ".cba";
	ST[2][0][3] = "ccaa";

	ST[2][1][0] = "aacc";
	ST[2][1][1] = "abbc";
	ST[2][1][2] = "c.ba";
	ST[2][1][3] = "ccaa";

	ST[2][2][0] = "aacc";
	ST[2][2][1] = "abbc";
	ST[2][2][2] = "cb.a";
	ST[2][2][3] = "ccaa";

	ST[2][3][0] = "aacc";
	ST[2][3][1] = "abbc";
	ST[2][3][2] = "cba.";
	ST[2][3][3] = "ccaa";

	///////////////////////////

	ST[3][0][0] = "aacc";
	ST[3][0][1] = "abbc";
	ST[3][0][2] = "ccba";
	ST[3][0][3] = ".caa";

	ST[3][1][0] = "aacc";
	ST[3][1][1] = "abbc";
	ST[3][1][2] = "ccba";
	ST[3][1][3] = "c.aa";

	ST[3][2][0] = "aacc";
	ST[3][2][1] = "abbc";
	ST[3][2][2] = "cbaa";
	ST[3][2][3] = "cc.a";

	ST[3][3][0] = "aacc";
	ST[3][3][1] = "abbc";
	ST[3][3][2] = "cbaa";
	ST[3][3][3] = "cca.";
}

// 격자가 2 * 2일 때는 따로 처리.

ll get_sabun(ll dest_x, ll dest_y, ll multi)
{
	ll conv_dest_x = dest_x - multi, conv_dest_y = dest_y - multi;

	if (conv_dest_x < 0 && conv_dest_y < 0)
		return 1;

	if (conv_dest_x < 0 && conv_dest_y >= 0)
		return 2;

	if (conv_dest_x >= 0 && conv_dest_y < 0)
		return 3;

	return 4;
}

void solve(ll pows, ll x, ll y, ll dest_x, ll dest_y, bool flag) // pows가 2일 때 --> 격자가 4 * 4임.
{
	if (pows == 2)
	{
		if (ST[dest_x][dest_y][x][y] == '.')
		{
			if (flag)
				cout << '@';
			else
				cout << 'b';
		}
		else
			cout << ST[dest_x][dest_y][x][y];
		return;
	}

	ll ret_ori_sabun = get_sabun(x, y, o << (pows - 1));

	ll ret_dest_sabun = get_sabun(dest_x, dest_y, o << (pows - 1));

	if (ret_ori_sabun != ret_dest_sabun)
	{
		if (ret_ori_sabun == 1)
			solve(pows - 1, x, y, (o << (pows - 1)) - 1, (o << (pows - 1)) - 1, false);

		if (ret_ori_sabun == 2)
			solve(pows - 1, x, y - (o << (pows - 1)), (o << (pows - 1)) - 1, 0, false);

		if (ret_ori_sabun == 3)
			solve(pows - 1, x - (o << (pows - 1)), y, 0, (o << (pows - 1)) - 1, false);

		if (ret_ori_sabun == 4)
			solve(pows - 1, x - (o << (pows - 1)), y - (o << (pows - 1)), 0, 0, false);

		return;
	}

	if (ret_ori_sabun == 1)
		solve(pows - 1, x, y, dest_x, dest_y, flag);

	else if (ret_ori_sabun == 2)
		solve(pows - 1, x, y - (o << (pows - 1)), dest_x, dest_y - (o << (pows - 1)), flag);

	else if (ret_ori_sabun == 3)
		solve(pows - 1, x - (o << (pows - 1)), y, dest_x - (o << (pows - 1)), dest_y, flag);

	else
		solve(pows - 1, x - (o << (pows - 1)), y - (o << (pows - 1)), dest_x - (o << (pows - 1)), dest_y - (o << (pows - 1)), flag);
}	

ll T;

int main()
{
	fastio;

	precomp();

	cin >> T >> N;

	while (T--)
	{
		cin >> a >> b;

		if (N == 1)
		{
			cout << ano[a - 1][b - 1][0] << '\n';
			cout << ano[a - 1][b - 1][1] << '\n';
			continue;
		}

		for (ll i = 0; i < (o << N); i++)
		{
			for (ll j = 0; j < (o << N); j++)
			{
				ll ret_ori_sabun = get_sabun(i, j, o << (N - 1));

				ll ret_dest_sabun = get_sabun(a - 1, b - 1, o << (N - 1));

				solve(N, i, j, a - 1, b - 1, ret_ori_sabun == ret_dest_sabun);
			}
			cout << '\n';
		}
	}
}