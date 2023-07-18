#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N;

string S, ans = "";

struct comp
{
	bool operator()(string a, string b)
	{
		return a + b > b + a;
	}
};

priority_queue<string, vector<string>, comp> PQ;

void solve()
{
	while (!PQ.empty())
	{
		string T1 = PQ.top();
		ans += T1[0];
		PQ.pop();
		if ((ll)T1.length() > 1)
			PQ.push(T1.substr(1));
	}
}

int main()
{
	cin >> N;

	for (ll i = 0; i < N; i++)
	{
		cin >> S;
		PQ.push(S);
	}

	solve();

	cout << ans;
}