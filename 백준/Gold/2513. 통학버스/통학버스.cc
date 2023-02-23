#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()

using namespace std;

int N, K, S, Ans;

deque<pii> Left, Right;

int main()
{
	fastio;

	cin >> N >> K >> S;

	for (int i = 0; i < N; i++)
	{
		int a, b; cin >> a >> b;
		if (a < S) Left.push_back({ a, b });
		else if (a > S) Right.push_back({ a, b });
	}

	sort(all(Left)); 
	
	sort(all(Right)); 
	reverse(all(Right));

	while (!Left.empty())
	{
		int Cnt = 0, SUM = K;
		for (auto &e : Left)
		{
			if (SUM - e.second < 0)
			{
				e.second -= SUM;
				break;
			}
			else
			{
				Cnt++;
				SUM -= e.second;
			}
		}
		Ans += 2 * (S - Left.front().first);

		while (Cnt--)
			Left.pop_front();
	}

	while (!Right.empty())
	{
		int Cnt = 0, SUM = K;
		for (auto& e : Right)
		{
			if (SUM - e.second < 0)
			{
				e.second -= SUM;
				break;
			}
			else
			{
				Cnt++;
				SUM -= e.second;
			}
		}
		Ans += 2 * (Right.front().first - S);

		while (Cnt--)
			Right.pop_front();
	}

	cout << Ans << '\n';
}