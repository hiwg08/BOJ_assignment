#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

using namespace std;

ll M, N, L, Ans;

vector<ll> S;

int main()
{
	fastio;

	cin >> M >> N >> L;

	S.resize(M);

	for (auto& iv : S)
		cin >> iv;

	sort(S.begin(), S.end());

	for (ll i = 0, ani_x, ani_y; i < N; i++)
	{
		cin >> ani_x >> ani_y;

		ll R_Idx = (ll)(lower_bound(S.begin(), S.end(), ani_x) - S.begin());

		ll L_Idx = R_Idx - 1;

		if (L_Idx == -1) L_Idx = R_Idx;

		if (R_Idx >= M) R_Idx = L_Idx;

		ll min_cost = min(abs(S[L_Idx] - ani_x) + ani_y, abs(S[R_Idx] - ani_x) + ani_y);

		if (L >= min_cost)
			Ans++;
	}

	cout << Ans << '\n';
}