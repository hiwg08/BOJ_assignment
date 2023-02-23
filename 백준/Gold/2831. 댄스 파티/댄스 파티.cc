#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(), x.end()

using namespace std;

int N, total;

vector<int> Small_M, Tall_W, Tall_M, Small_W;

int main()
{
	fastio;

	cin >> N;
	
	for (int i = 0, a; i < N; i++)
	{
		cin >> a;
		a > 0 ? Tall_M.push_back(a) : Small_M.push_back(-a);
	}

	for (int i = 0, a; i < N; i++)
	{
		cin >> a;
		a > 0 ? Tall_W.push_back(a) : Small_W.push_back(-a);
	}

	sort(all(Tall_M), greater<>());
	sort(all(Tall_W), greater<>());
	sort(all(Small_M), greater<>());
	sort(all(Small_W), greater<>());

	int M_Idx = 0, W_Idx = 0;

	while (M_Idx < (int)Tall_M.size() && W_Idx < (int)Small_W.size())
	{
		if (Tall_M[M_Idx] < Small_W[W_Idx])
		{
			total++;
			M_Idx++, W_Idx++;
		}
		else
			M_Idx++;
	}

	M_Idx = 0, W_Idx = 0;

	while (M_Idx < (int)Tall_W.size() && W_Idx < (int)Small_M.size())
	{
		if (Tall_W[M_Idx] < Small_M[W_Idx])
		{
			total++;
			M_Idx++, W_Idx++;
		}
		else
			M_Idx++;
	}

	cout << total << '\n';
}