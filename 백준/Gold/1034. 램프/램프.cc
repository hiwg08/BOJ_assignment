#include <bits/stdc++.h>

using namespace std;

int N, M, K, total;

vector<string> V;

multiset<string> ms;

int main()
{
	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
	{
		string S; cin >> S;
		for (int j = 0; j < M; j++)
		{
			if (S[j] == '0') S[j] = '1';
			else S[j] = '0';
		}
		V.push_back(S);
		ms.insert(S);
	}

	sort(V.begin(), V.end());

	V.erase(unique(V.begin(), V.end()), V.end());

	cin >> K;

	for (int i = 0; i < (int)V.size(); i++)
	{
		int cnt = 0;

		for (auto e : V[i])
		{
			if (e == '1') cnt += 1;
		}
		if (K >= cnt && (K - cnt) % 2 == 0)
			total = max(total, (int)ms.count(V[i]));
	}

	cout << total << '\n';
}