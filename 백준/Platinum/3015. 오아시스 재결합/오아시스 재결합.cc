#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pll pair<ll, ll>
#define f first
#define s second

using namespace std;

ll N, Ans;

stack<pll> S;

int main()
{
	fastio;

	cin >> N;

	for (ll i = 0, Q; i < N; i++)
	{
		cin >> Q;

		ll Cnt = 0;

		while (!S.empty() && S.top().f < Q)
		{
			Ans += S.top().s;
			S.pop();
			Cnt++;
		}

		Ans += Cnt;

		if (!S.empty())
			S.top().f > Q ? S.push({ Q, 1 }) : S.push({ Q, S.top().s + 1 });
		else
			S.push({ Q, 0 });
	}

	while (!S.empty())
	{
		Ans += S.top().s;
		S.pop();
	}

	cout << Ans << '\n';
}