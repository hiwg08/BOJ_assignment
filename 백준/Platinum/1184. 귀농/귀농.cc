#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int N, total;

int Arr[51][51]{ 0 };

int pre_ori[51][51]{ 0 };

int pre_res[51][51]{ 0 };

int pre_ori_f[51][51]{ 0 };

int pre_res_f[51][51]{ 0 };

bool is_range(int px, int py)
{
	return !(px < 1 || py < 1 || px >= N + 1 || py >= N + 1);
}

int ret_ori(int ax, int ay, int bx, int by)
{
	return pre_ori_f[bx][by] - pre_ori_f[ax - 1][by] - pre_ori_f[bx][ay - 1] + pre_ori_f[ax - 1][ay - 1];
}

int ret_res(int ax, int ay, int bx, int by)
{
	return pre_res_f[bx][by] - pre_res_f[ax - 1][by] - pre_res_f[bx][ay + 1] + pre_res_f[ax - 1][ay + 1];
}

vector<int> monge_1(pii p) 
{
	vector<int> ans;

	int ni = p.x, nj = p.y;

	while (is_range(ni, nj))
	{
		int ti = ni, tj = nj;

		ans.push_back(ret_ori(ti, tj, p.x, p.y));

		while (true)
		{
			tj--;

			if (!is_range(ti, tj))
				break;

			ans.push_back(ret_ori(ti, tj, p.x, p.y));
		}
		
		ti = ni, tj = nj;

		while (true)
		{
			ti--;

			if (!is_range(ti, tj))
				break;

			ans.push_back(ret_ori(ti, tj, p.x, p.y));
		}

		ni--, nj--;
	}

	return ans;
}
vector<int> monge_2(pii p)
{
	vector<int> ans;

	int ni = p.x, nj = p.y;

	while (is_range(ni, nj))
	{
		int ti = ni, tj = nj;

		ans.push_back(ret_res(ti, tj, p.x, p.y));

		while (true)
		{
			tj++;

			if (!is_range(ti, tj))
				break;

			ans.push_back(ret_res(ti, tj, p.x, p.y));
		}

		ti = ni, tj = nj;

		while (true)
		{
			ti--;

			if (!is_range(ti, tj))
				break;

			ans.push_back(ret_res(ti, tj, p.x, p.y));
		}

		ni--, nj++;
	}

	return ans;
}
vector<int> monge_3(pii p)
{
	vector<int> ans;

	int ni = p.x, nj = p.y;

	while (is_range(ni, nj))
	{
		int ti = ni, tj = nj;

		ans.push_back(ret_res(p.x, p.y, ti, tj));

		while (true)
		{
			tj--;

			if (!is_range(ti, tj))
				break;

			ans.push_back(ret_res(p.x, p.y, ti, tj));
		}

		ti = ni, tj = nj;

		while (true)
		{
			ti++;

			if (!is_range(ti, tj))
				break;

			ans.push_back(ret_res(p.x, p.y, ti, tj));
		}

		ni++, nj--;
	}

	return ans;

}
vector<int> monge_4(pii p)
{
	vector<int> ans;

	int ni = p.x, nj = p.y;

	while (is_range(ni, nj))
	{
		int ti = ni, tj = nj;

		ans.push_back(ret_ori(p.x, p.y, ti, tj));

		while (true)
		{
			tj++;

			if (!is_range(ti, tj))
				break;

			ans.push_back(ret_ori(p.x, p.y, ti, tj));
		}

		ti = ni, tj = nj;

		while (true)
		{
			ti++;

			if (!is_range(ti, tj))
				break;

			ans.push_back(ret_ori(p.x, p.y, ti, tj));
		}

		ni++, nj++;
	}

	return ans;
}

void solve()
{
	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = 1; j <= N - 1; j++)
		{
			pii T1 = { i, j }, T2 = { i, j + 1 }, T3 = { i + 1, j }, T4 = { i + 1, j + 1 };
			
			vector<int> V1 = monge_1(T1);
			vector<int> V2 = monge_2(T2);
			vector<int> V3 = monge_3(T3);
			vector<int> V4 = monge_4(T4);

			sort(V4.begin(), V4.end());

			sort(V3.begin(), V3.end());

			for (auto e : V1) // V4
				total += (int)(lower_bound(V4.begin(), V4.end(), e + 1) - V4.begin()) - (int)(lower_bound(V4.begin(), V4.end(), e) - V4.begin());

			for (auto e : V2) // V3
				total += (int)(lower_bound(V3.begin(), V3.end(), e + 1) - V3.begin()) - (int)(lower_bound(V3.begin(), V3.end(), e) - V3.begin());

		}
	}
}

void Input()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			cin >> Arr[i][j];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			pre_ori[i][j] = pre_ori[i][j - 1] + Arr[i][j];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = N; j >= 1; j--)
			pre_res[i][j] = pre_res[i][j + 1] + Arr[i][j];
	}

	for (int j = 1; j <= N; j++)
	{
		for (int i = 1; i <= N; i++)
		{
			pre_ori_f[i][j] = pre_ori_f[i - 1][j] + pre_ori[i][j];
			pre_res_f[i][j] = pre_res_f[i - 1][j] + pre_res[i][j];
		}
	}
}

int main()
{
	Input();

	solve();

	cout << total << '\n';
}