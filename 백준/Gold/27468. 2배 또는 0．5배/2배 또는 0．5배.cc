#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N;

int Idx = 0;

int first[]{ 0, 1, 3, 2 };

int second[]{ 0, 2, 1, 3 };

int main()
{
	fastio;

	cin >> N;

	Idx = N;

	// 4씩 쪼개서

	cout << "YES" << '\n';

	if (N % 2 == 0) // 1 2 4 3 5 6 8 7 ... (짝수)
	{
		for (int i = 1;; i += 4)
		{
			for (int j = 0; j < 4; j++)
			{
				cout << i + first[j] << " ";
				if (--Idx == 0)
					break;
			}
			if (Idx == 0)
				break;
		}
	}
	else // 1 3 2 4 5 7 6 8 .... (홀수)
	{
		for (int i = 1;; i += 4)
		{
			for (int j = 0; j < 4; j++)
			{
				cout << i + second[j] << " ";
				if (--Idx == 0)
					break;
			}
			if (Idx == 0)
				break;
		}
	}
}