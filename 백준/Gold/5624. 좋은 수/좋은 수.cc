#include <bits/stdc++.h>
#include <unordered_set>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N, Arr[5001], total;

unordered_set<int> DP;

int main()
{
	fastio;

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> Arr[i];

	for (int i = 0; i < N; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (DP.find(Arr[i] - Arr[j]) != DP.end())
			{
				total++;
				break;
			}
		}

		for (int j = i; j >= 0; j--)
			DP.insert(Arr[i] + Arr[j]);
	}

	cout << total << '\n';
}