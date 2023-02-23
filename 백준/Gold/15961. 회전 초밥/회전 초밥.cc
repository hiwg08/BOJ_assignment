#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int Vis[3001]{ 0 };

int N, D, K, C, Cnt, Ans = INT_MIN;

queue<int> Q;

vector<int> V;

int main()
{
	fastio;

	cin >> N >> D >> K >> C;

	for (int i = 0, a; i < N; i++)
	{
		cin >> a; V.push_back(a);
	}

	for (int i = 0; i < K; i++)
		V.push_back(V[i]);

	Vis[C] = 1, Cnt = 1;

	for (int i = 0; i < N + K; i++)
	{
		Q.push(V[i]);
		if (Vis[V[i]] == 0)
			Cnt++;
		Vis[V[i]]++;

		if ((int)Q.size() == K)
		{
			Ans = max(Ans, Cnt);

			Vis[Q.front()]--;
			if (Vis[Q.front()] == 0)
				Cnt--;
			Q.pop();
		}
	}

	cout << Ans << '\n';
}