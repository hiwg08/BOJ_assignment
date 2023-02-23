#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define MOD (ll)1000
#define vvll vector<vector<ll>>

using namespace std;

vvll Matrix;

ll N, B;

vvll matrix_mul(vvll pa1, vvll pa2)
{
	vvll temp; temp.resize(N);

	for (ll i = 0; i < N; i++)
	{
		for (ll j = 0; j < N; j++)
		{
			ll SUM = 0;
			for (ll k = 0; k < N; k++)
				SUM += (pa1[i][k] * pa2[k][j]) % MOD;
			temp[i].push_back(SUM % MOD);
		}
	}

	return temp;
}

vvll solve(vvll matr, ll B)
{
	if (B == 1)
		return matr;

	vvll temp = solve(matr, B / 2);

	vvll Ans = matrix_mul(temp, temp);

	if (B % 2 != 0)
		Ans = matrix_mul(Ans, matr);

	return Ans;
}

int main()
{
	fastio;

	cin >> N >> B;

	Matrix.resize(N);

	for (ll i = 0; i < N; i++)
	{
		Matrix[i].resize(N);

		for (auto& iv : Matrix[i])
		{
			cin >> iv;
			iv %= MOD;
		}
	}

	vvll Ans = solve(Matrix, B);

	for (ll i = 0; i < N; i++)
	{
		for (ll j = 0; j < N; j++)
			cout << Ans[i][j] << " ";
		cout << '\n';
	}
}