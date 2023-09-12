#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N;

string S;

vector<ll> J, O, I;

bool check(ll standard)
{
	vector<ll> upup;

	ll start = 0;

	ll IC = 0, JC = 0;

	for (ll i = (ll)I.size() - 1; i >= 0; i--)
	{
		ll Idx = (ll)(lower_bound(O.begin(), O.end() - start, I[i]) - O.begin()) - 1;

		if (Idx >= 0 && Idx < (ll)O.size())
		{
			upup.push_back(O[Idx]);

			if ((ll)upup.size() == standard)
			{
				IC = (ll)I.size() - i;
				break;
			}
				
			start = (ll)O.size() - Idx;
		}
	}

	if ((ll)upup.size() < standard)
		return false;


	for (ll i = 0; i < (ll)upup.size(); i++)
	{
		ll L = (ll)(lower_bound(I.begin(), I.end() - IC, upup[i]) - I.begin()) - 1;

		ll R = (ll)(lower_bound(J.begin(), J.end() - JC, upup[i]) - J.begin()) - 1;

		if ((L >= 0 && L < (ll)I.size()) && (R >= 0 && R < (ll)J.size()))
		{
			if (I[L] < J[R])
				JC = (ll)J.size() - R;
			else
				IC = (ll)I.size() - L;
		}
		else if ((L >= 0 && L < (ll)I.size()) && !(R >= 0 && R < (ll)J.size()))
			IC = (ll)I.size() - L;
		else if (!(L >= 0 && L < (ll)I.size()) && (R >= 0 && R < (ll)J.size()))
			JC = (ll)J.size() - R;
		else
			return false;
	}

	return true;
}

ll solve()
{
	ll lo = 0, hi = N + 1;

	while (lo + 1 < hi)
	{
		ll mid = (lo + hi) >> 1;

		check(mid) ? lo = mid : hi = mid;
	}

	return lo;
}

int main()
{
	cin >> N;

	cin >> S;

	for (ll i = 0; i < (ll)S.length(); i++)
	{ 
		if (S[i] == 'J')
			J.push_back(i);

		if (S[i] == 'I')
			I.push_back(i);

		if (S[i] == 'O')
			O.push_back(i);
	}

	cout << solve();
}