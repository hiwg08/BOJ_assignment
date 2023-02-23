#include <bits/stdc++.h>
#define MAX 50000

using namespace std;

int N, Prime_Num[MAX + 1]{ 0 }, Total;

vector<int> V;

void Init()
{
	int standard = (int)sqrt(N);

	for (int i = 2; i <= standard; i++)
	{
		if (Prime_Num[i] == -1)
			continue;
		for (int j = i; j <= N; j += i)
		{
			if (j != i)
				Prime_Num[j] = -1;
		}
	}

	for (int i = 2; i <= N; i++)
	{
		if (Prime_Num[i] != -1)
			V.push_back(i);
	}
}

int get(int params)
{
	int Ans = 1;

	for (auto e : V)
	{
		if (params == 1)
			break;
		
		int Idx = 1;
		
		while (params % e == 0)
			params /= e, Idx *= e;

		Ans *= (Idx - (Idx / e));
	}

	return Ans;
}

int main()
{
	cin >> N;

	Init();

	for (int i = 2; i <= N; i++)
		Total += get(i);
		

	cout << Total << '\n';
}