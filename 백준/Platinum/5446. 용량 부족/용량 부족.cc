#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N, M;

int cToin(char c)
{
	if (c >= '0' && c <= '9') return (int)(c - 48);
	if (c >= 'a' && c <= 'z') return (int)(c - 87);
	if (c == '.') return (int)(c + 16);
	return (int)(c - 29);
}

char inToc(int i)
{
	if (i >= 0 && i <= 9)
		return (char)(i + '0');
	if (i >= 10 && i <= 35)
		return (char)(i + 87);
	if (i == 62)
		return '.';
	return (char)(i + 29);
}

class Trie
{
public:
	Trie* Node[63];
	bool Vis;
	bool End;

	Trie()
	{
		fill(Node, Node + 63, nullptr);
		Vis = false;
		End = false;
	}
	~Trie()
	{
		for (int i = 0; i < 63; i++)
		{
			if (Node[i] != nullptr)
				delete Node[i];
		}
	}

	void Insert(string S, int Idx, int L) 
	{
		if (Idx == L)
			return;

		int T = cToin(S[Idx]);

		if (Node[T] == nullptr)
			Node[T] = new Trie();

		if (Idx == L - 1)
			Node[T]->End = true;

		Node[T]->Insert(S, Idx + 1, L);
 	}

	void search(string S, int Idx, int L)
	{
		if (Idx == L)
			return;

		int T = cToin(S[Idx]);

		if (Node[T] != nullptr)
		{
			Node[T]->Vis = true;
			Node[T]->search(S, Idx + 1, L);
		}
		else
			return;
	}

	int check_delete()
	{
		bool CHK = false;

		int child_T = 0;

		for (int i = 0; i < 63; i++)
		{
			if (Node[i] != nullptr)
			{
				if (Node[i]->Vis)
				{
					if (Node[i]->End)
						child_T++;
					CHK = true;
				}
				child_T += Node[i]->check_delete();
			}
		}

		if (!CHK)
		{
			if (Vis)
				return child_T;
			return 1;
		}
		return child_T;
	}
};

Trie* root;

int T;

int main()
{
	fastio;

	cin >> T;

	while (T--)
	{
		cin >> N;

		root = new Trie();

		for (int i = 0; i < N; i++)
		{
			string S; cin >> S;

			root->Insert(S, 0, (int)S.length());
		}

		cin >> M;

		for (int i = 0; i < M; i++)
		{
			string S; cin >> S;

			root->search(S, 0, (int)S.length());
		} 

		cout << root->check_delete() << '\n';

		delete root;
	}	
}