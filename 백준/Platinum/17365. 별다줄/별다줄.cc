#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define MOD (ll)(1e9 + 7)
using namespace std;

class Trie
{
public:
	Trie* Node[26];
	ll mine;

	Trie()
	{
		fill(Node, Node + 26, nullptr);
		mine = 0;
	}

	~Trie()
	{
		for (ll i = 0; i < 26; i++)
		{
			if (Node[i] != nullptr)
				delete Node[i];
		}
	}

	ll get_ans(string S, ll Idx, ll L)
	{
		if (Idx >= L)
			return 0;

		ll al = (ll)(S[Idx] - 'a');

		if (Idx == (ll)S.length() - 1)
		{
			if (Node[al] == nullptr)
				return 0;
			return Node[al]->mine;
		}

		if (Idx >= L)
			return 0;

		if (Node[al] == nullptr)
			return 0;

		return Node[al]->get_ans(S, Idx + 1, L);
	}

	void Insert(string S, ll Idx, ll L)
	{
		if (Idx >= L)
			return;

		ll al = (ll)(S[Idx] - 'a');

		if (Node[al] == nullptr)
		{
			Node[al] = new Trie();
			Node[al]->mine++;
		}
		else
			Node[al]->mine++;

		Node[al]->Insert(S, Idx + 1, L);
	}
};

ll N;

Trie* root;

ll DP[200001]{ 0 };

string comp;

void mul_mod(ll& ret, ll params)
{
	ret *= params;
	ret %= MOD;
}

void add_mod(ll& ret, ll params)
{
	ret += params;
	ret %= MOD;
}

ll solve(ll Idx) // 방법의 수
{
	if (Idx >= (ll)comp.length())
		return 1;

	ll& ret = DP[Idx];

	if (ret != -1)
		return ret;

	ret = 0;

	bool chk = false;

	string C = "";

	Trie* P = root;

	for (ll i = Idx; i < (ll)comp.size(); i++)
	{
		C = "";

		C += comp[i];

		ll R = P->get_ans(C, 0, (ll)C.length());

		ll al = (ll)(comp[i] - 'a');

		P = P->Node[al];

		if (R >= 1)
		{
			ll Q = R;
			mul_mod(Q, solve(i + 1));
			add_mod(ret, Q);
		}
		else
			break;
	}

	return ret;
}

int main()
{
	fastio;

	cin >> N;

	root = new Trie();

	for (ll i = 0; i < N; i++)
	{
		string S; cin >> S;
		root->Insert(S, 0, (ll)S.length());
	}

	cin >> comp;

	memset(DP, -1, sizeof(DP));

	cout << solve(0);

	delete root;
}