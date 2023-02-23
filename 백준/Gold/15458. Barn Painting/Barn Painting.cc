#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define MOD 1000000007
#define MAX 100000 + 1

using namespace std;

bool Vis[MAX]{ 0 };

ll N, K, Root, RGB[MAX]{ 0 };

vector<vector<ll>> Tree;

tuple<ll, ll, ll> DP[MAX];

tuple<ll, ll, ll> solve(ll Idx)
{
	tuple<ll, ll, ll>& ret = DP[Idx];

	Vis[Idx] = true;

	if (RGB[Idx] == 0) ret = { 1, 1, 1 };
	if (RGB[Idx] == 1) ret = { 1, 0, 0 };
	if (RGB[Idx] == 2) ret = { 0, 1, 0 };
	if (RGB[Idx] == 3) ret = { 0, 0, 1 };

	for (ll i = 0; i < (ll)Tree[Idx].size(); i++)
	{
		if (!Vis[Tree[Idx][i]])
		{
			tuple<ll, ll, ll> T1 = solve(Tree[Idx][i]);

			get<0>(ret) = (get<0>(ret) * (get<1>(T1) + get<2>(T1)) % MOD) % MOD;
			get<1>(ret) = (get<1>(ret) * (get<0>(T1) + get<2>(T1)) % MOD) % MOD;
			get<2>(ret) = (get<2>(ret) * (get<0>(T1) + get<1>(T1)) % MOD) % MOD;
		}
	}

	return ret;
}

void Input()
{
	fastio;

	cin >> N >> K;

	Tree.resize(N + 1);

	for (ll i = 0; i < N - 1; i++)
	{
		ll a, b; cin >> a >> b;
		Tree[a].push_back(b);
		Tree[b].push_back(a);
		Vis[b] = true;
	}

	for (ll i = 0; i < K; i++)
	{
		ll a, b; cin >> a >> b;
		RGB[a] = b;
	}

	for (int i = 1; i <= N; i++)
	{
		if (!Vis[i])
		{
			Root = i;
			break;
		}
	}

	memset(Vis, false, sizeof(Vis));
}

int main()
{
	Input();

	DP[Root] = solve(Root);
	
	cout << (((get<0>(DP[Root]) + get<1>(DP[Root])) % MOD) + get<2>(DP[Root])) % MOD << '\n';
}