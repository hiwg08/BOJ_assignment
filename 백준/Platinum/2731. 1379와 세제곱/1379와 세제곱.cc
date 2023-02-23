#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll T, N;

string S;

void calc_rem(ll& remain, ll nxt, ll size)
{
	ll L = 0, R = nxt;

	ll pows = (ll)pow(10, size), rev_pows = 10;

	while (pows > 1)
	{
		ll pi = (R % rev_pows) / (rev_pows / 10);

		ll tmp = (remain * pi) % pows;

		L += (tmp * (rev_pows / 10));

		R -= pi;

		pows /= 10, rev_pows *= 10;
	}

	L %= (ll)pow(10, size);

	remain = L;
}

void solve(ll Idx, ll num)
{
	if (Idx >= (ll)S.size())
	{
		cout << num << '\n';
		return;
	}

	ll pows = (ll)pow(10, Idx);

	ll n_pows = pows * 10;

	for (ll i = 0; i <= 9; i++)
	{
		ll nxt = num + (pows * i);

		ll remain = nxt;

		calc_rem(remain, nxt, Idx + 1); calc_rem(remain, nxt, Idx + 1);

		if (remain == N % n_pows)
			solve(Idx + 1, nxt);
	}
}

int main()
{
	cin >> T;

	while (T--)
	{
		cin >> N;

		S = to_string(N);

		reverse(S.begin(), S.end());

		solve(0, 0);
	}
}