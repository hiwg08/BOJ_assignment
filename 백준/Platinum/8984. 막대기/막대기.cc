#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(p) (p).begin(), (p).end()
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll N, L, total;

vector<pll> V;

vector<ll> up, down;

bool cmp(pll a, pll b)
{
	if (a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
} // 정렬 순서는 상관 없다. 일단 초기에는 구현을 편하게 하려고 y 좌표를 1순위, x 좌표를 2순위로 둔 것 뿐.

ll DP[2][100001]{ 0 };

// DP[1][k] : 현재 막대기의 y 좌표가 k일 때, y -> x 방향(현 그림 기준으로 올라가는 구조)으로 막대기가 구성되는 길이의 최댓값으로 정의
// DP[0][q] : 현재 막대기의 x 좌표가 q일 때, x -> y 방향(현 그림 기준으로 내려가는 구조)으로 막대기가 구성되는 길이의 최댓값으로 정의

int main()
{
	fastio;

	cin >> N >> L;

	for (ll i = 0, a, b; i < N; i++)
	{
		cin >> a >> b;
		V.push_back({ a, b });
		up.push_back(a);
		down.push_back(b);
	}

	sort(all(V), cmp);

	sort(all(up));
	
	sort(all(down));

	up.erase(unique(all(up)), up.end());

	down.erase(unique(all(down)), down.end()); // 좌표 압축 시 항상 중복되는 좌표들은 이 처럼 걸러줘야 한다.

	for (ll i = 0; i < N; i++)
	{
		ll ni = (ll)(lower_bound(all(up), V[i].x) - up.begin());
		ll nj = (ll)(lower_bound(all(down), V[i].y) - down.begin());
	
		ll height = abs(V[i].x - V[i].y) + L;

		ll px = DP[0][ni], py = DP[1][nj];

		DP[1][nj] = max(py, px + height); // 현재 막대기의 y -> x (1이므로), 즉 '올라가는' 방향에 대한 최댓값을 구하려면, 현재 막대기의 x 좌표를 확인한 후, 그 'x 좌표'에서 시작되는 막대기의 '내려가는' 방향에 대한 최댓값과 현 값을 비교해준다.
		DP[0][ni] = max(px, py + height); // 현재 막대기의 x -> y (0이므로), 즉 '내려가는' 방향에 대한 최댓값을 구하려면, 현재 막대기의 y 좌표를 확인한 후, 그 'y 좌표'에서 시작되는 막대기의 '올라가는' 방향에 대한 최댓값과 현 값을 비교해준다.

		total = max(total, max(DP[1][nj], DP[0][ni])); // DP[1][ni]로 실수로 코딩했었다. 주의하자.
	}

	cout << total;
}
