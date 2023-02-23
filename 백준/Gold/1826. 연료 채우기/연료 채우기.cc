#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define f first
#define s second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

ll N, Dest, Oil;

vector<pll> V;

priority_queue<ll> PQ;

int main()
{
	fastio;

	cin >> N;

	for (ll i = 0, a, b; i < N; i++)
	{
		cin >> a >> b; V.push_back({ a, b });
	}

	cin >> Dest >> Oil;

	V.push_back({ Dest, -1 });

	sort(V.begin(), V.end());

	ll Ans = 0;

	bool CHK = true;

	for (ll i = 0; i < N + 1; i++)
	{
		while (!PQ.empty() && Oil < V[i].f)
		{
			Oil += PQ.top();
			Ans++;
			PQ.pop();
		}

		if (Oil < V[i].f)
		{
			CHK = false;
			break;
		}

		if (Oil >= Dest)
			break;

		PQ.push(V[i].s);
	}

	CHK ? cout << Ans << '\n' : cout << -1 << '\n';
}