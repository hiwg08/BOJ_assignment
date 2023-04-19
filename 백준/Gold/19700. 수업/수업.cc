#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int N;

multiset<int> ms;

vector<pii> V;

int main()
{
	fastio;

	cin >> N; V.resize(N);

	for (auto& iv : V)
		cin >> iv.x >> iv.y;

	sort(V.begin(), V.end());

	for (int i = N - 1; i >= 0; i--)
	{
		auto it = ms.lower_bound(-V[i].y + 1);

		if (it == ms.end())
			ms.insert(-1);
		else
		{
			int k = *it - 1;
			ms.erase(it);
			ms.insert(k);
		}
	}

	cout << (int)ms.size();
}