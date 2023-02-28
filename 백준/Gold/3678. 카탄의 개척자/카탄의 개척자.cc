#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int T, N;

int ans[10010]{ 0, 1, 2, 3, 4, 5, 2, 3, };

int total[6]{ 0, 1, 2, 2, 1, 1 };

vector<int> select(int t1, int t2, int t3)
{
	vector<int> ret;

	for (int i = 1; i <= 5; i++)
	{
		if (i != ans[t1] && i != ans[t2])
		{
			if (t3 == -1)
				ret.push_back(i);

			else if (i != ans[t3])
				ret.push_back(i);
		}
	}

	return ret;
}

void solve(int Idx, int t1, int t2, int t3)
{
	vector<int> V = select(t1, t2, t3);

	vector<pii> T;

	for (auto e : V)
		T.push_back({ total[e], e });

	sort(T.begin(), T.end());

	ans[Idx] = T[0].y;

	total[T[0].y]++;
}

void katan()
{
	int interval = 12;

	int Idx = 8, cnt = 2;

	while (true)
	{
		int quo = interval / 6 - 2;

		int t1 = Idx - 1, t2 = cnt;

		solve(Idx, Idx - 1, cnt, -1);

	//s	cout << "(" << Idx << ") , " << t1 << ", " << t2 << '\n';

		Idx++;
		if (Idx > 10000) break;

		for (int i = 0; i < quo; i++) // 여기는 3
		{
			int t1 = Idx - 1, t2 = cnt, t3 = cnt + 1;

			solve(Idx, Idx - 1, cnt, cnt + 1);

			//cout << "(" << Idx << ") , " << t1 << ", " << t2 << ", " << t3 << '\n';

			cnt++, Idx++;

			if (Idx > 10000) break;
		}

		if (Idx > 10000) break;

		quo += 1;

		for (int i = 0; i < 5; i++)
		{
			int t1 = Idx - 1, t2 = cnt;

			solve(Idx, Idx - 1, cnt, -1);

		  //  cout << "(" << Idx << ") , " << t1 << ", " << t2 << '\n';

			Idx++;

			if (Idx > 10000) break;

			// 맨 처음은 2

			for (int j = 0; j < quo; j++) // 여기는 3
			{
				int t1 = Idx - 1, t2 = cnt, t3 = cnt + 1;

				solve(Idx, Idx - 1, cnt, cnt + 1);

			//	cout << "(" << Idx << ") , " << t1 << ", " << t2 << ", " << t3 << '\n';

				cnt++, Idx++;

				if (Idx > 10000) break;
			}
		}

		if (Idx > 10000) break;

		t1 = Idx - 1, t2 = cnt;
		int t3 = cnt + 1;

		solve(Idx, Idx - 1, cnt, cnt + 1);

	//	cout << "(" << Idx << ") , " << t1 << ", " << t2 << ", " << t3 << '\n';

		cnt++, Idx++;

		if (Idx > 10000) break;

		interval += 6;
	}
}

int main()
{
	katan();

	cin >> T;

	while (T--)
	{
		cin >> N;

		cout << ans[N] << '\n';
	}
}