#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

bool Vis[5][5]{ 0 };

char Main_Board[5][5]{ 0 }, Sub_Board[5][5]{ 0 };

int Piece_Cnt, MIN = INT_MAX;

vector<pii> V;

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, 1, 0, -1 };

pair<int, int> Piece_Pos[5];

bool Is_Connected(int x, int y)
{
	int Cnt = 0;

	map<pii, bool> CHK;

	queue<pii> Q;

	CHK[{x, y}] = true;

	Q.push( {x, y} );

	while (!Q.empty())
	{
		pii st1 = Q.front();
		Q.pop();
		Cnt++;

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = st1.first + dx[dir];
			int ny = st1.second + dy[dir];

			if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
				continue;

			if (Sub_Board[nx][ny] == 0)
				continue;

			if (CHK[{nx, ny}])
				continue;

			CHK[{nx, ny}] = true;
			Q.push({ nx, ny });
		}
	}

	return Cnt == Piece_Cnt;
}

int Get_Mahhatan(int x, int y, int Detect)
{
	return (int)(abs(x - Piece_Pos[Detect].first) + abs(y - Piece_Pos[Detect].second));
}

void Recurse(int x, int y, int Idx)
{
	if (Idx == Piece_Cnt)
	{
		if (Is_Connected(V[0].first, V[0].second))
		{
			do
			{
				int SUM = 0;
				for (int i = 0; i < Idx; i++)
					SUM += Get_Mahhatan(V[i].first, V[i].second, i);
				MIN = min(MIN, SUM);
			} while (next_permutation(V.begin(), V.end()));
		}
		return;
	}

	while (x < 5)
	{
		while (y < 5)
		{
			if (!Vis[x][y])
			{
				Vis[x][y] = true;
				V.push_back( { x, y } );
				Sub_Board[x][y] = 1;
				Recurse(x, y + 1, Idx + 1);
				Vis[x][y] = false;
				V.pop_back();
				Sub_Board[x][y] = 0;
			}
			y++;
		}
		x++;
		y = 0;
	}
}

void Input()
{
	for (int i = 0; i < 5; i++)
	{
		string S; cin >> S;
		for (int j = 0; j < (int)S.size(); j++)
		{
			Main_Board[i][j] = S[j];
			if (S[j] == '*') Piece_Pos[Piece_Cnt++] = { i, j };
		}
	}
}

int main()
{
	Input();

	Recurse(0, 0, 0);

	cout << MIN << '\n';
}