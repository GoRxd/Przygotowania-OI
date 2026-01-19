/*
	https://cses.fi/problemset/task/1635/
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n, sum;

	cin >> n >> sum;

	vector<long long> coins(n);
	vector<long long> dp(sum + 1, 0);

	for(int i = 0; i < n; i++)
	{
		cin >> coins[i];
		if (coins[i] <= sum)
			dp[coins[i]] = 1;
	}

	for(long long i = 1; i <= sum; i++)
	{
		if (dp[i] != 0)
		{
			for(long long j = 0; j < coins.size(); j++)
			{
				//cout << i << " + " << coins[j] << endl;
				if (i + coins[j] <= sum)
					dp[i + coins[j]] = (dp[i] + dp[i + coins[j]]) % 1'000'000'007;
			}
		}
	}

	cout << dp[sum] << endl;
}
