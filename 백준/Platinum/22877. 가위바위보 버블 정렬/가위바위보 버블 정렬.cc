#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

using namespace std;

ll N, T;

string S, ans;

bool compare(char a, char b)
{
	if (a == 'R' && b == 'S')
		return true;

	if (a == 'S' && b == 'P')
		return true;

	if (a == 'P' && b == 'R')
		return true;

	return false;
}

void solve()
{
	char c = '.';

	ll cnt = 0;


	for (ll i = 0; i < (ll)S.length(); i++)
	{
		if (c != S[i])
		{
			char tmp = S[i];
			
			if (c != '.')
			{	
				if (compare(c, S[i]))
				{
					tmp = S[i];
					ll ano_cnt = 0;

					while (tmp == S[i] && i < (ll)S.length())
					{
						ano_cnt++;
						i++;
					}
					i--;

					for (ll j = 0; j < cnt - T; j++)
						ans += c;
					for (ll j = 0; j < ano_cnt; j++)
						ans += tmp;

					cnt = min(T, cnt);

					tmp = c;
				}
				else
				{
					for (ll j = 0; j < cnt; j++)
						ans += c;
					cnt = 1;
				}
			}
			else
				cnt++;
			c = tmp;
		}
		else
			cnt++;

		if (i == (ll)S.length() - 1)
		{
			while ((ll)ans.length() < (ll)S.length())
				ans += c;
		}
	}
}

int main()
{
	cin >> N >> T;

	cin >> S;

	solve();

	cout << ans;
}