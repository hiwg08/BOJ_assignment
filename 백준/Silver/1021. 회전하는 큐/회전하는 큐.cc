#include <bits/stdc++.h>

using namespace std;

int N, M, total, cmd[51]{ 0 };

deque<int> DQ;

int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
		cin >> cmd[i];

	for (int i = 0; i < N; i++)
		DQ.push_back(i + 1);

	for (int i = 0; i < M; i++)
	{
		deque<int> L_DQ = DQ, R_DQ = DQ;

		int l_move = 0, r_move = 0;

		while (L_DQ.front() != cmd[i])
		{
			L_DQ.push_back(L_DQ.front());
			L_DQ.pop_front();
			l_move++;
		}
		while (R_DQ.front() != cmd[i])
		{
			R_DQ.push_front(R_DQ.back());
			R_DQ.pop_back();
			r_move++;
		}

		L_DQ.pop_front(), R_DQ.pop_front();

		if (l_move < r_move)
		{
			total += l_move;
			DQ = L_DQ;
		}
		else
		{		
			total += r_move;
			DQ = R_DQ;
		}
	}

	cout << total << '\n';
}