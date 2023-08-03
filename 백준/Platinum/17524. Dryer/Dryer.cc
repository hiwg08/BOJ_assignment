#include <bits/stdc++.h>
#define pii pair<int ,int>
#define pdii pair<int, pii>
#define all(q) (q).begin(), (q).end()
#define x first
#define y second

using namespace std;

int N, K;

int temper[101]{ 0 };

vector<pdii> V;

int solve(vector<pdii> v, int groups)
{
	if (v.empty())
		return 0;

	int ret = INT_MAX, a = INT_MAX;

	for (auto e : v)
		a = min(a, e.y.x);

	vector<pdii> tmp;

	for (auto e : v)
		tmp.push_back({ (e.y.x - a) * e.y.y, {e.y.x, e.y.y} });

	sort(all(tmp), [&](pdii a, pdii b)
	{
		return a.x > b.x;
	});

	while (!tmp.empty())
	{
		auto it = tmp.back();
			
		tmp.pop_back();

		if (groups >= 2)
			ret = min(ret, 30 + it.x + solve(tmp, groups - 1));
		else
			ret = 30 + it.x;
	}

	return ret;
}

void input()
{
	cin >> N >> K;

	for (int i = 0, a, b; i < N; i++)
	{
		cin >> a >> b;
		temper[a] = max(temper[a], b);
	}

	for (int i = 40; i <= 100; i++)
	{
		if (temper[i] != 0)
			V.push_back({ 0, { i, temper[i] } });
	}
}

int main()
{
	input();

	cout << solve(V, K);
}