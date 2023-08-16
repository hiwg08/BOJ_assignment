#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll N, K, total, w_fir = -1, w_sec = -1, cmd;

string S;

pll ans[2000001];

void precomp()
{
	ans[total] = { 1, N };
	
	if (S[0] == 'T' && S[N - 1] == 'T')
	{
		if (w_fir == -1)
			return;

		ll nu = 0;

		ll lo = w_fir + 1, hi = w_fir + 1;

		for (ll j = w_fir; j >= 0; j--)
		{
			bool flag = true;

			if (S[j] == 'W')
			{
				flag = true;
				nu += 1;
			}

			else
			{
				flag = false;
				nu += 2;
			}

			ans[nu] = { lo, hi };

			if (!flag)
				ans[nu - 1] = { lo, hi - 1 };
			lo--;
		}

		nu = 0;

		lo = w_fir + 1, hi = w_fir + 1;

		for (ll j = w_fir; j < N; j++)
		{
			bool flag = true;

			if (S[j] == 'W')
				nu += 1;

			else
			{
				flag = false;
				nu += 2;
			}

			ans[nu] = { lo, hi };

			if (!flag)
				ans[nu - 1] = { lo + 1, hi };
			hi++;
		}

		for (ll j = w_fir, tmp = 2; j > 0; j--, tmp += 2)
			ans[nu + tmp] = { j, N };

		nu = 0;

		lo = w_sec + 1, hi = w_sec + 1;

		for (ll j = w_sec; j >= 0; j--)
		{
			bool flag = true;

			if (S[j] == 'W')
			{
				flag = true;
				nu += 1;
			}

			else
			{
				flag = false;
				nu += 2;
			}

			ans[nu] = { lo, hi };

			if (!flag)
				ans[nu - 1] = { lo, hi - 1 };
			lo--;
		}

		ll cpy = nu;

		nu = 0;

		lo = w_sec + 1, hi = w_sec + 1;

		for (ll j = w_sec; j < N; j++)
		{
			bool flag = true;

			if (S[j] == 'W')
				nu += 1;

			else
			{
				flag = false;
				nu += 2;
			}

			ans[nu] = { lo, hi };

			if (!flag)
				ans[nu - 1] = { lo + 1, hi };
			hi++;
		}

		for (ll j = w_sec + 1, tmp = 2; j < N; j++, tmp += 2)
			ans[cpy + tmp] = { 1, j + 1 };
	}
	else // 여기서부터는 모든 숫자가 다 됨
	{
		if (S[0] == 'W')
		{
			ll nu = 0;

			ll lo = 1, hi = 1;

			bool flag = true;
			
			for (ll i = 0; i < N; i++)
			{
				if (S[i] == 'W')
				{
					flag = true;
					nu += 1;
				}
					
				else 
				{
					flag = false;
					nu += 2;
				}

				ans[nu] = { lo, hi };

				if (!flag)
					ans[nu - 1] = { lo + 1, hi };
				hi++;
			}
		}
		else
		{
			ll nu = 0;

			ll lo = N, hi = N;

			bool flag = true;

			for (ll i = N - 1; i >= 0; i--)
			{
				if (S[i] == 'W')
				{
					flag = true;
					nu += 1;
				}

				else
				{
					flag = false;
					nu += 2;
				}

				ans[nu] = { lo, hi };

				if (!flag)
					ans[nu - 1] = { lo, hi - 1 };
				lo--;
			}
		}
	}
}

int main()
{
	fastio;

	cin >> N >> K;

	cin >> S;

	N = (ll)S.length();

	for (ll i = 0, rev = N - 1; i < N; i++, rev--)
	{
		S[i] == 'T' ? total += 2 : total += 1;

		if (S[i] == 'W' && w_fir == -1)
			w_fir = i;

		if (S[rev] == 'W' && w_sec == -1)
			w_sec = rev;
	}

	precomp();

	/*for (ll i = 1; i <= total; i++)
		cout << i << " -> " << ans[i].x << " " << ans[i].y << '\n';*/

	while (K--)
	{
		cin >> cmd;

		if (w_fir == -1)
		{
			if (total < cmd)
				cout << "NIE" << '\n';
			else
			{
				if (cmd % 2 != 0)
					cout << "NIE" << '\n';
				else
					cout << 1 << " " << (cmd / 2) << '\n';
			}
		}
		else
		{
			if (ans[cmd].x == 0 && ans[cmd].y == 0)
				cout << "NIE" << '\n';
			else
				cout << ans[cmd].x << " " << ans[cmd].y << '\n';
		}
	}
}