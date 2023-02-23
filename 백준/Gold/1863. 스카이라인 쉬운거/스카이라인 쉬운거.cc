#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int N, Ans;

vector<pii> V;

stack<int> S;

int main()
{
	fastio;

	cin >> N; V.resize(N);

	for (auto& iv : V)
		cin >> iv.x >> iv.y;

	sort(V.begin(), V.end());

	for (int i = 0; i < N; i++)
	{
		while (!S.empty() && S.top() > V[i].y)
		{
			S.pop();
			Ans++;
		}

		if (!S.empty() && S.top() == V[i].y)
			continue;

		if (V[i].y != 0)
			S.push(V[i].y);
	}

	while (!S.empty())
	{
		S.pop();
		Ans++;
	}

	cout << Ans << '\n';
}