#include <bits/stdc++.h>
#define ll long long
#define o (ll)1
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll N, ans = LLONG_MAX, total;

ll a1[20]{ 0 }, b1[20]{ 0 }, a2[20]{ 0 }, b2[20]{ 0 };

void solve_L(ll Idx, ll cnt, ll a_, ll b_, ll bits, vector<pll>& V1) // Idx는 a를 뽑는 놈의 개수이다.
// solve_L에는 a1
{
	if (cnt >= N / 2)
	{
		if (Idx == 0) // a를 다 썼을 때
			V1.push_back({ a_ - b_, bits });
		return;
	}

	if (Idx >= 1)
		solve_L(Idx - 1, cnt + 1, a_ + a1[cnt], b_, bits | (o << ((N / 2) - cnt - 1)), V1);

	solve_L(Idx, cnt + 1, a_, b_ + b1[cnt], bits, V1);
}

void solve_R(ll Idx, ll cnt, ll a_, ll b_, ll bits, vector<pll>& V2, vector<pll>& V3)
// solve_R에는 a2
{
	if (cnt >= N / 2)
	{
		if (Idx == 0) // a를 다 썼을 때
		{
			V2.push_back({ a_ - b_, bits });
			V3.push_back({ a_ - b_, bits });
		}
			
		return;
	}
	if (Idx >= 1)
		solve_R(Idx - 1, cnt + 1, a_ + a2[cnt], b_, bits | (o << ((N / 2) - cnt - 1)), V2, V3);

	solve_R(Idx, cnt + 1, a_, b_ + b2[cnt], bits, V2, V3);
}

bool cmp(pll a, pll b)
{
	if (a.x == b.x)
		return a.y > b.y;
	return a.x < b.x;
}

int main()
{
	cin >> N;

	for (ll i = 0; i < N / 2; i++)
		cin >> a1[i];
	for (ll i = 0; i < N / 2; i++)
		cin >> a2[i];

	for (ll i = 0; i < N / 2; i++)
		cin >> b1[i];
	for (ll i = 0; i < N / 2; i++)
		cin >> b2[i];

	for (ll i = 0; i <= N / 2; i++)
	{
		vector<pll> V1, V2, V3;
		solve_L(i, 0, 0, 0, 0, V1);
		solve_R((N / 2) - i, 0, 0, 0, 0, V2, V3);

		sort(V2.begin(), V2.end(), cmp);
		sort(V3.begin(), V3.end());

		for (auto e : V1)
		{
			ll rev = -e.x;

			ll Idx = (ll)(lower_bound(V2.begin(), V2.end(), make_pair(rev, LLONG_MIN)) - V2.begin());

			if (Idx >= 0 && Idx < (ll)V2.size()) // 오른쪽을 확인
			{
				ll comp = abs(e.x + V2[Idx].x);

				if (ans > comp)
				{
					ans = comp;

					total = e.y << (N / 2);
					total |= V2[Idx].y;
				}
				else if (ans == comp)
				{
					ll T1 = e.y << (N / 2);
					T1 |= V2[Idx].y;

					if (T1 > total)
						total = T1;
				}
			}

			if (Idx - 1 >= 0 && Idx - 1 < (ll)V2.size()) // 왼쪽을 확인
			{
				ll comp = abs(e.x + V3[Idx - 1].x);

				if (ans > comp)
				{
					ans = comp;

					total = e.y << (N / 2);
					total |= V3[Idx - 1].y;
				}
				else if (ans == comp)
				{
					ll T1 = e.y << (N / 2);
					T1 |= V3[Idx - 1].y;

					if (T1 > total)
						total = T1;
				}
			}
		}
	}

	for (ll i = N - 1; i >= 0; i--)
	{
		if (total & (o << i))
			cout << 1 << " ";
		else
			cout << 2 << " ";
	}
}