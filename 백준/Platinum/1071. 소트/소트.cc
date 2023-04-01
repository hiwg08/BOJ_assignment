#include <bits/stdc++.h>

using namespace std;

int N;

multiset<int> ms;

vector<int> V;

int main()
{
	cin >> N;

	for (int i = 0, a; i < N; i++)
	{
		cin >> a;
		ms.insert(a);
	}

	while ((int)V.size() < N)
	{
		bool chk = false;

		for (auto it = ms.begin(); it != ms.end(); it++)
		{
			auto nxt = ++it;
			it--;

			if (nxt != ms.end())
			{
				int ni = (*it), nj = (*nxt);

				if (ni + 1 == nj)
				{
					chk = true;
					auto itt = ms.lower_bound(nj + 1);

					if (itt != ms.end()) // 1, 3, 순서대로
					{
						for (auto e : ms)
						{
							if (e != ni)
								break;
							V.push_back(e);
						}
						V.push_back(*itt);
						ms.erase(itt);
						ms.erase(ni);
						break;
					}
					else // 2만
					{
						V.push_back(nj);
						ms.erase(nxt);
						break;
					}
				}
				else if (ni + 1 < nj)
				{
					chk = true;
					V.push_back(ni);
					ms.erase(it);
					break;
				}
			}
			// else는 없다.
		}

		if (!chk)
		{
			for (auto e : ms)
				V.push_back(e);
		}
	}

	for (int i = 0; i < (int)V.size(); i++)
		cout << V[i] << " ";
}