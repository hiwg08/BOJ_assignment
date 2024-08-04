#include <bits/stdc++.h>

using namespace std;

int n, ans = INT_MIN;

int arr[100001]{ 0 };

int dp[100001]{ 0 };

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	ans = 1, dp[0] = 1;

	for (int i = 1; i < n; i++)
	{
		if (arr[i] > arr[i - 1])
		{
			dp[i] = dp[i - 1] + 1;
		}
		else
		{
			if (dp[i - 1] >= arr[i])
			{
				dp[i] = arr[i];
			}
			else
			{
				dp[i] = dp[i - 1] + 1;
			}
		}

		ans = max(ans, dp[i]);
	}

	cout << ans;
}