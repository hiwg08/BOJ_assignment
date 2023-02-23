#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int N, Ans;

vector<pii> V;

bool cmp(pii a, pii b)
{
	if (a.x == b.x)
		return a.y > b.y;
	return a.x < b.x;
}

int main()
{
	fastio;

	cin >> N; V.resize(N);

	for (auto& iv : V)
		cin >> iv.x >> iv.y;

	sort(V.begin(), V.end(), cmp);

	int hi = V[0].y;
	
	Ans = hi - V[0].x;

	for (int i = 1; i < N; i++)
	{
		if (V[i].y < hi)
			continue;

		if (V[i].x > hi)
			Ans += V[i].y - V[i].x;
		else
			Ans += V[i].y - hi;

		hi = V[i].y;
	}

	cout << Ans << '\n';
}