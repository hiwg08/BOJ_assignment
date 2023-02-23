#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pll pair<ll, ll>
#define f first
#define s second

using namespace std;

ll N, W[200001]{ 0 };

pll DP[200001];

vector<ll> Tree[200001];

void Init()
{
	for (ll i = 1; i <= 200000; i++)
		DP[i] = { -1, -1 };
}

pll solve(ll Idx, ll Before)
{
	pll& ret = DP[Idx];

	if (ret.s != -1)
		return ret;

	ret = { 0, 0 };

	bool flag = false;

	for (ll i = 0; i < (ll)Tree[Idx].size(); i++)
	{
		if (Tree[Idx][i] == Before)
			continue;

		pll T1 = solve(Tree[Idx][i], Idx);

		ll tmp = max(T1.f, T1.s);

		if (!flag)
		{
			flag = true;
			ret.s = (W[Tree[Idx][i]] * W[Idx]) + T1.f + ret.f;
		}
		else
			ret.s = max(ret.s + tmp, (W[Tree[Idx][i]] * W[Idx]) + T1.f + ret.f);

		ret.f += tmp;
	}

	return ret;
}

void Input()
{
	fastio;

	cin >> N;

	for (ll i = 2, a; i <= N; i++)
	{
		cin >> a;
		Tree[i].push_back(a);
		Tree[a].push_back(i);
	}

	for (ll i = 1; i <= N; i++)
		cin >> W[i];

	Init();
}

int main()
{
	Input();

	pll Ans = solve(1, -1);

	cout << max(Ans.f, Ans.s) << '\n';
}