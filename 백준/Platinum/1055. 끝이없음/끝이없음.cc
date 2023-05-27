#include <bits/stdc++.h>
#define ll long long

using namespace std;

string S, A, cpy;

ll hei, L, R, cnt, alpha; // cnt는 달러의 개수

bool real_solve(ll x, ll roop, ll params)
{
	if (roop == 0)
	{
		cout << S[params - 1];
		return true;
	}

	ll bef = (x - alpha) / cnt, pre = 0;

	ll Idx = 0;

	for (ll i = 0; i < (ll)A.length(); i++)
	{
		pre = Idx;

		if (A[i] == '$')
		{
			Idx += bef;
			
			if (Idx >= params)
				return real_solve(bef, roop - 1, params - pre);
		}
		else
		{
			Idx += 1;

			if (Idx == params)
			{
				cout << A[i];
				return true;
			}
		}
	}

	return false;
}

void solve(ll params)
{
	ll start = (ll)S.length(), Idx = 1;

	ll nxt = start * cnt + alpha;

	while (nxt <= params && Idx < hei)
	{
		nxt = nxt * cnt + alpha;
		Idx++;
	} // pre는 구할 필요가 없는거다 그래서

	if (!real_solve(nxt, Idx, params))
		cout << "-";
}

int main()
{
	cin >> S;

	cin >> A;

	cin >> hei >> L >> R;

	for (auto e : A)
	{
		if (e == '$')
			cnt++;
		else
			cpy += e;
	}

	alpha = (ll)A.length() - cnt;

	if (cnt == 1)
	{
		ll max_size = alpha * hei + (ll)S.length();

		for (ll i = L; i <= R; i++)
		{
			if (i > max_size)
			{
				cout << '-';
				continue;
			}
			if (i >= 1 && i <= (ll)S.length())
				cout << S[i - 1];
			else
				cout << cpy[(i - (ll)S.length() - 1) % (ll)cpy.length()];
		}
		exit(0);
	}
	
	for (ll i = L; i <= R; i++)
		solve(i);
}