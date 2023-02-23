#include <bits/stdc++.h>
#include <unordered_map>
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll N, Ans, assign[26]{ 0 };

bool no_zero[26]{ 0 };

unordered_map<ll, ll> UM;

vector<string> S_V;

vector<pll> V;

bool cmp(pll a, pll b) 
{
	return a.y > b.y;
}

ll dev_con(ll params, ll pows)
{
	if (pows == 0)
		return 1;

	if (pows % 2 != 0)
		return params * dev_con(params, pows - 1);

	ll T = dev_con(params, pows / 2);

	return T * T;
}

int main()
{
	cin >> N;

	for (ll i = 0; i < N; i++)
	{
		string S; cin >> S;

		S_V.push_back(S);

		no_zero[(ll)(S[0] - 'A')] = true;

		for (ll j = 0; j < (ll)S.length(); j++)
			UM[(ll)(S[j] - 'A')] += dev_con(10, (ll)S.length() - j - 1);	
	}

	for (auto& e : UM)
		V.push_back({ e.x, e.y }); 

	sort(V.begin(), V.end(), cmp);

	if ((ll)V.size() == 10)
	{
		vector<pll> tmp_V;

		while (no_zero[V.back().x])
		{
			tmp_V.push_back(V.back());
			V.pop_back();
		}

		pll T1 = V.back();
		V.pop_back();

		while (!tmp_V.empty())
		{
			V.push_back(tmp_V.back());
			tmp_V.pop_back();
		}

		V.push_back(T1);
	}

	ll Idx = 10;

	for (auto& e : V)
		assign[e.x] = --Idx;

	for (auto& e : S_V)
	{
		for (int i = 0; i < (ll)e.length(); i++)
			Ans += assign[(ll)(e[i] - 'A')] * dev_con(10, (ll)e.length() - i - 1);
	}

	cout << Ans << '\n';
}