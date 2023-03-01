#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll N, MAX = LLONG_MIN;

vector<vector<pair<ll, char>>> VS[11];

vector<pair<pll, ll>> V;

bool Vis[11]{ 0 };

ll dx[]{ 0, 1, 0, 1 };
ll dy[]{ 4, 4, 3, 3 };

void rotate_0(ll Idx, ll stand, vector<vector<pair<ll, char>>>& ret)
{
	ll stand_x = dx[stand], stand_y = dy[stand];

	for (ll i = stand_y, k = 4, ry = 3; k > 0; k--, i--, ry--)
	{
		for (ll j = stand_x, xk = 0, rx = 0; xk < 4; xk++, j++, rx++)
		{
			ll new_x = rx, new_y = ry;
			
			ll quantity = VS[Idx][new_x][new_y].x;
			char element = VS[Idx][new_x][new_y].y;
			
			if (ret[j][i].x + quantity < 0)
				ret[j][i].x = 0;
			else if (ret[j][i].x + quantity > 9)
				ret[j][i].x = 9;
			else
				ret[j][i].x += quantity;


			if (element != 'W')
				ret[j][i].y = element;
		}
	}
}

void rotate_90(ll Idx, ll stand, vector<vector<pair<ll, char>>>& ret)
{
	ll stand_x = dx[stand], stand_y = dy[stand];

	for (ll i = stand_y, k = 4, ry = 3; k > 0; k--, i--, ry--)
	{
		for (ll j = stand_x, xk = 0, rx = 0; xk < 4; xk++, j++, rx++)
		{
			ll new_x = 3 - ry, new_y = rx;

			//cout << new_x << " " << new_y << " / ";

			ll quantity = VS[Idx][new_x][new_y].x;
			char element = VS[Idx][new_x][new_y].y;

			if (ret[j][i].x + quantity < 0)
				ret[j][i].x = 0;
			else if (ret[j][i].x + quantity > 9)
				ret[j][i].x = 9;
			else
				ret[j][i].x += quantity;


			if (element != 'W')
				ret[j][i].y = element;
		}
		//cout << '\n';
	}

}

void rotate_180(ll Idx, ll stand, vector<vector<pair<ll, char>>>& ret)
{
	ll stand_x = dx[stand], stand_y = dy[stand];

	for (ll i = stand_y, k = 4, ry = 3; k > 0; k--, i--, ry--)
	{
		for (ll j = stand_x, xk = 0, rx = 0; xk < 4; xk++, j++, rx++)
		{
			ll new_x = 3 - rx, new_y = 3 - ry;

			//cout << new_x << " " << new_y << " / ";

			ll quantity = VS[Idx][new_x][new_y].x;
			char element = VS[Idx][new_x][new_y].y;

			if (ret[j][i].x + quantity < 0)
				ret[j][i].x = 0;
			else if (ret[j][i].x + quantity > 9)
				ret[j][i].x = 9;
			else
				ret[j][i].x += quantity;

			if (element != 'W')
				ret[j][i].y = element;
		}
		//cout << '\n';
	}
}

void rotate_270(ll Idx, ll stand, vector<vector<pair<ll, char>>>& ret)
{
	ll stand_x = dx[stand], stand_y = dy[stand];

	for (ll i = stand_y, k = 4, ry = 3; k > 0; k--, i--, ry--)
	{
		for (ll j = stand_x, xk = 0, rx = 0; xk < 4; xk++, j++, rx++)
		{
			ll new_x = ry, new_y = 3 - rx;

			//cout << new_x << " " << new_y << " / ";

			ll quantity = VS[Idx][new_x][new_y].x;
			char element = VS[Idx][new_x][new_y].y;

			if (ret[j][i].x + quantity < 0)
				ret[j][i].x = 0;
			else if (ret[j][i].x + quantity > 9)
				ret[j][i].x = 9;
			else
				ret[j][i].x += quantity;


			if (element != 'W')
				ret[j][i].y = element;
		}
		//	cout << '\n';
	}
}

ll calc()
{
	ll total = 0;

	vector<vector<pair<ll, char>>> ans = vector<vector<pair<ll, char>>>(5, vector<pair<ll, char>>(5, { 0, 'W' }));

	for (auto& e : V)
	{
		//cout << e.x.x << ", " << e.x.y << " / " << e.y << '\n';
		if (e.y == 0)
			rotate_0(e.x.x, e.x.y, ans);
		if (e.y == 1)
			rotate_90(e.x.x, e.x.y, ans);
		if (e.y == 2)
			rotate_180(e.x.x, e.x.y, ans);
		if (e.y == 3)
			rotate_270(e.x.x, e.x.y, ans);

		/*for (ll i = 4; i >= 0; i--)
		{
			for (ll j = 0; j < 5; j++)
			{
				cout << ans[j][i].x << ans[j][i].y << " ";
			}
			cout << '\n';
		}
		cout << '\n';*/
	}

	for (ll i = 0; i < 5; i++)
	{
		for (ll j = 0; j < 5; j++)
		{
			if (ans[i][j].y == 'R')
				total += 7 * ans[i][j].x;

			if (ans[i][j].y == 'B')
				total += 5 * ans[i][j].x;

			if (ans[i][j].y == 'G')
				total += 3 * ans[i][j].x;

			if (ans[i][j].y == 'Y')
				total += 2 * ans[i][j].x;
		}
	}

	return total;
}

// {{ x, y }, z} x가 번호, y가 기준 행/렬, z가 회전

void solve(ll cnt)
{
	if (cnt == 3)
	{
		MAX = max(MAX, calc());

		return;
	}

	for (ll i = 0; i < N; i++)
	{
		if (!Vis[i])
		{
			Vis[i] = true;
			for (ll j = 0; j < 4; j++)
			{
				for (ll k = 0; k < 4; k++)
				{
					V.push_back({ { i, j }, k });
					solve(cnt + 1);
					V.pop_back();
				}
			}
			Vis[i] = false;
		}
	}
}

void Input()
{
	cin >> N;

	for (ll i = 0; i < N; i++)
	{
		VS[i] = vector<vector<pair<ll, char>>>(4, vector<pair<ll, char>>(4, { 0, '.' }));

		for (ll j = 3; j >= 0; j--)
		{
			for (ll k = 0, a; k < 4; k++)
			{
				cin >> a;
				VS[i][k][j].x = a;
			}
		}

		for (ll j = 3; j >= 0; j--)
		{
			for (ll k = 0; k < 4; k++)
			{
				char c; cin >> c;
				VS[i][k][j].y = c;
			}
		}

		/*for (ll j = 3; j >= 0; j--)
		{
			for (ll k = 0; k < 4; k++)
			{
				cout << VS[i][k][j] << " ";
			}
			cout << '\n';
		}

		cout << '\n' << '\n';*/
	}

}

int main()
{
	Input();

    solve(0);

	cout << MAX << '\n';
}