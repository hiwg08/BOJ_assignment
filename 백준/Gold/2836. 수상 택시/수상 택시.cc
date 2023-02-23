#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pll pair<ll, ll>
#define f first
#define s second

using namespace std;

ll N, M, Ans;

vector<pll> V;

bool cmp(pll a, pll b)
{
	if (a.f == b.f)
		return a.s > b.s;
	return a.f < b.f;
}

int main()
{
	fastio;

	cin >> N >> M;

	for (ll i = 0, a, b; i < N; i++)
	{
		cin >> a >> b;
		if (b < a)
			V.push_back({ b, a });
	}

	Ans = M;

	sort(V.begin(), V.end(), cmp);

	ll Start = -1, End = -1;

	for (auto params : V)
	{
		if (Start == -1)
			Start = params.f, End = params.s;

		else
		{
			if (End < params.f)
			{
				Ans += 2 * (End - Start);
				Start = params.f, End = params.s;

			}
			else
			{
				if (End < params.s)
					End = params.s;
			}
		}
	}

	Ans += 2 * (End - Start);

	cout << Ans << '\n';
}