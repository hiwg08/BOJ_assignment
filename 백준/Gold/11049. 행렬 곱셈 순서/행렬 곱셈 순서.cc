#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pii pair<int, int>

using namespace std;

int N, DP[501][501]{ 0 };

vector<pii> V;

int solve(int Start, int End)
{
	if (Start == End)
		return 0;

	int& ret = DP[Start][End];

	if (ret != 0x7f7f7f7f)
		return ret;

	for (int i = Start; i < End; i++) // 처음 End가 N - 1이기 때문. Start - i - End 간의 관계
		ret = min(ret, solve(Start, i) + solve(i + 1, End) + (V[Start].first * V[i].second * V[End].second));

	return ret;
}

int main()
{
	fastio;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a, b; cin >> a >> b;
		V.push_back({ a, b });
	}

	memset(DP, 0x7f, sizeof(DP));

	cout << solve(0, N - 1) << '\n';
}