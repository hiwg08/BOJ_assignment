#include <bits/stdc++.h>
#define ll long long
#define MOD (ll)(1e9 + 7)
#define MAX (ll)(15000000)

using namespace std;

ll N, M, total = 1;

ll vis[MAX + 1]{ 0 };

ll comp[MAX + 1]{ 0 };

vector<ll> V;

vector<ll> V1[980000], V2[980000];

void add_mod(ll& ret, ll params)
{
	ret += params;
	ret %= MOD;
}

void sub_mod(ll& ret, ll params)
{
	ret = (ret - params + MOD) % MOD;
}

void mul_mod(ll& ret, ll params)
{
	ret *= params;
	ret %= MOD;
}

ll dev_con(ll params, ll pows)
{
	if (pows == 0)
		return 1;

	if (pows % 2 != 0)
		return ((params % MOD) * (dev_con(params, pows - 1) % MOD)) % MOD;

	ll T = dev_con(params, pows / 2) % MOD;

	return (T *T) % MOD;
}

void eratos()
{
	for (ll i = 2; i <= MAX; i++)
		vis[i] = i;

	for (ll i = 2; i <= (ll)sqrt(MAX); i++)
	{
		if (vis[i] != i)
			continue;

		for (ll j = i * i; j <= MAX; j += i)
		{
			if (vis[j] == j)
				vis[j] = i;
		}
	}

	ll Idx = 0;

	for (ll i = 2; i <= MAX; i++)
	{
		if (vis[i] == i)
		{
			V.push_back(i);

			ll tmp = 0;

			for (ll j = i;; j *= i)
			{
				tmp++;

				if (j > MAX)
				{
					tmp--;
					break;
				}
			}

			V1[Idx].resize(tmp + 1);
			V2[Idx].resize(tmp + 1);

			comp[i] = Idx++;
		}
	}
}

void factor(ll n, bool flag) // 큰 쪽이 V1으로, 작은 쪽이 V2로
{
	ll chk = -1;

	ll cnt = 0;

	while (n > 1)
	{
		if (chk == -1)
			chk = vis[n];

		else
		{
			if (chk != vis[n])
			{
				if (flag)
					add_mod(V2[comp[chk]][cnt], 1);

				chk = vis[n];
				cnt = 0;
			}
		}

		cnt++;

		add_mod(V1[comp[chk]][cnt], 1);

		n /= vis[n];
	}

	if (flag)
		add_mod(V2[comp[chk]][cnt], 1);
}

void recomp()
{
	for (ll i = 0; i < (ll)V.size(); i++)
	{
		ll pre_sum = 0;

		ll bef = -1;

		for (ll inn = 1; inn < (ll)V1[i].size(); inn++)
		{
			if (inn == 1)
				bef = V1[i][inn];

			else
			{
				ll ww = bef;

				sub_mod(ww, V1[i][inn]);

				ll diff = ww;

				ll ins1 = V1[i][inn];

				mul_mod(ins1, inn);

				add_mod(ins1, pre_sum);

				ll ins2 = diff;

				mul_mod(ins2, inn - 1);

				add_mod(ins1, ins2);

				bef = V1[i][inn];

				V1[i][inn] = ins1;

				add_mod(pre_sum, ins2);
			}
		}
	}
}

void fir()
{
	for (ll i = 2; i <= N; i++)
		factor(i, i <= M);

	recomp();
}

int main() // N을 크게 유지
{
	eratos();

 	cin >> N >> M;

	if (N < M)
		swap(N, M);

	fir();

	for (ll i = 0; i < (ll)V.size(); i++)
	{
		for (ll j = 1; j < (ll)V2[i].size(); j++) // 여기서 V 사용
		{
			if (V2[i][j] == 0)
				break;
		
			ll tmp = V1[i][j];

			tmp *= V2[i][j];

			//mul_mod(tmp, V2[i][j]);

			mul_mod(total, dev_con(V[i], tmp));
		}
	}

	cout << total;
}