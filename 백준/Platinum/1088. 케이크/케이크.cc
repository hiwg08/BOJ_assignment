#include <bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;

struct info
{
	ld num;
	ll div;
	ll ori;

	info(ld _num, ll _div, ll _ori)
		:num(_num), div(_div), ori(_ori)
	{}
};

struct comp
{
	bool operator()(info a, info b)
	{
		return a.num < b.num;
	}
};

priority_queue<info, vector<info>, comp> PQ;

ll N, M;

ld min_num = LDBL_MAX, max_num = LDBL_MIN, ans;

void solve()
{
	for (ll i = 0; i < M; i++)
	{
		if (!PQ.empty())
		{
			info T1 = PQ.top();

			PQ.pop();

			ll cut = T1.div + 1;

			PQ.push(info((ld)T1.ori / cut, cut, T1.ori));
			min_num = min(min_num, (ld)T1.ori / cut);

			ans = min(ans, abs(PQ.top().num - min_num));
		}
	}
}

int main()
{
	cin >> N;

	for (ll i = 0, a; i < N; i++)
	{
		cin >> a;
		min_num = min(min_num, (ld)a);
		max_num = max(max_num, (ld)a);
		PQ.push(info((ld)a, 1, a));
	}

	cin >> M;

	cout.precision(9);

	if (N == 1)
	{
		cout << fixed << (ld)0;
		exit(0);
	}

	ans = max_num - min_num;

	solve();

	cout << fixed << ans;
}