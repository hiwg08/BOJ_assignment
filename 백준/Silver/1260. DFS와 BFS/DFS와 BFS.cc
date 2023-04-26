#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M, V, I1, I2;

vector<vector<int>> graphs;

bool vis[1001] = { 0 };

void sort()
{
	for (unsigned int i = 0; i < graphs.size(); i++)
	{
		if (graphs.size() != 0)
			sort(graphs[i].begin(), graphs[i].end());
	}
}

void DFS(int Node)
{
	vis[Node] = true;
	cout << Node << " ";
	for (int e : graphs[Node])
	{
		if (!vis[e])
		{
			vis[e] = true;
			DFS(e);
		}
	}
}

void BFS(int Node)
{
	memset(vis, false, sizeof(vis));
	queue<int> seq;
	seq.push(Node);
	while (!seq.empty())
	{
		int last = seq.front();
		cout << last << " ";
		seq.pop();
		vis[last] = true;
		for (int e : graphs[last])
		{
			if (!vis[e])
			{
				seq.push(e);
				vis[e] = true;
			}
		}
	}
}

int main()
{
	cin >> N >> M >> V;
	graphs.resize(N + 1);
	for (int i = 0; i < M; i++)
	{
		cin >> I1 >> I2;
		graphs[I1].push_back(I2);
		graphs[I2].push_back(I1);
	}

	sort();

	DFS(V);
	cout << '\n';

	BFS(V);
	cout << '\n';
}