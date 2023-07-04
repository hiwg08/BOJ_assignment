#include <bits/stdc++.h>
#define ll long long
#define o (ll)1
#define pll pair<ll, ll>
#define pls pair<ll, string>
#define x first
#define y second

using namespace std;

ll N;

ll DP[13][1 << 13]{ 0 };

pls comp[13][13];

pll trace[13][1 << 13];

vector<string> V;

bool cmp(string a, string b)
{
	return (ll)a.length() < (ll)b.length();
}

void pruning()
{
	vector<string> tmp;

	sort(V.begin(), V.end(), cmp);

	for (ll i = 0; i < (ll)V.size(); i++)
	{
		bool chk = true;

		for (ll j = i + 1; j < (ll)V.size(); j++)
		{
			if (V[j].find(V[i]) != string::npos)
			{
				chk = false;
				break;
			}
		}

		if (chk)
			tmp.push_back(V[i]);
	}

	V = tmp;

	N = (ll)V.size();
}

pls get_length(string bef, string pos)
{
	ll ret_l = 0;
	string ret_s = "";

	for (ll outer = (ll)bef.size() - 1; outer >= 0; outer--)
	{
		ll cnt = 0;

		bool chk = true;

		for (ll last_pos = outer, curr = 0; (last_pos < (ll)bef.size() && curr < (ll)pos.size()); last_pos++, curr++)
		{
			if (bef[last_pos] == pos[curr])
				cnt++;
			else
			{
				chk = false;
				break;
			}
		}

		if (chk)
			ret_l = max(ret_l, cnt);
	}

	for (ll q = ret_l; q < (ll)pos.length(); q++)
		ret_s += pos[q];

	return { ret_l, ret_s };
}

void check_mini()
{
	for (ll i = 0; i < (ll)V.size(); i++) // V[i] --> V[j] 순으로 문자열을 붙일 때
	{
		for (ll j = 0; j < (ll)V.size(); j++)
		{
			if (i == j)
				continue;

			comp[i][j] = get_length(V[i], V[j]);
		}
	}
}

ll solve(ll pos, ll bits)
{
	if ((ll)__builtin_popcount(bits) == N)
		return (ll)V[pos].length();

	ll& ret = DP[pos][bits];

	if (ret != -1)
		return ret;

	ret = LLONG_MAX;

	string c_s = "";

	if (bits == 0)
	{
		for (ll i = 0; i < N; i++)
		{
			ll T1 = solve(i, bits | o << i);

			if (ret > T1)
			{
				c_s = V[i], ret = T1;
				trace[pos][bits] = { i, bits | o << i };
			}
			else if (ret == T1)
			{
				if (c_s > V[i])
				{
					c_s = V[i];
					trace[pos][bits] = { i, bits | o << i };
				}
			}
		}
	}

	else
	{
		for (ll i = 0; i < N; i++) // i가 다음에 붙일 것, pos가 이전 거
		{
			if (i == pos || (bits & (o << i)))
				continue;

			pls Z1 = comp[pos][i];

			ll T1 = solve(i, bits | o << i);

			if (ret > T1 + (ll)V[pos].length() - Z1.x)
			{
				c_s = Z1.y, ret = T1 + (ll)V[pos].length() - Z1.x;
				trace[pos][bits] = { i, bits | o << i };
			}

			else if (ret == T1 + (ll)V[pos].length() - Z1.x)
			{
				if (c_s > Z1.y)
				{
					c_s = Z1.y;
					trace[pos][bits] = { i, bits | o << i };
				}
			}
		}
	}

	return ret;
	// 그게 아닌 경우
}

void reconstruct(ll pos, ll bits)
{
	if (N == (ll)__builtin_popcount(bits))
		return;

	pll R = trace[pos][bits];

	if (bits == 0)
		cout << V[R.x];
	else
	{
		pls T1 = comp[pos][R.x];

		for (ll i = T1.x; i < (ll)V[R.x].length(); i++)
			cout << V[R.x][i];
	}

	reconstruct(R.x, R.y);
}

int main()
{
	cin >> N;

	for (ll i = 0; i < N; i++)
	{
		string S; cin >> S;
		V.push_back(S);
	}

	pruning();

	check_mini();

	memset(DP, -1, sizeof(DP));

	solve(0, 0);

	reconstruct(0, 0);
}