#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

using namespace std;

ll A, B;

string sta[]{ "A+=A", "A+=B", "B+=A", "B+=B" };

vector<ll> V;

void solve()
{
	while (A != B)
	{
		ll T1 = A & (-A);
		ll T2 = B & (-B);

		ll flag = T1 > T2 ? 3 : 0;

		for (ll i = 0; i < (ll)(log2(max(T1, T2) / min(T1, T2))); i++)
			V.push_back(flag);
		
		A >>= (ll)(log2(T1)), B >>= (ll)(log2(T2));
	
		if (A < B)
		{
			B += A;
			V.push_back(2);
		}
		else if (A > B)
		{
			A += B;
			V.push_back(1);
		}
	}
}

int main()
{
	fastio;

	cin >> A >> B;

	solve();

	cout << (ll)V.size() << '\n';
	
	for (auto e : V)
		cout << sta[e] << '\n';
}