#include <bits/stdc++.h>

using namespace std;

int a, b, c, d;

int sqr_cnt[51][51]{ 0 };

int DP[51][51][51][51]{ 0 };

int get_rec(int na, int nb) // O(N^3)
{
	int& ret = sqr_cnt[na][nb];
	
	if (ret != -1)
		return ret;

	if (nb > na)
		return ret = get_rec(nb, na);

	if (na % nb == 0)
		return ret = na / nb;

	ret = INT_MAX;

	for (int i = 1; i < nb; i++)
	{
		int L = i, R = nb - i;

		ret = min(ret, get_rec(na, L) + get_rec(na, R));
	}
	for (int i = 1; i < nb; i++)
	{
		int L = i, R = na - i;

		ret = min(ret, get_rec(nb, L) + get_rec(nb, R));
	}

	return ret;
}

void init()
{
	for (int i = 1; i <= 50; i++)
	{
		for (int j = 1; j <= 50; j++)
			get_rec(i, j);
	}
}

int solve(int h1, int w1, int h2, int w2) // O(N^5)
{
	int& ret = DP[h1][w1][h2][w2];

	if (ret != -1)
		return ret;

	ret = INT_MAX;

	int hi_w = w1 - w2, hi_h = h1 - h2;

	for (int i = 1; i < w1; i++)
	{
		if (i < hi_w)
		{
			int L = i, R = hi_w - i;

			ret = min(ret, solve(h1, R + w2, h2, w2) + sqr_cnt[h1][L]);
		}
		else if (i == hi_w)
			ret = min(ret, sqr_cnt[h1][hi_w] + sqr_cnt[w2][hi_h]);
		else
		{
			int L = i - hi_w, R = w1 - i;

			ret = min(ret, solve(h1, hi_w + L, h2, L) + sqr_cnt[R][hi_h]);
		}
	}

	for (int i = 1; i < h1; i++)
	{
		if (i < h2)
		{
			int L = i, R = h2 - i;

			ret = min(ret, solve(R + hi_h, w1, R, w2) + sqr_cnt[hi_w][L]);
		}
		else if (i == h2)
			ret = min(ret, sqr_cnt[h2][hi_w] + sqr_cnt[w1][hi_h]);
		else
		{
			int L = i - h2, R = h1 - i;

			ret = min(ret, solve(h2 + L, w1, h2, w2) + sqr_cnt[w1][R]);
		}
	}
	
	return ret;
}

int main()
{
	cin >> a >> b >> c >> d;

	memset(sqr_cnt, -1, sizeof(sqr_cnt));

	memset(DP, -1, sizeof(DP));

	init();

	cout << solve(a, b, c, d) << '\n';
}