#include <bits/stdc++.h>
#define ll long long
#define x first
#define y second

using namespace std;

ll N;

vector<tuple<ll, ll, ll>> V;

ll A[501]{ 0 }, B[501]{ 0 };

vector<pair<ll, char>> ans;



void sol_col()
{
	vector<tuple<ll, ll, ll>> dat[2][501];

	for (ll i = 0; i < N; i++)
	{
		A[i] = i + 1;
		B[i] = get<1>(V[i]);
	}

	ll L = -1, R = -1;

	bool flag = false;

	for (ll i = 0; i < N; i++)
	{
		auto& [ni, nj, nk] = V[i];

		if (A[i] > nj)
		{
			flag = false;
			break;
		}
		else if (A[i] < nj)
		{
			flag = true;
			break;
		}
	}

	for (ll i = 0; i < N; i++)
	{
		auto& [ni, nj, nk] = V[i];

		if (A[i] > nj) // 오른 방향 이동
		{
			if (!flag)
			{
				R++;
				flag = true;
			}
			
			dat[1][R].push_back({ A[i], nj, nk });
		}
		else if (A[i] < nj)
		{
			if (flag)
			{
				L++;
				flag = false;
			}

			dat[0][L].push_back({ A[i], nj, nk });
		}
	}

	for (ll i = 0; i <= L; i++) // dat[0]
	{
		for (ll j = 0; j < (ll)dat[0][i].size(); j++)
		{
			auto& [ni, nj, nk] = dat[0][i][j];

			for (ll k = 0; k < abs(ni - nj); k++)
				ans.push_back({ nk, 'L' });
		}
	}
	for (ll i = 0; i <= R; i++) // dat[1]
	{
		for (ll j = (ll)dat[1][i].size() - 1; j >= 0; j--)
		{
			auto& [ni, nj, nk] = dat[1][i][j];

			for (ll k = 0; k < abs(ni - nj); k++)
				ans.push_back({ nk, 'R' });
		}
	}
}

void sol_row()
{
	vector<tuple<ll, ll, ll>> dat[2][501];

	for (ll i = 0; i < N; i++)
	{
		A[i] = i + 1;
		B[i] = get<0>(V[i]);
	}

	ll U = -1, D = -1;

	bool flag = false;

	for (ll i = 0; i < N; i++)
	{
		auto& [ni, nj, nk] = V[i];

		if (A[i] > ni)
		{
			flag = false;
			break;
		}
		else if (A[i] < ni)
		{
			flag = true;
			break;
		}
	}

	for (ll i = 0; i < N; i++)
	{
		auto& [ni, nj, nk] = V[i];

		if (A[i] > ni) // 아랫 방향 이동
		{
			if (!flag)
			{
				D++;
				flag = true;
			}

			dat[1][D].push_back({ A[i], ni, nk });
		}
		else if (A[i] < ni) // 윗 방향 이동
		{
			if (flag)
			{
				U++;
				flag = false;
			}

			dat[0][U].push_back({ A[i], ni, nk });
		}
	}

	for (ll i = 0; i <= U; i++) // dat[0]
	{
		for (ll j = 0; j < (ll)dat[0][i].size(); j++)
		{
			auto& [ni, nj, nk] = dat[0][i][j];

			for (ll k = 0; k < abs(ni - nj); k++)
				ans.push_back({ nk, 'U' });
		}
	}
	for (ll i = 0; i <= D; i++) // dat[1]
	{
		for (ll j = (ll)dat[1][i].size() - 1; j >= 0; j--)
		{
			auto& [ni, nj, nk] = dat[1][i][j];

			for (ll k = 0; k < abs(ni - nj); k++)
				ans.push_back({ nk, 'D' });
		}
	}
}

int main()
{
	cin >> N; V.resize(N);

	for (ll i = 0; i < N; i++)
	{
		auto& [ni, nj, nk] = V[i];
		cin >> ni >> nj;
		nk = i + 1;
	}

	sort(V.begin(), V.end(), [&](tuple<ll, ll, ll> a, tuple<ll, ll, ll> b){
		return get<1>(a) < get<1>(b);
	});

	sol_col();

	sort(V.begin(), V.end(), [&](tuple<ll, ll, ll> a, tuple<ll, ll, ll> b) {
		return get<0>(a) < get<0>(b);
	});

	sol_row();

	cout << (ll)ans.size() << '\n';

	for (auto e : ans)
		cout << e.first << " " << e.second << '\n';
}