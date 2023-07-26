#include <bits/stdc++.h>
#define ll long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

ll N, ans;

ll Arr[300001]{ 0 }, nu[300001]{ 0 };

string S, sfa = "";

vector<ll> V;

void precomp()
{
	char flag = S[0];

	ll maxi = Arr[0], Idx = 0;

	for (ll i = 1; i < (ll)S.length(); i++)
	{
		if (flag != S[i])
		{
			sfa += flag;
			flag = S[i];
			nu[Idx++] = maxi;
			maxi = Arr[i];
			continue;
		}
		maxi = max(maxi, Arr[i]);
	}

	nu[Idx++] = maxi;
	sfa += flag;
}

void solve()
{
	ll cnt = 0;

	for (ll i = 2; i < (ll)sfa.length(); i++)
	{
		V.push_back(nu[i - 1]);
		
		if (i % 2 == 0)
			cnt++;
	}

	sort(V.begin(), V.end());

	while (cnt--)
	{
		ans += V.back();
		V.pop_back();
	}
}

int main()
{
	fastio;

	cin >> N;

	cin >> S;

	for (ll i = 0; i < N; i++)
		cin >> Arr[i];

	precomp();

	solve();

	cout << ans;
}