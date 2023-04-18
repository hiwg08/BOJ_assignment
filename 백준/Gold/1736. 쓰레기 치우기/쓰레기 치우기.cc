#include <bits/stdc++.h>

using namespace std;

multiset<int> ms[101];

int N, M, total;

void solve(int Idx, int standard)
{
	for (int i = Idx; i >= 1; i--)
	{
		while (!ms[i].empty())
		{
			auto it = ms[i].lower_bound(standard);

			if (it == ms[i].end()) // ms[i]가 텅 비었거나 lower_bound에 만족하는 숫자가 없을 때는 그 곳은 애당초 로봇이 쓰레기를 치울 수가 없다. 따라서 바로 빠져나오자.
				break;

			standard = *it;

			ms[i].erase(it);
		}
	}
}

void input()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1, a; j <= M; j++)
		{
			cin >> a;
			if (a == 1)
				ms[i].insert(-j); // 배열은 굳이 필요하지 않다. multiset에 '음수'로 각 행에 있는 쓰레기의 열 값을 저장해주자. **** 가장 가까운 '왼쪽' 값을 찾기 위해서이다. ****
		}
	}
}

int main() // 그리디 문제. 1. 맨 아래에서부터 보면서 왼쪽 --> 위 쪽으로 쓰레기를 치워주자.
           // 오른쪽 -> 아래로 밖에 로봇이 움직이지 못 한다는 점, dp로 접근하기에는 점화식을 세우기 까다로웠던 점, 너무 직관적인(?) 아이디어로 인해 그리디로 생각.  
{
	input();

	for (int i = N; i >= 1; i--) // 가장 아래 행부터 탐색을 진행하자.
	{
		if (!ms[i].empty()) // 하나라도 있으면 그 곳을 치워야 한다.
		{
			total++;

			int T = *(ms[i].begin());

			auto it = ms[i].lower_bound(T);

			ms[i].erase(it);

			solve(i, T); // 현재 행 & 열에서 로봇이 치울 수 있는 쓰레기를 치워주자.
		}
	}

	cout << total;
}
