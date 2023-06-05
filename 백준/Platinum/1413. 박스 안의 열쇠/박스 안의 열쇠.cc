#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, M, total;

ll fac_DP[30]{ 0 };

void get_fac()
{
	fac_DP[0] = 1;

	for (ll i = 1; i <= 20; i++)
		fac_DP[i] = fac_DP[i - 1] * i;
}

ll ret_fac(ll a, ll b)
{
	return fac_DP[a] / (fac_DP[b] * fac_DP[a - b]);
}

ll ret_repeat(ll a, ll b)
{
	ll q = a + b - 1, r = b;

	return fac_DP[q] / (fac_DP[r] * fac_DP[q - r]);
}

vector<ll> V;

void reconstruct(ll cnt, ll last, ll sum, ll upper)
{
	if (cnt == upper) // 이거 정렬할 필요도 없다.
	{
		ll info[21]{ 0 };

		for (auto e : V)
			info[e]++;

		ll ret = 1, space = 1;

		bool chk = false;

		for (ll i = 1; i <= 20; i++)
		{
			ll L = i, R = info[i];

			if (info[i] == 1)
				ret *= fac_DP[L - 1];

			else if (info[i] > 1)
			{
				ll first = L * R - 1;

				for (ll j = first; j >= L - 1; j -= L)
					ret *= ret_fac(j, L - 1);

				for (ll j = 0; j < R; j++)
					ret *= fac_DP[L - 1];
			}

			if (info[i] >= 1)
				chk = true;

			ret *= ret_repeat(space, L * R);

			space += L * R;
		}

		if (chk)
			total += ret;
		
		return;
	}

	if (cnt == upper - 1)
	{
		V.push_back(N - sum);
		reconstruct(cnt + 1, 1, sum, upper);
		V.pop_back();
		return;
	}

	ll limit = (N - sum) / (upper - cnt);

	for (ll i = last; i <= limit; i++)
	{
		V.push_back(i);
		reconstruct(cnt + 1, i, sum + i, upper);
		V.pop_back();
	}
}

void solve()
{
	for (ll bomb = 1; bomb <= M; bomb++)
	{
		ll remain = N - bomb;

		if (bomb == N)
			total += 1;
		else
			reconstruct(0, 1, 0, bomb);
	}
}

ll get_gcd(ll a, ll b)
{
	if (b == 0)
		return a;

	return get_gcd(b, a % b);
}

int main()
{
	cin >> N >> M;

	get_fac();

	solve();

	ll gcd = get_gcd(total, fac_DP[N]);

	cout << (total / gcd) << "/" << (fac_DP[N] / gcd);
}