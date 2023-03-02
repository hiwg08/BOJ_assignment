#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pob pop_back

using namespace std;

ll N, MAX = LLONG_MIN;

string S;

vector<ll> inte;

vector<char> oper;

ll ctoii(char c)
{
	return (ll)(c - 48);
}

ll calc(char a, char oper, char b)
{
	ll new_a = ctoii(a), new_b = ctoii(b);

	if (oper == '+')
		return new_a + new_b;

	if (oper == '-')
		return new_a - new_b;

	return new_a * new_b;
}

ll real_calc()
{
	ll total = 0;

	vector<ll> ans;

	ans.pb(inte[0]);

	for (ll i = 1; i < (ll)inte.size(); i++)
	{
		if (oper[i - 1] == '-')
			ans.pb(-inte[i]);
		if (oper[i - 1] == '+')
			ans.pb(inte[i]);
		if (oper[i - 1] == '*')
			ans.back() *= inte[i];
	}

	while (!ans.empty())
	{
		total += ans.back();
		ans.pob();
	}

	return total;
}

void solve(ll Idx)
{
	if (Idx >= N)
	{
		MAX = max(MAX, real_calc());

		return;
	}

	if (Idx <= N - 3)
	{
		ll ret = calc(S[Idx], S[Idx + 1], S[Idx + 2]);
		inte.pb(ret);
		
		if (Idx != N - 3) 
			oper.pb(S[Idx + 3]);

		solve(Idx + 4);

		inte.pob();

		if (Idx != N - 3)
			oper.pob();
	}

	inte.pb(ctoii(S[Idx]));

	if (Idx < N)
		oper.pb(S[Idx + 1]);

	solve(Idx + 2);

	inte.pob();

	if (Idx < N)
		oper.pob();
}

int main()
{
	cin >> N;

	cin >> S;

	solve(0);

	cout << MAX << '\n';
}