#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N, a, b;

int U[101]{ 0 }, D[101]{ 0 };

int a_U[101]{ 0 }, a_D[101]{ 0 };

int solve()
{
	int val = INT_MIN;

	U[a]++, D[b]++;

	for (int i = 1; i <= 100; i++) a_U[i] = U[i], a_D[i] = D[i];

	int lo = 1, hi = 100;

	while (true)
	{
		while (a_U[lo] == 0 && lo <= 100)
			lo++;

		while (a_D[hi] == 0 && hi >= 1)
			hi--;

		if (lo > 100 && hi < 1)
			break;

		int L = a_U[lo], R = a_D[hi];

		val = max(val, lo + hi);

		if (L > R)
		{
			a_U[lo] -= R;
			hi--;
		}
		else if (L == R)
		{
			a_U[lo] -= R;
			a_D[hi] -= R;
			lo++, hi--;
		}
		else
		{
			a_D[hi] -= L;
			lo++;
		}
	}

	return val;
}

int main()
{
	fastio;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;

		cout << solve() << '\n';
	}
}