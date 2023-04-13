#include <bits/stdc++.h>

using namespace std;

int N, total = 0;

int arr[60][20]{ 0 };

int order[20]{ 0 };

int Vis[20]{ 0 };

int match()
{
	int cnt = 0;

	int k = -1;

	for (int i = 1; i <= N; i++) // 모든 이닝마다 반복
	{
		int out_count = 0; // 이닝이 시작할 때 아웃 카운트는 초기화

		deque<int> DQ; // n루에 있는 타자들도 마찬가지로 초기화.덱을 쓰는 이유는 나무 제테크 문제와 동일하다고 보면 된다. (항상 오름차순 또는 내림차순으로 관리되는 덱을 생각하면 됨)

		if (k == -1)
			k = 1;
		else
		{
			if (k == 9)
				k = 1;
			else
				k++;
		} // ex. 이전 이닝에서 4번 타자에서 아웃됐으면 5번 타자로 점프, 9번 타자였다면 1번 타자로. 

		for (int j = k; j <= 9; j++)
		{
			int player = order[j];

			if (arr[i][player] == 0)
				out_count++;
			else
			{
				for (int k = (int)DQ.size() - 1; k >= 0; k--)
				{
					DQ[k] += arr[i][player];

					if (DQ[k] >= 4)
						cnt++;
				}

				if (arr[i][player] == 4)
					cnt++;
				else
					DQ.push_front(arr[i][player]);

				while (!DQ.empty() && DQ.back() >= 4)
					DQ.pop_back();
			}

			if (out_count == 3) // 3 아웃이면 그 다음 칠 타자를 정해주고 빠져나오자.
			{
				k = j;
				break;
			}

			if (j == 9)
				j = 0; // 이거 맨 처음에 int j = k라고 되어 있어도, k는 안 바꿔도 자동으로 1로 시작되더라 ㅇㅇ. 아마 int j = k는 걍 진짜 '맨 처음'의 초기값일 거야.
		}
	}

	return cnt;
}

void solve(int Idx)
{
	if (Idx == 10)
	{
		total = max(total, match());
		return;
	}

	if (Idx == 4) // 4번 타석은 이미 1번 타자 고정이다.
	{
		solve(Idx + 1); // 그래서 넘겨준 다음에 바로 리턴.
		return;
	}

	for (int i = 2; i <= 9; i++) // 1번 타자는 이미 4번 타석이므로 8! = 40320 돌리면 됨.
	{
		if (Vis[i])
			continue;
		Vis[i] = true;
		order[Idx] = i;
		solve(Idx + 1);
		order[Idx] = 0;
		Vis[i] = false;
	}
}

int main()
{
	cin >> N;
	 
	for (int i = 1; i <= N; i++) 
	{
		for (int j = 1; j <= 9; j++)
			cin >> arr[i][j];
	}

	order[4] = 1; // 4번은 1번 타자가

	solve(1); // 1(Idx)번 order부터 9번 order까지 브루트포스로 정하기

	cout << total;
}
