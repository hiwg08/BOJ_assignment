#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, K, comp, total = INT_MIN;

ll word_bits[51]{ 0 };

char words[21]{ 'b', 'd', 'e', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'o', 'p', 'q', 'r', 's', 'u', 'v', 'w', 'x', 'y', 'z'};

bool Vis[21]{ 0 };

ll cToin(char c)
{
	return (ll)(c - 97);
}

void solve(ll Idx, ll Cnt, ll Bits)
{
	if (Cnt == K)
	{
		ll chk = 0;

		for (ll i = 0; i < N; i++)
		{
			if ((word_bits[i] & Bits) == word_bits[i])
				chk++;
		}

		total = max(total, chk);

		return;
	}
	for (ll i = Idx; i < 21; i++)
	{
		if (Vis[i])
			continue;
		Vis[i] = true;
		solve(i + 1, Cnt + 1, Bits | ((ll)1 << cToin(words[i])));
		Vis[i] = false;
	}
}

int main()
{
	cin >> N >> K;

	for (ll i = 0; i < N; i++)
	{
		string S; cin >> S;

		for (auto e : S)
			word_bits[i] |= ((ll)1 << cToin(e));
	}

	if (K <= 4)
	{
		cout << 0 << '\n';
		exit(0);
	}

	comp |= ((ll)1 << cToin('a'));
	comp |= ((ll)1 << cToin('n'));
	comp |= ((ll)1 << cToin('t'));
	comp |= ((ll)1 << cToin('i'));
	comp |= ((ll)1 << cToin('c'));

	K -= 5;

	solve(0, 0, comp);

	cout << total << '\n';
}