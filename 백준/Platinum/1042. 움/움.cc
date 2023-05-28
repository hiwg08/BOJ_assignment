#include <bits/stdc++.h>
#define ll long long
#define MOD (ll)(1e9 + 7)

using namespace std;

string S;

ll M, size_to;

ll cnt = 0, ano_cnt = 0;

map<string, ll> opti;

map<string, ll> ss;

string sta[51];

ll DP[2501]{ 0 };

void add_mod(ll& ret, ll params)
{
	ret += params;
	ret %= MOD;
}

ll solve(ll Idx)
{
	if (Idx >= size_to)
		return 0;

	ll& ret = DP[Idx];

	if (ret != -1)
		return ret;

	ret = 0;

	ll Arr[51]{ 0 };

	bool chk[51]{ 0 };

	for (ll i = Idx; i < size_to; i++)
	{
		// 현재 문자는 S[i]이다.
		for (ll j = 0; j < M; j++)
		{
			ll pre = Arr[j];

			if (pre >= 3)
				continue;

			if (sta[j][pre] == S[i])
			{
				Arr[j]++;

				if (Arr[j] == 3)
				{
					if (!chk[opti[sta[j]]])
					{
						chk[opti[sta[j]]] = true;

						add_mod(ret, solve(i + 1));
						add_mod(ret, 1);
					}
				}
			}
		}
	}

	return ret;
}

int main()
{
	cin >> S;

	cin >> M;

	size_to = (ll)S.length();

	for (ll i = 0; i < M; i++)
	{
		string a, b; cin >> a >> b;

		if (ss.find(b) == ss.end())
		{
			cnt++;
			ss[b] = cnt;
		}
		opti[a] = ss[b];
		sta[i] = a;
	}

	memset(DP, -1, sizeof(DP));

	cout << solve(0);
}