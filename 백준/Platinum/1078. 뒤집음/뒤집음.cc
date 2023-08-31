// sol : number_theory, prefix_sum
// core idea : to narrow possible range of D

#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll D;

vector<ll> V, ans;

deque<ll> dq;

ll pre_sum[21]{ 0 };

bool calc(ll pre_i)
{
	ll ori = 0, cha = 0, inc = 2;

	ll Idx = (ll)dq.size() - 1;

	for (ll i = 0; i <= 9; i++)
	{
		ll T = V[0] * i;

		if (T % 10 == dq[Idx])
		{
			ori += T;
			cha += T;
			Idx--;
			cha /= 10;
			ans.push_back(i);
			break;
		}
	}

	for (ll i = 1, mul = 10; i < (ll)V.size(); i++, mul *= 10)
	{
		for (ll j = -9; j <= 9; j++)
		{
			ll T = (V[i] * j) / mul;

			ll cpy = cha + T;

			if (cpy % 10 == dq[Idx])
			{
				ll L = ori + (V[i] * j) - (pre_sum[pre_i] - pre_sum[inc]);
				ll R = ori + (V[i] * j) + (pre_sum[pre_i] - pre_sum[inc]);

				if (L <= D && D <= R)
				{
					ori += (V[i] * j);
					cha += T;
					cha /= 10;
					Idx--;
					inc++;
					ans.push_back(j);
					break;
				}
			}
		}
	}

	return (ori == D);
}

void solve(ll params, ll u)
{
	V.clear();

	ans.clear();

	memset(pre_sum, 0, sizeof(pre_sum));

	ll ni = 100, Idx = 1;

	while (params != 0)
	{
		V.push_back(params);

		pre_sum[Idx] = pre_sum[Idx - 1] + (params * 9);

		Idx++;

		params = (params / ni) * (ni / 10);

		ni *= 10;
	}

	Idx--;

	if (calc(Idx))
	{
		ll total[21]{ 0 };

		ll lo = 0, hi = u;

		for (ll i = 0; i < (ll)ans.size(); i++)
		{
			if (i == 0)
			{
				if (ans[i] == 0)
					total[lo++] = 1, total[hi--] = 1;
				else
				{
					if (ans[i] > 0)
						total[lo++] = ans[i], total[hi--] = 0;
					else
						total[lo++] = 0, total[hi--] = -ans[i];
				}
			}
			else
			{
				if (ans[i] > 0)
					total[lo++] = ans[i], total[hi--] = 0;
				else
					total[lo++] = 0, total[hi--] = -ans[i];
			}
		}

		for (ll i = 0; i <= u; i++)
			cout << total[i];

		exit(0);
	}
}

void input()
{
	cin >> D;

	ll N = D;

	while (N != 0)
	{
		dq.push_front(N % 10);
		N /= 10;
	}
}

int main()
{
	input();

	if (D % 9 != 0)
	{
		cout << -1;
		exit(0);
	}

	for (ll i = 1, Idx = 9; i <= 18; i++, Idx = (Idx * 10) + 9)
		solve(Idx, i);

	cout << -1;
}