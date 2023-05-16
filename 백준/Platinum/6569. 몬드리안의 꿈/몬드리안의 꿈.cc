#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define o (ll)1

using namespace std;

ll DP[12][1 << 12]{ 0 };

ll H, W, total;

void reconstruct(ll Idx, ll start, ll bit, ll standard) // start가 H를 넘길 때까지 반복. 이 함수는 나머지 인덱스에도 똑같이 적용시킨다.
{
	DP[Idx][bit] += standard;

	if (start >= H - 1)
		return;

	for (ll i = start; i < H - 1; i++)
	{
		ll L = bit & (o << i);
		ll R = bit & (o << (i + 1));

		if (L == 0 && R == 0)
		{
			ll e = bit | (o << i);
			e |= (o << (i + 1));
			reconstruct(Idx, i + 2, e, standard);
		}
	}
}

void init()
{
	memset(DP, 0, sizeof(DP));

	total = 0;

	reconstruct(0, 0, 0, 1);

	for (ll i = 1; i < W; i++)
	{
		for (ll j = 0; j <= (o << H) - 1; j++) // 그니까 얘는 전 상태의 bit라는 거지?
		{
			ll rev = (o << H) - 1 - j;

			reconstruct(i, 0, rev, DP[i - 1][j]);
		}
	}

	total = DP[W - 1][(o << H) - 1];
}

int main()
{
	fastio;

	while (true)
	{
		cin >> H >> W;

		if (H == 0 && W == 0)
			break;

		init();

		cout << total << '\n';
	}
}