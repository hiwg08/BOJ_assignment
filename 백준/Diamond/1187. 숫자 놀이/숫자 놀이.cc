#include <bits/stdc++.h>
#define ll long long
#define vl vector<ll>
#define ppvl pair<vl, vl>
#define x first
#define y second

using namespace std;

ll N;

vector<ll> V;

ppvl solve(vector<ll> params, ll n)
{
	vector<ll> res1, res2;

	if (n == 2)
	{
		if ((params[0] + params[1]) % n == 0)
		{
			res1.push_back(params[0]);
			res1.push_back(params[1]);
			res2.push_back(params[2]);
		}
		else if ((params[1] + params[2]) % n == 0)
		{
			res1.push_back(params[1]);
			res1.push_back(params[2]);
			res2.push_back(params[0]);
		}
		else if ((params[0] + params[2]) % n == 0)
		{
			res1.push_back(params[0]);
			res1.push_back(params[2]);
			res2.push_back(params[1]);
		}

		return { res1, res2 };
	}

	vector<ll> tmp, ans[3];

	n >>= 1;

	for (ll i = 0; i < 2 * n - 1; i++)
		tmp.push_back(params[i]);

	ppvl T1 = solve(tmp, n);

	tmp.clear();

	for (ll i = 0; i < (ll)T1.x.size(); i++)
		ans[0].push_back(T1.x[i]);

	for (ll i = 0; i < (ll)T1.y.size(); i++)
		tmp.push_back(T1.y[i]);

	for (ll i = 2 * n - 1; i < 2 * n - 1 + n; i++)
		tmp.push_back(params[i]);

	ppvl T2 = solve(tmp, n);

	tmp.clear();

	for (ll i = 0; i < (ll)T2.x.size(); i++)
		ans[1].push_back(T2.x[i]);

	for (ll i = 0; i < (ll)T2.y.size(); i++)
		tmp.push_back(T2.y[i]);

	for (ll i = 2 * n - 1 + n; i < 2 * n - 1 + n + n; i++)
		tmp.push_back(params[i]);

	ppvl T3 = solve(tmp, n);

	tmp.clear();

	for (ll i = 0; i < (ll)T3.x.size(); i++)
		ans[2].push_back(T3.x[i]);

	for (ll i = 0; i < (ll)T3.y.size(); i++)
		tmp.push_back(T3.y[i]);

	ll L[3]{ 0 };

	for (ll i = 0; i < (ll)ans[0].size(); i++)
		L[0] += ans[0][i];
	for (ll i = 0; i < (ll)ans[1].size(); i++)
		L[1] += ans[1][i];
	for (ll i = 0; i < (ll)ans[2].size(); i++)
		L[2] += ans[2][i];

	n <<= 1;

	if ((L[0] + L[1]) % n == 0)
	{
		for (ll i = 0; i < (ll)ans[0].size(); i++)
			res1.push_back(ans[0][i]);
		for (ll i = 0; i < (ll)ans[1].size(); i++)
			res1.push_back(ans[1][i]);
		for (ll i = 0; i < (ll)ans[2].size(); i++)
			res2.push_back(ans[2][i]);
	}
	else if ((L[1] + L[2]) % n == 0)
	{
		for (ll i = 0; i < (ll)ans[1].size(); i++)
			res1.push_back(ans[1][i]);
		for (ll i = 0; i < (ll)ans[2].size(); i++)
			res1.push_back(ans[2][i]);
		for (ll i = 0; i < (ll)ans[0].size(); i++)
			res2.push_back(ans[0][i]);
	}
	else if ((L[0] + L[2]) % n == 0)
	{
		for (ll i = 0; i < (ll)ans[0].size(); i++)
			res1.push_back(ans[0][i]);
		for (ll i = 0; i < (ll)ans[2].size(); i++)
			res1.push_back(ans[2][i]);
		for (ll i = 0; i < (ll)ans[1].size(); i++)
			res2.push_back(ans[1][i]);
	}

	for (auto e : tmp)
		res2.push_back(e);

	return { res1, res2 };
}

int main()
{
	cin >> N;

	for (ll i = 0, a; i < (2 * N) - 1; i++)
	{
		cin >> a;
		V.push_back(a);
	}

	vl ans = solve(V, N).x;

	for (auto e : ans)
		cout << e << " ";
}