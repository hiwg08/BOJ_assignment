#include <bits/stdc++.h>
#define pii pair<int ,int>
#define x first
#define y second

using namespace std;

vector<pii> V;

int ans = 0, N;

int main() 
{
	cin >> N; V.resize(N);

	for (auto& iv : V)
		cin >> iv.x >> iv.y;

	sort(V.begin(), V.end(), [&](pii a, pii b) {
		return a.x + b.y > a.y + b.x;
	});

	ans = abs(V[N - 1].x - V[0].x) + abs(V[N - 1].y - V[0].y);
	
	sort(V.begin(), V.end(), [&](pii a, pii b) {
		return a.x + a.y > b.x + b.y;
	});

	ans = max(ans, abs(V[N - 1].x - V[0].x) + abs(V[N - 1].y - V[0].y));

	cout << ans;
}