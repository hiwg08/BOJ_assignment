#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define o (ll)1

using namespace std;

ll DP[1001][20]{ 0 };

ll T, N;

void carve_dp(ll standard, ll pos)
{
	ll quo = pos / 60, remain = pos % 60;

	DP[standard][quo] |= (o << remain);
}

ll solve(ll standard, ll pos, bool flag)
{
	ll ret = 0;

	ll L = pos + 1, R = N;

	ll quo_L = L / 60, remain_L = L % 60;

	ll quo_R = R / 60, remain_R = R % 60;

	if (flag)
	{
		if (quo_L == quo_R)
		{
			ll comp1 = (DP[standard][quo_L] >> remain_L) & ((o << (remain_R - remain_L + 1)) - 1);

			ll comp2 = (DP[pos][quo_L] >> remain_L) & ((o << (remain_R - remain_L + 1)) - 1);

			ll res = comp1 & comp2; // and 연산을 취해준다.

			ret += (ll)(__builtin_popcountll(res));
		}
		else
		{
			ll comp1 = (DP[standard][quo_L] >> remain_L) & ((o << (59 - remain_L + 1)) - 1);

			ll comp2 = (DP[pos][quo_L] >> remain_L) & ((o << (59 - remain_L + 1)) - 1);

			ll res = comp1 & comp2; // and 연산을 취해준다.

			ret += (ll)(__builtin_popcountll(res));
			// 여기서 첫 빳다

			for (ll i = quo_L + 1; i <= quo_R - 1; i++)
				ret += (ll)(__builtin_popcountll(DP[standard][i] & DP[pos][i]));

			comp1 = (DP[standard][quo_R]) & ((o << (remain_R + 1)) - 1);

			comp2 = (DP[pos][quo_R]) & ((o << (remain_R + 1)) - 1);

			res = comp1 & comp2; // and 연산을 취해준다.

			ret += (ll)(__builtin_popcountll(res));
		}
	}
	else
	{
		if (quo_L == quo_R)
		{
			ll comp1 = (DP[standard][quo_L] >> remain_L) & ((o << (remain_R - remain_L + 1)) - 1);

			ll comp2 = (DP[pos][quo_L] >> remain_L) & ((o << (remain_R - remain_L + 1)) - 1);

			ll res = comp1 & comp2; // and 연산을 취해준다.

			ll another = comp1 ^ comp2;

			ll zero_cnt = (remain_R - remain_L + 1) - (ll)(__builtin_popcountll(another)), one_cnt = (ll)(__builtin_popcountll(res));

			ret += zero_cnt - one_cnt;
		}
		else
		{
			ll comp1 = (DP[standard][quo_L] >> remain_L) & ((o << (59 - remain_L + 1)) - 1);

			ll comp2 = (DP[pos][quo_L] >> remain_L) & ((o << (59 - remain_L + 1)) - 1);

			ll res = comp1 & comp2; // and 연산을 취해준다.

			ll another = comp1 ^ comp2;

			ll zero_cnt = (59 - remain_L + 1) - (ll)(__builtin_popcountll(another)), one_cnt = (ll)(__builtin_popcountll(res));

			ret += zero_cnt - one_cnt;

			// 여기서 첫 빳다

			for (ll i = quo_L + 1; i <= quo_R - 1; i++)
			{
				zero_cnt = 60 - (ll)(__builtin_popcountll(DP[standard][i] ^ DP[pos][i]));
				one_cnt = (ll)(__builtin_popcountll(DP[standard][i] & DP[pos][i]));

				ret += zero_cnt - one_cnt;
			}

			comp1 = (DP[standard][quo_R]) & ((o << (remain_R + 1)) - 1);

			comp2 = (DP[pos][quo_R]) & ((o << (remain_R + 1)) - 1);

			res = comp1 & comp2; // and 연산을 취해준다.

			another = comp1 ^ comp2;

			zero_cnt = (remain_R + 1) - (ll)(__builtin_popcountll(another)), one_cnt = (ll)(__builtin_popcountll(res));

			ret += zero_cnt - one_cnt;
		}
	}

	return ret;
}

// fir를 기준으로 두고, pos + 1 ~ N까지를 확인해주면 된다.
// 그리고 반 드 시 비교 대상으로 fir + 1를 기준, pos + 1 ~ N까지를 추가 대상으로 남겨두자.

void input()
{
	cin >> N;

	for (ll ou = 1; ou < N; ou++)
	{
		for (ll inn = ou + 1; inn <= N; inn++)
		{
			ll a; cin >> a;

			if (a == 1)
				carve_dp(ou, inn);

			// a가 1일 때, 얘를 비트마스크로 새겨야 한다.
		}
	}
}

int main()
{
	fastio;

	cin >> T;

	while (T--)
	{
		memset(DP, 0, sizeof(DP));

		ll ans = 0;

		input();

 		for (ll fir = 1; fir < N; fir++)
		{
			for (ll sec = fir + 1; sec < N; sec++)
			{
				ll quo = sec / 60, remain = sec % 60;

				ll comp = DP[fir][quo] & (o << remain);

				ans += solve(fir, sec, comp);
			}
		}

		cout << ans << '\n';
	}
}