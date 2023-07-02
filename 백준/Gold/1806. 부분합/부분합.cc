#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int N, S, Arr[100001]{ 0 }, MIN = INT_MAX;

queue<int> Q;

int main()
{
	fastio;

	cin >> N >> S;

	for (int i = 0; i < N; i++)
		cin >> Arr[i];

	int SUM = 0;

	for (int i = 0; i < N; i++)
	{
		SUM += Arr[i];
		Q.push(Arr[i]);

		while (!Q.empty() && SUM >= S)
		{
			MIN = min(MIN, (int)Q.size());
			SUM -= Q.front();
			Q.pop();
		}
	}

	MIN == INT_MAX ? cout << 0 << '\n' : cout << MIN << '\n';
}