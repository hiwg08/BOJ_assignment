#include <bits/stdc++.h>
#define pii pair<int, int>
#define s second
#define f first

using namespace std;

int N, DP[16][1 << 16]{ 0 };

vector<pair<int, pii>> V;

int solve(int Last, int Bit)
{
	int& ret = DP[Last][Bit];

	if (ret != -1) return ret;

	ret = 0;

	for (int i = 0; i < N; i++)
	{
		if ((!Bit) || (!(Bit & (1 << i)) && V[Last].s.s == V[i].s.f))
			ret = max(ret, solve(i, (Bit | (1 << i))) + V[i].f);
	}

	return ret;
}

int main()
{
	cin >> N;

	memset(DP, -1, sizeof(DP));

	for (int i = 0; i < N; i++)
	{
		string S; cin >> S;
		V.push_back({ (int)S.length(), {(int)S[0], (int)S[(int)S.length() - 1]}});
	}

	cout << solve(0, 0) << '\n';
}