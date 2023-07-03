#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

using PP = pair<int, int>;

bool cmp(PP a, PP b)
{
	return a.second < b.second;
}

priority_queue<int, vector<int>, greater<int>> PQ;

vector<PP> Lecture;

int N, Ans;

int main()
{
	fastio;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a, b; cin >> a >> b;
		Lecture.push_back({ a, b });
	}

	sort(Lecture.begin(), Lecture.end(), cmp);

	for (int i = 0; i < Lecture.size(); i++)
	{
		if (PQ.size() < Lecture[i].second)
			PQ.push(Lecture[i].first);
		else if (!PQ.empty() && PQ.top() < Lecture[i].first)
		{
			PQ.pop();
			PQ.push(Lecture[i].first);
		}
	}

	while (!PQ.empty())
	{
		Ans += PQ.top();
		PQ.pop();
	}

	cout << Ans << '\n';
}