#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int N, K;

deque<int> Arr;

deque<pii> S;

deque<int> ans;

void update_query(int order, int num)
{
	while (!S.empty() && S.back().x < order)
		S.pop_back();
	
	S.push_back({ order, num });
}

int main()
{
	cin >> N; Arr.resize(N);

	for (int i = 0; i < N; i++)
		cin >> Arr[i];

	cin >> K;

	for (int i = 0, a, b; i < K; i++)
	{
		cin >> a >> b;

		update_query(a, 1);
		update_query(b, -1);
	}

	int Idx = N - S[0].x;

	while (Idx > 0)
	{
		ans.push_front(Arr.back());
		Arr.pop_back();
		Idx--;
	}

	S.push_back({ 0, 1 });

	sort(Arr.begin(), Arr.end());

	for (int i = 0; i < (int)S.size() - 1; i++)
	{
		int interval = abs(S[i].x - S[i + 1].x);

		if (S[i].y == 1)
		{
			while (interval--)
			{
				ans.push_front(Arr.back());
				Arr.pop_back();
			}
		}
		else
		{
			while (interval--)
			{
				ans.push_front(Arr.front());
				Arr.pop_front();
			}
		}
	}

	for (auto e : ans)
		cout << e << " ";
}