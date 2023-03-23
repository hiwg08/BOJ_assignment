#include <bits/stdc++.h>

using namespace std;

int N, a, b, A, B;

int Arr[110][110]{ 0 };

int dx[]{ 0, -1, 0, 1 };
int dy[]{ 1, 0, -1, 0 };

bool computer;

void make_dir(int px, int py)
{
	int nx = px, ny = py;

	for (int i = 1; i <= A; i++)
	{
		if (i == N + 2)
			break;
		if (i == 1)
			Arr[nx][ny] = -1;
		if (i == 2)
			Arr[nx - 1][ny] = -1;
		if (i == 3)
			Arr[nx][++ny] = -1;
		if (i >= 4 && i <= N + 1)
			Arr[nx][++ny] = -1;
	}
}

// A가 -1, B가 1

int main()
{
	cin >> N >> a >> b;

	A = min(a, b), B = max(a, b);

	if (A == a)
		computer = true;

	make_dir(N - 1, 0);

	if (A >= N + 2)
	{
		for (int i = N - 1; i >= 0; i--)
		{
			for (int j = 0; j < N; j++)
			{
				if (A == 0)
					break;
				Arr[i][j] = -1;
				A--;
			}
			if (A == 0)
				break;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			bool chk = true;
			
			if (Arr[i][j] == -1)
				chk = false;

			for (int dir = 0; dir < 4; dir++)
			{
				int nx = i + dx[dir], ny = j + dy[dir];
				
				if (nx < 0 || ny < 0 || nx >= N || ny >= N)
					continue;
				
				if (Arr[nx][ny] == -1)
					chk = false;
			}

			if (chk && B > 0)
			{
				Arr[i][j] = 1;
				B--;
			}
		}
	}

	if (B != 0)
	{
		cout << -1;
		exit(0);
	}
	
	cout << 1 << '\n';

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Arr[i][j] == -1) 
				computer ? cout << 1 : cout << 2;
			else if (Arr[i][j] == 1)
				computer ? cout << 2 : cout << 1;
			else
				cout << Arr[i][j];
		}
		cout << '\n';
	}
}