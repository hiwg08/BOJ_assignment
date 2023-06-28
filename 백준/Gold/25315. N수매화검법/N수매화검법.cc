#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pll pair<ll, ll>
#define f first
#define s second
#define MAX 3000

using namespace std;

typedef struct line
{
	pll a, b;
	ll score, Idx;
	line(pll _T1, pll _T2, ll _score)
	{
		a = _T1;
		b = _T2;
		score = _score;
	}
} line;

vector<line> V;

ll N, total;

ll ccw(pll a, pll b, pll c)
{
	ll tmp = ((b.f - a.f) * (c.s - a.s)) + ((a.s - b.s) * (c.f - a.f));

	if (tmp == 0)
		return 0;
	if (tmp > 0)
		return 1;
	return -1;
}

bool match_line(line L, line R)
{
	if ((ccw(L.a, L.b, R.a) * ccw(L.a, L.b, R.b) < 0) &&
		(ccw(R.a, R.b, L.a) * ccw(R.a, R.b, L.b) < 0))
	{
		return true;
	}
	return false;
}

bool cmp(line a, line b)
{
	return a.score < b.score;
}

int main()
{
	fastio;

	cin >> N;

	for (ll i = 0, a, b, c, d, e; i < N; i++)
	{
		cin >> a >> b >> c >> d >> e;
		line u({ a, b }, { c, d }, e);
		V.push_back(u);
	}

	sort(V.begin(), V.end(), cmp);

	for (ll i = 0; i < N; i++)	
	{
		ll cnt = 0;

		for (ll j = i + 1; j < N; j++)
		{
			if (match_line(V[i], V[j]))
				cnt++;
		}
		total += ((cnt + 1) * V[i].score);
	}

	cout << total;
}