// written by bliss08
// category : greedy + sorting
// core idea : mathmatical observation ➜ sort and choose numbers in order greedily.

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); 
#define ll long long

using namespace std;

ll N;

deque<ll> A, B;

vector<ll> double_plus, single_plus;

vector<ll> double_minus, single_minus;

vector<ll> dec_v, inc_v;

ll ans[300001]{ 0 };

ll tot = 0;

int main()
{
	fastio;

	cin >> N; A.resize(N); B.resize(N);

	ll Idx = -1;

	for (auto& ia : A)
	{
		cin >> ia;

		Idx++;

		if (Idx <= 1)
			continue;

		if (A[Idx - 2] < A[Idx - 1] && A[Idx - 1] < A[Idx])
		{
			inc_v.push_back(Idx - 1);
			continue;
		}

		if (A[Idx - 2] > A[Idx - 1] && A[Idx - 1] > A[Idx])
		{
			dec_v.push_back(Idx - 1);
			continue;
		}

		if (A[Idx - 2] > A[Idx - 1] && A[Idx - 1] < A[Idx])
		{
			double_minus.push_back(Idx - 1);
			continue;
		}

		if (A[Idx - 2] < A[Idx - 1] && A[Idx - 1] > A[Idx])
			double_plus.push_back(Idx - 1);
	}
	
	for (auto& ib : B)
		cin >> ib;


	if (A[0] > A[1])
		single_plus.push_back(0);
	else
		single_minus.push_back(0);

	if (A[N - 2] > A[N - 1])
		single_minus.push_back(N - 1);
	else
		single_plus.push_back(N - 1);

	sort(B.begin(), B.end());

	while (!double_plus.empty())
	{
		tot += 2 * B.back();
		ans[double_plus.back()] = B.back();
		double_plus.pop_back();
		B.pop_back();
	}

	while (!single_plus.empty())
	{
		tot += B.back();
		ans[single_plus.back()] = B.back();
		single_plus.pop_back();
		B.pop_back();
	}

	while (!double_minus.empty())
	{
		tot -= 2 * B.front();
		ans[double_minus.back()] = B.front();
		double_minus.pop_back();
		B.pop_front();
	}

	while (!single_minus.empty())
	{
		tot -= B.front();
		ans[single_minus.back()] = B.front();
		single_minus.pop_back();
		B.pop_front();
	}

	for (auto e : dec_v)
	{
		ans[e] = B.back();
		B.pop_back();
	}

	for (auto e : inc_v)
	{
		ans[e] = B.front();
		B.pop_front();
	}

	cout << tot << '\n';

	for (ll i = 0; i < N; i++)
		cout << ans[i] << " ";
}