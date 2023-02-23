#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define pss pair<string, string>

using namespace std;

int N, max_len = INT_MIN;

vector<pss> V;

string Ans = "";

bool cmp(pss a, pss b)
{
	return a.second > b.second;
}

int main()
{
	fastio;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string S; cin >> S;
		V.push_back({ S, S });
		max_len = max(max_len, (int)S.length());
	}

	for (int i = 0; i < N; i++)
	{
		while ((int)V[i].second.length() < max_len * 2)
			V[i].second += V[i].first;

		while ((int)V[i].second.length() > max_len * 2)
			V[i].second.pop_back();
	}

	sort(all(V), cmp);

	for (auto e : V)
		Ans += e.first;

	Ans[0] == '0' ? cout << 0 << '\n' : cout << Ans << '\n';
}