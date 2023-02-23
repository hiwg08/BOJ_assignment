#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N, Cnt;

vector<int> table;

string S = "", A = "";

void make_table()
{
	table[0] = -1;

	for (int i = -1, j = 0; j <= (int)A.length(); i++, j++)
	{
		table[j] = i;

		while ((i >= 0) && (A[i] != A[j]))
			i = table[i];
	}
}

void solve() // 테이블은 한 칸 씩 땡겨서 사용
{
	int S_L = (int)S.length(), A_L = (int)A.length();

	int P_Idx = 0;

	for (int i = 0; i < S_L - 1; i++)
	{
		while ((P_Idx > 0) && (S[i] != A[P_Idx]))
			P_Idx = table[P_Idx];

		if (S[i] == A[P_Idx])
		{
			if (P_Idx == A_L - 1)
			{
				Cnt++;
				P_Idx = table[P_Idx + 1];
			}
			else
				P_Idx++;
		}
	}
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	fastio;

	cin >> N;

	char c;

	for (int i = 0; i < N; i++)
	{
		cin >> c; S += c;
	}

	for (int i = 0; i < N; i++)
	{
		cin >> c; A += c;
	}

	S += S;

	table.resize((int)A.length() + 1);

	make_table();

	solve();

	int tmp = gcd(N, Cnt);

	cout << (Cnt / tmp) << "/" << (N / tmp) << '\n';
}