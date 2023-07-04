#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, K;

vector<ll> cnt[36];

string S;

vector<string> VS;

bool chk_z[36]{ 0 };

ll total[60];

bool cmp(vector<ll> a, vector<ll> b)
{
	for (ll i = 59; i >= 0; i--)
	{
		if (a[i] == b[i])
			continue;
		return a[i] > b[i];
	}

	return false;
}

ll conv_c(char c)
{
	if (c >= '0' && c <= '9')
		return (ll)(c - 48);
	return (ll)(c - 55);
}

char conv_l(ll l)
{
	if (l >= 0 && l <= 9)
		return (char)(l + 48);
	return (char)(l + 55);
}

void input()
{
	cin >> N;

	for (ll i = 0; i < 36; i++)
	{
		cnt[i].resize(61, 0);
		cnt[i][60] = i;
	}

	for (ll i = 0; i < N; i++)
	{
		cin >> S;

		VS.push_back(S);

		for (ll j = (ll)(S.length()) - 1, zari = 0; j >= 0; j--, zari++)
			cnt[conv_c(S[j])][zari] += (35 - conv_c(S[j]));
	}

	cin >> K;

	for (ll i = 0; i < 36; i++)
	{
		ll carry = 0;

		for (ll j = 0; j < 60; j++)
		{
			ll T1 = cnt[i][j] + carry;

			cnt[i][j] = T1 % 36;

			carry = T1 / 36;
		}
	}
}

int main()
{
	input();

	sort(cnt, cnt + 36, cmp);

	for (ll i = 0, nu = K; (i < 36 && nu > 0); i++, nu--)
		chk_z[cnt[i][60]] = true;

	for (auto e : VS)
	{
		for (ll j = (ll)e.length() - 1, zari = 0; j >= 0; j--, zari++)
		{
			if (chk_z[conv_c(e[j])])
				total[zari] += 35;
			else
				total[zari] += conv_c(e[j]);
		}
	}

	ll carry = 0;

	for (ll j = 0; j < 60; j++)
	{
		ll T1 = total[j] + carry;

		total[j] = T1 % 36;

		carry = T1 / 36;
	}

	bool chk = false;

	for (ll j = 59; j >= 0; j--)
	{
		if (total[j] != 0)
			chk = true;

		if (chk)
			cout << conv_l(total[j]);
	}

	if (!chk)
		cout << 0;
}