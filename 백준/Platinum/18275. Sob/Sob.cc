// refered to official editorial
// sol : math + greedy
// time complexity : O(N)

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

using namespace std;

ll N, M;

int main()
{
    fastio;
    
    cin >> N >> M;

    for (N--; N >= 0;)
    {
        ll tmp = M;

        while ((tmp & N) != N)
           tmp++;

        for (ll i = tmp; i >= M; i--)
        {
            cout << N << " " << i << '\n';
            N--;
        }
        M = tmp + 1;
    }
}