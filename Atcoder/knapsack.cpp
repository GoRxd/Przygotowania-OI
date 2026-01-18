/*
	https://atcoder.jp/contests/dp/tasks/dp_d
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n, capacity;

	cin >> n >> capacity;

	vector<long long> weights (n + 1);
	vector<long long> values (n + 1);

	vector<vector<long long>> dp (n + 1, vector<long long>(capacity + 1, 0));	

	//dp[i][waga] = maxValue;
	//i -> aktualny sprawdzany przedmiot
	//i -> moze tez byc do i - 1 sprawdzone (flaga)

	for(long long i = 1; i <= n; i++)
	{
		cin >> weights[i] >> values[i];
	}

	for(long long i = 1; i <= n; i++)
	{
		for(long long j = 1; j <= capacity; j++)
		{
			// nie branie
			dp[i][j] = max(dp[i][j], dp[i-1][j]);
			// wziecie przedmiotu

			if (j - weights[i] >= 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - weights[i]] + values[i]);
		}
	}

	long long maks = LLONG_MIN;

	for(int i = 1; i <= capacity; i++)
	{
		maks = max(maks, dp[n][capacity]);
	}

	cout << maks << endl;

}
