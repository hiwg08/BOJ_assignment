#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using PP = pair<int, int>;

int N, I1, I2, D, G;

vector<vector<int>> graphs;

vector<PP> p_c;

bool vis[300001]{ 0 };

int combination(int n)
{
	return static_cast<int>((n * (n - 1) * (n - 2)) / 6);
}

void BFS_and_G(int Start)
{
	queue<int> seq;
	seq.push(Start);

	while (!seq.empty())
	{
		int temp = seq.front();
		vis[temp] = true;
		seq.pop();

		int cnt = 0;
		for (int e : graphs[temp])
		{
			if (!vis[e])
			{
				seq.push(e);
				p_c.push_back({ temp, e });
			}
			cnt++;
		}

		if (cnt >= 3)
			G += combination(cnt);
	}
}
void find_D(int Start)
{
	for (PP e : p_c)
		D += ((graphs[e.first].size() - 1) * (graphs[e.second].size() - 1));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	graphs.resize(N + 1);

	for (int i = 0; i < N - 1;i++)
	{
		cin >> I1 >> I2;
		graphs[I1].push_back(I2);
		graphs[I2].push_back(I1);
	}

	BFS_and_G(1);

	find_D(1);

	if (3 * G == D)
		cout << "DUDUDUNGA" << '\n';
	else if (3 * G < D)
		cout << "D" << '\n';
	else
		cout << "G" << '\n';
}