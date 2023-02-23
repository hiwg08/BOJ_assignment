#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using namespace std;

int N, M, ans;

vector<int> crain, s;

int main()
{
	cin >> N; crain.resize(N);

	for (auto& iv : crain)
		cin >> iv;

	cin >> M; s.resize(M);

	for (auto& iv : s)
		cin >> iv;

	sort(all(crain), greater<>());

	sort(all(s));

	if (s[(int)s.size() - 1] > crain[0])
	{
		cout << -1 << '\n';
		exit(0);
	}

	while (!s.empty())
	{
		for (int i = 0; i < N; i++)
		{
			if (s.empty())
				break;

			auto it = (int)(lower_bound(all(s), crain[i]) - s.begin());

			if (it >= (int)s.size())
				s.pop_back();

			else
			{
				if (s[it] > crain[i])
					it--;

				if (it >= 0 && s[it] <= crain[i])
					s.erase(s.begin() + it);
			}
		}

		ans++;
	}

	cout << ans << '\n';
}