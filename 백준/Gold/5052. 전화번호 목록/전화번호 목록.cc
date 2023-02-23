#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N, T;

bool CHK = true;

class Trie
{
private:
	bool is_leaf;
	Trie* Node[10];

public:
	Trie()
	{
		is_leaf = true;
		for (int i = 0; i < 10; i++)
			Node[i] = nullptr;
	}
	~Trie()
	{
		for (int i = 0; i < 10; i++)
		{
			if (Node[i] != nullptr)
				delete Node[i];
		}
	}

	void Insert(string S, int Idx, int L, int Cnt)
	{
		if (Idx >= L)
		{
			if (Cnt == L) CHK = false;
			return;
		}


		if (Node[(int)(S[Idx] - '0')] == nullptr)
		{
			Node[(int)(S[Idx] - '0')] = new Trie();

			if (Idx != L - 1)
				Node[(int)(S[Idx] - '0')]->is_leaf = false;
		}
		else
		{
			if (Node[(int)(S[Idx] - '0')]->is_leaf)
			{
				CHK = false;
				return;
			}
			Cnt += 1;
		}

		Node[(int)(S[Idx] - '0')]->Insert(S, Idx + 1, L, Cnt);
	}

};

Trie* root;

int main()
{
	fastio;

	cin >> T;

	while (T--)
	{
		CHK = true;

		cin >> N;

		root = new Trie();

		for (int i = 0; i < N; i++)
		{
			string S; cin >> S;
			root->Insert(S, 0, (int)S.length(), 0);
		}

		CHK ? cout << "YES" << '\n' : cout << "NO" << '\n';

		delete root;
	}
}