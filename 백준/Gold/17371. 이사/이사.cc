#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pii pair<int, int>
#define ld long double
#define x first
#define y second

using namespace std;

int N;

ld ans_x, ans_y;

ld dis_min = LDBL_MAX;

vector<pii> V;

ld calc_dis(pii a, pii b)
{
	return (((ld)a.x - (ld)b.x) * ((ld)a.x - (ld)b.x)) + (((ld)a.y - (ld)b.y) * ((ld)a.y - (ld)b.y));
}

int main()
{
	fastio;

	cin >> N; V.resize(N);

	for (auto& iv : V)
		cin >> iv.x >> iv.y;

	ans_x = (ld)V[0].x, ans_y = (ld)V[0].y;

	for (int i = 0; i < N; i++)
	{
		ld seg_max = LDBL_MIN;

		for (int j = 0; j < N; j++)
		{
			if (i == j)
				continue;
			seg_max = max(seg_max, calc_dis(V[i], V[j]));
		}

		if (dis_min > seg_max)
		{
			dis_min = seg_max;
			ans_x = (ld)V[i].x, ans_y = (ld)V[i].y;
		}
	}

	cout.precision(6);

	cout << fixed << ans_x << " " << ans_y << '\n';
}