#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pii pair<int, int>
#define pb push_back
#define x first
#define y second

using namespace std;

int N, K, Interval, a, b, c, d, total_water, sink_water;

map<pii, int> M;

vector<pair<pii, int>> V;

int main()
{
	fastio;

	cin >> N; Interval = (N - 2) / 2;

	cin >> a >> b; 

	V.pb({ {-1, -1}, -1 });

	for (int i = 1; i <= Interval; i++)
	{
		cin >> a >> b >> c >> d;
		M[{a, b}] = i;
		V.pb({ {0, b}, c - a });
		total_water += b * (c - a);
	}

	cin >> a >> b; 

	cin >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> a >> b >> c >> d;
		int pre_inter = M[{a, b}];
		int min_height = V[pre_inter].x.y;

		sink_water += (V[pre_inter].x.y - V[pre_inter].x.x) * V[pre_inter].y;
		
		V[pre_inter].x.x = V[pre_inter].x.y;

		for (int j = pre_inter + 1; j <= Interval; j++)
		{
			min_height = min(min_height, V[j].x.y);

			if (V[j].x.x <= min_height)
			{
				sink_water += (min_height - V[j].x.x) * V[j].y;
				V[j].x.x = min_height;
			}
		}

		min_height = V[pre_inter].x.y;

		for (int j = pre_inter - 1; j >= 1; j--)
		{
			min_height = min(min_height, V[j].x.y);

			if (V[j].x.x <= min_height)
			{
				sink_water += (min_height - V[j].x.x) * V[j].y;
				V[j].x.x = min_height;
			}
		}
	}

	cout << total_water - sink_water << '\n';
}