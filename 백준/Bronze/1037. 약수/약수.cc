#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N;

vector<ll> V;

int main()
{
	cin >> N; V.resize(N);

	for (auto& iv : V)
		cin >> iv;

	sort(V.begin(), V.end());

	if ((ll)V.size() % 2 == 1) // 홀수일 때
		cout << V[(ll)V.size() / 2] * V[(ll)V.size() / 2];
	else
		cout << V[((ll)V.size() / 2) - 1] * V[(ll)V.size() / 2];
}