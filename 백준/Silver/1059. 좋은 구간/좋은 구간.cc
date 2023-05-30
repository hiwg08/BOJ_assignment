#include <bits/stdc++.h>

using namespace std;

int L, N, total;

vector<int> V;

int main()
{
	cin >> L; V.resize(L);
	
	for (auto& iv : V)
		cin >> iv;

	cin >> N;

	V.push_back(0);

	sort(V.begin(), V.end());

	for (int i = 0; i < (int)V.size() - 1; i++)
	{
		int L = V[i] + 1, R = V[i + 1] - 1;

		for (int out = L; out < R; out++)
		{
			for (int inn = out + 1; inn <= R; inn++)
			{
				if (N >= out && N <= inn)
					total++;
			}
		}
	}

	cout << total;
}