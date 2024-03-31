#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll N, M, standard = -1, accu = 0, repeat = 0, tot = LLONG_MAX;

vector<pll> V;

int main() // sol : greedy + sorting 
{
	fastio;

	cin >> N >> M; V.resize(N);

	for (auto& iv : V)
		cin >> iv.x >> iv.y;

	sort(V.begin(), V.end(), [&](auto a, auto b) {
		if (a.y == b.y)
			return a.x > b.x;
		return a.y < b.y;
	}); // 가격이 최우선. 가격이 같으면 무게가 높은 순서로 배치. 

	for (ll i = 0; i < N; i++)
	{
		if (standard != V[i].y)
		{
			standard = V[i].y;
			repeat = 0;
		}

		repeat++;
		accu += V[i].x;
		
		if (accu >= M)
			tot = min(tot, repeat * V[i].y);
	}

	if (tot == LLONG_MAX)
		tot = -1;

	cout << tot;

	return 0;
}