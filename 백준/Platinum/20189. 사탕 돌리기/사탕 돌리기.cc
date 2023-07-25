#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int N, K, Q, sum;

int nu[2001]{ 0 };

deque<pii> DQ;

bool solve()
{
	for (int i = 0, Idx = N; i < N * K; i += K, Idx--)
	{
		for (int j = i; j < i + K; j++)
		{
			if (DQ[j].y >= 1)
			{
				sum += DQ[j].y;

				nu[Idx]--;

				if (Idx + DQ[j].y <= N)
					nu[Idx + DQ[j].y]++;
				else
					nu[(Idx + DQ[j].y) % N]++;
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (nu[i] >= 1)
			return false;
	}

	return true;
}

void input()
{
	cin >> N >> K >> Q;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0, a; j < K; j++)
		{
			cin >> a;

			if (a >= i)
				DQ.push_front({ a, a - i });
			else
				DQ.push_front({ a, N - i + a });
		}
	}
}

int main()
{
	fastio;

	input();

	bool ans = solve();

	if (ans && sum / N <= Q)
		cout << 1;
	else
		cout << 0;
}