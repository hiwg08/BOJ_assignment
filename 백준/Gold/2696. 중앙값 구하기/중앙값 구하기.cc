#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

priority_queue<int> Max_PQ;

priority_queue<int, vector<int>, greater<int>> Min_PQ;

void Insert(int order, int params)
{
	if (order == 1)
	{
		Max_PQ.push(params);
		return;
	}

	if (!Max_PQ.empty())
	{
		if (Max_PQ.top() > params)
			Max_PQ.push(params);
		else
			Min_PQ.push(params);
	}
	else if (!Min_PQ.empty())
	{
		if (Min_PQ.top() < params)
			Min_PQ.push(params);
		else
			Max_PQ.push(params);
	}
}

void Modify(int order)
{
	if (order % 2 == 0)
	{
		while ((int)Max_PQ.size() < (int)Min_PQ.size())
		{
			Max_PQ.push(Min_PQ.top());
			Min_PQ.pop();
		}
		while ((int)Max_PQ.size() > (int)Min_PQ.size())
		{
			Min_PQ.push(Max_PQ.top());
			Max_PQ.pop();
		}
	}
	else // Max_PQ 쪽이 하나 더 커야됨
	{
		while ((int)Max_PQ.size() < (int)Min_PQ.size() + 1)
		{
			Max_PQ.push(Min_PQ.top());
			Min_PQ.pop();
		}
		while ((int)Max_PQ.size() > (int)Min_PQ.size() + 1)
		{
			Min_PQ.push(Max_PQ.top());
			Max_PQ.pop();
		}
	}
}

int T, N;

int main()
{
    fastio;
    
	cin >> T;

	while (T--)
	{
		cin >> N;

		vector<int> Ans;

		while (!Max_PQ.empty())
			Max_PQ.pop();
		while (!Min_PQ.empty())
			Min_PQ.pop();

		for (int i = 0, a; i < N; i++)
		{
			cin >> a;

			Insert(i + 1, a);

			Modify(i + 1);

			if (i % 2 == 0)
				Ans.push_back(Max_PQ.top());
		}

		cout << (int)Ans.size() << '\n';
		
		for (int i = 0; i < (int)Ans.size(); i++)
		{
			if (i != 0 && i % 10 == 0)
				cout << '\n';
			cout << Ans[i] << " ";
		}
		cout << '\n';
	}
}