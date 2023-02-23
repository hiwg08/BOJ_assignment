#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

class Trie
{
public:
	Trie* Node[26];
	int child_num, overlap;
	bool end;

	Trie()
	{
		fill(Node, Node + 26, nullptr);
		child_num = 0;
		overlap = 0;
		end = false;
	}

	~Trie()
	{
		for (int i = 0; i < 26; i++)
		{
			if (Node[i] != nullptr)
				delete Node[i];
		}
	}

	void Insert(string S, int Idx, int L)
	{
		if (Idx >= L)
		{
			this->end = true;
			return;
		}
		
		int al = (int)(S[Idx] - 'a');

		if (Node[al] == nullptr)
		{
			this->child_num++;
			Node[al] = new Trie();
		}
		else
			this->overlap++;

		Node[al]->Insert(S, Idx + 1, L);
	}
};

int N;

Trie* root;

int main()
{
	fastio;

	while (true)
	{
		cin >> N;

		if (cin.eof())
			break;

		root = new Trie();

		vector<string> V;

		for (int i = 0; i < N; i++)
		{
			string S; cin >> S; V.push_back(S);
			root->Insert(S, 0, (int)S.length());
		}

		int Total = 0;

		for (auto params : V)
		{
			Trie* q = root->Node[(int)(params[0] - 'a')];
			
			int Cnt = 1;

			for (int i = 1; i < (int)params.length(); i++)
			{
				if (q->child_num == 1)
				{
					if (q->end)
						Cnt++;
					if (q->overlap == 0)
						break;
				}
				else
					Cnt++;

				q = q->Node[(int)(params[i] - 'a')];
			}

			Total += Cnt;
		}

		double Ans = (double)Total / (double)N;

		cout.precision(2);

		cout << fixed << round(Ans * 100.0) / 100.0 << '\n';

		delete root;
	}
}