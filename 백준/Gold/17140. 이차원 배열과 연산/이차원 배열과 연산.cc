#include <bits/stdc++.h>
#include <unordered_map>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int R, C, K, Arr[101][101]{ 0 };

int Row_S = 3, Col_S = 3;

bool cmp(pii a, pii b)
{
	if (a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}

void solve_row()
{
	int Update_Col = Col_S;

	for (int i = 0; i < Row_S; i++)
	{
		unordered_map<int, int> M;
		vector<pii> V;
		for (int j = 0; j < Col_S; j++)
		{
			if (Arr[i][j] != 0)
				M[Arr[i][j]]++;
		}

		for (auto& e : M)
			V.push_back({ e.x, e.y });

		sort(V.begin(), V.end(), cmp);

		Update_Col = max(Update_Col, (int)V.size() * 2);

		int Idx = 0;

		for (int j = 0; j < (int)V.size(); j++)
		{
			Arr[i][Idx++] = V[j].x;
			if (Idx >= 100)
			{
				Idx--; break;
			}

			Arr[i][Idx++] = V[j].y;
			if (Idx >= 100)
			{
				Idx--; break;
			}
		}

		for (int j = Idx; j < Col_S; j++)
			Arr[i][j] = 0;
	}

	Col_S = Update_Col;
}
void solve_col()
{
	int Update_Row = Row_S;

	for (int i = 0; i < Col_S; i++)
	{
		unordered_map<int, int> M;
		vector<pii> V;

		for (int j = 0; j < Row_S; j++)
		{
			if (Arr[j][i] != 0)
				M[Arr[j][i]]++;
		}

		for (auto& e : M)
			V.push_back({ e.x, e.y });

		sort(V.begin(), V.end(), cmp);

		Update_Row = max(Update_Row, (int)V.size() * 2);

		int Idx = 0;

		for (int j = 0; j < (int)V.size(); j++)
		{
			Arr[Idx++][i] = V[j].x;
			if (Idx >= 100)
			{
				Idx--; break;
			}

			Arr[Idx++][i] = V[j].y;
			if (Idx >= 100)
			{
				Idx--; break;
			}
		}

		for (int j = Idx; j < Row_S; j++)
			Arr[j][i] = 0;
	}

	Row_S = Update_Row;
}

int main()
{
	cin >> R >> C >> K;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> Arr[i][j];
	}

	for (int T = 0; T <= 100; T++)
	{
		if (Arr[R - 1][C - 1] == K)
		{
			cout << T << '\n';
			exit(0);
		}

		if (Row_S >= Col_S) solve_row();
		else solve_col();
	}

	cout << -1 << "\n";
}