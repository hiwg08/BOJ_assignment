#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll L, R, cnt, total;

ll DP[51]{ 0 };

void precomp()
{
	DP[2] = 1;

	for (ll i = 3; i <= 50; i++)
	{
		if (i % 2 != 0)
			DP[i] = 2;
		else
		{
			for (ll j = 2; j < i; j++)
			{
				if (i % j != 0)
				{
					DP[i] = DP[j] + 1;
					break;
				}
			}
		}
	}
}

ll get_gcd(ll a, ll b)
{
	if (b == 0)
		return a;
	return get_gcd(b, a % b);
}

ll get_new_L(ll ori, ll basu)
{
	ll nxt = basu * (ori / basu);

	if (nxt < ori)
		nxt += basu;

	return nxt;
}

ll get_new_R(ll ori, ll basu)
{
	return basu * (ori / basu);
}

void solve()
{
	ll bef = 1, Idx = 2;

	while (cnt > 0)
	{
		while (true)
		{
			ll nxt = (bef * Idx) / (get_gcd(bef, Idx));

			if (bef != nxt)
			{
				bef = nxt;
				break;
			}

			Idx++;
		}

		ll new_L = get_new_L(L, bef);
		ll new_R = get_new_R(R, bef);

		ll sub_cnt = (new_R / bef) - (new_L / bef) + 1;

		ll remain = cnt - sub_cnt;

		total += (DP[Idx] + 1) * remain;

		cnt = sub_cnt;

		L = new_L, R = new_R;
		// nxt의 배수를 제외한 모든 녀석들을 제거.
		
		Idx++;

		// 마지막은 갱신
	}
}

int main()
{
	cin >> L >> R;

	cnt = R - L + 1;

	precomp();

	solve();

	cout << total;
}