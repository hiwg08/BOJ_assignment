#include <bits/stdc++.h>
#define pb push_back
#define pob pop_back
#define ll long long

using namespace std;

ll N, oper[4]{ 0 }, sum, MAX = INT_MIN, MIN = INT_MAX;

vector<ll> V;

vector<char> coll;

char d[]{ '+', '-', '*', '/' };

void calculate()
{
	ll total = 0;

	vector<ll> result;

	result.pb(V[0]);

	for (ll i = 1, j = 0; i < (ll)V.size(); i++, j++) // j가 연산자 인덱스
	{
		if (coll[j] == '+')
			result.pb(V[i]);

		if (coll[j] == '-')
			result.pb(-V[i]);

		if (coll[j] == '*')
			result.back() *= V[i];

		if (coll[j] == '/')
			result.back() /= V[i];
	}

	while (!result.empty())
	{
		total += result.back();
		result.pob();
	}

	MAX = max(MAX, total);
	MIN = min(MIN, total);
}

void solve(ll Idx)
{
	if (Idx == 0)
	{
		calculate();
		return;
	}
	for (ll i = 0; i < 4; i++)
	{
		if (oper[i])
		{
			oper[i]--;
			coll.pb(d[i]);
			solve(Idx - 1);
			oper[i]++;
			coll.pob();
		}
	}
}

int main()
{
	cin >> N; V.resize(N);

	for (auto& iv : V)
		cin >> iv;

	for (ll i = 0; i < 4; i++)
	{
		cin >> oper[i];
		sum += oper[i];
	}

	solve(sum);

	cout << MAX << '\n' << MIN << '\n';
}