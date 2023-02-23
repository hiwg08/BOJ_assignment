#include <bits/stdc++.h>

using namespace std;

string S[4];

int K, total;

void rotate(int Idx, int Dir)
{
	int real_ro[4]{ 0 };
	real_ro[Idx] = Dir;

	int t_Idx = Idx;

	while (t_Idx <= 2)
	{
		if (S[t_Idx][2] == S[t_Idx + 1][6])
			break;
		real_ro[t_Idx + 1] = -real_ro[t_Idx];
		t_Idx++;
	}

	t_Idx = Idx;

	while (t_Idx >= 1)
	{
		if (S[t_Idx][6] == S[t_Idx - 1][2])
			break;
		real_ro[t_Idx - 1] = -real_ro[t_Idx];
		t_Idx--;
	}

	for (int i = 0; i < 4; i++)
	{
		if (real_ro[i] == -1)
		{
			char tmp = S[i][0];
			S[i] = S[i].substr(1);
			S[i] += tmp;
		}
		else if (real_ro[i] == 1)
		{
			string tmp_s = S[i].substr(0, 7);
			char tmp_c = S[i][7];
			S[i] = "";
			S[i] += tmp_c;
			S[i] += tmp_s;
		}
	}
}

void get_score()
{
	for (int i = 0; i < 4; i++)
	{
		if (S[i][0] == '1')
			total += (int)pow(2, i);
	}
}

int main()
{
	for (int i = 0; i < 4; i++)
		cin >> S[i];

	cin >> K;

	for (int i = 0, a, b; i < K; i++)
	{
		cin >> a >> b;
		rotate(a - 1, b);
	}

	get_score();

	cout << total << '\n';
}