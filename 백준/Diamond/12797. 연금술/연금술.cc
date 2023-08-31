#include <bits/stdc++.h>
#include <random>
#define ll long long
#define MOD (ll)(1e9 + 7)
#define vl vector<ll>
#define vvl vector<vl>

using namespace std;

ll ipow(ll x, ll p) {
	ll ret = 1, piv = x;
	while (p) {
		if (p & 1) ret = ret * piv % MOD;
		piv = piv * piv % MOD;
		p >>= 1;
	}
	return ret;
}
vl berlekamp_massey(vl x) {
	vl ls, cur;
	ll lf, ld;
	for (ll i = 0; i < (ll)x.size(); i++) {
		ll t = 0;
		for (ll j = 0; j < (ll)cur.size(); j++) {
			t = (t + 1ll * x[i - j - 1] * cur[j]) % MOD;
		}
		if ((t - x[i]) % MOD == 0) continue;
		if (cur.empty()) {
			cur.resize(i + 1);
			lf = i;
			ld = (t - x[i]) % MOD;
			continue;
		}
		ll k = -(x[i] - t) * ipow(ld, MOD - 2) % MOD;
		vl c(i - lf - 1);
		c.push_back(k);
		for (auto& j : ls) c.push_back(-j * k % MOD);
		if ((ll)c.size() < (ll)cur.size()) c.resize((ll)cur.size());
		for (ll j = 0; j < (ll)cur.size(); j++) {
			c[j] = (c[j] + cur[j]) % MOD;
		}
		if (i - lf + (ll)ls.size() >= (ll)cur.size()) {
			tie(ls, lf, ld) = make_tuple(cur, i, (t - x[i]) % MOD);
		}
		cur = c;
	}
	for (auto& i : cur) i = (i % MOD + MOD) % MOD;
	return cur;
}
ll get_nth(vl rec, vl dp, ll n) {
	ll m = rec.size();
	vl s(m), t(m);
	s[0] = 1;
	if (m != 1) t[1] = 1;
	else t[0] = rec[0];
	auto mul = [&rec](vl v, vl w) {
		ll m = (ll)v.size();
		vl t(2 * m);
		for (ll j = 0; j < m; j++) {
			for (ll k = 0; k < m; k++) {
				t[j + k] += 1ll * v[j] * w[k] % MOD;
				if (t[j + k] >= MOD) t[j + k] -= MOD;
			}
		}
		for (ll j = 2 * m - 1; j >= m; j--) {
			for (ll k = 1; k <= m; k++) {
				t[j - k] += 1ll * t[j] * rec[k - 1] % MOD;
				if (t[j - k] >= MOD) t[j - k] -= MOD;
			}
		}
		t.resize(m);
		return t;
	};
	while (n) {
		if (n & 1) s = mul(s, t);
		t = mul(t, t);
		n >>= 1;
	}
	ll ret = 0;
	for (ll i = 0; i < m; i++) ret += 1ll * s[i] * dp[i] % MOD;
	return ret % MOD;
}
ll guess_nth_term(vl x, ll n) {
	if (n < (ll)x.size()) return x[n];
	vl v = berlekamp_massey(x);
	if (v.empty()) return 0;
	return get_nth(v, x, n);
}

ll N, M;

ll Arr[1001]{ 0 };

ll DP[4001][1001]{ 0 };

void mul_mod(ll& ret, ll params)
{
	ret *= params;
	ret %= MOD;
}

void add_mod(ll& ret, ll params)
{
	ret += params;
	ret %= MOD;
}

ll dev_con(ll params, ll pows)
{
	if (pows == 0)
		return 1;

	if ((pows & 1) == 1)
	{
		ll T1 = dev_con(params, pows - 1);

		mul_mod(T1, params);

		return T1;
	}

	ll T1 = dev_con(params, pows >> 1);

	mul_mod(T1, T1);

	return T1;
}

void solve()
{
	if (M - 1 < 0)
		return;

	for (ll i = 0; i < M; i++)
		DP[1][i] = Arr[M - 1];

	bool flag = false;

	ll fir = 0;

	for (ll i = 2; i <= 4000; i++)
	{
		ll diff = M - 1;

		for (ll j = 0; j < M; j++)
		{
			if (j == 0)
			{
				DP[i][j] = Arr[M - 1];
				mul_mod(DP[i][j], DP[i - 1][j]);
			}
			else
			{
				DP[i][j] = DP[i][j - 1];
				ll Q = Arr[diff - j];
				mul_mod(Q, DP[i - 1][j]);
				add_mod(DP[i][j], Q);
			}
		}

		if (i == N + 1)
		{
			fir = DP[i][M - 1];
			flag = true;
			break;
		}
	}

	if (flag)
	{
		ll Q = dev_con(Arr[M - 1], MOD - 2);

		mul_mod(fir, Q);

		cout << fir;

		exit(0);
	}		

	vl V;

	for (ll i = 0; i <= 4000; i++)
		V.push_back(DP[i][M - 1]);

	ll ret = guess_nth_term(V, N + 1);

	ll Q = dev_con(Arr[M - 1], MOD - 2);

	mul_mod(ret, Q);

	cout << ret;
}

int main()
{
	cin >> N >> M;

	for (ll i = 0; i < M; i++)
		cin >> Arr[i];

	solve();
}