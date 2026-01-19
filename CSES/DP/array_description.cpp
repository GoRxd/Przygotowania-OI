/*
	https://cses.fi/problemset/task/1746/
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	long long n, m;
 
	cin >> n >> m;
 
	vector<long long> nums (n);
	vector<vector<long long>> dp (n + 1, vector<long long>(m + 1, 0));
 
	for(long long i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
 
	if (nums[0] == 0)
	{
		for(long long i = 0; i <= m; i++)
		{
			dp[0][i] = 1;
		}
	}
	else
		dp[0][nums[0]] = 1; // dla 2 0 3, to bedzie dp[0][2]=1
 
 
	for(long long i = 0; i < n - 1; i++)//wysokosc drzewa
	{
		for(long long k = 1; k <= m; k++) //iterujemy po kazdej mozliwej kulce w danym depth
		{
			if (dp[i][k] != 0 && nums[i + 1] == 0)
			{
				for(long long j = k - 1; j <= k + 1; j++)
				{
					if (j >= 1 && j <= m && abs(k - j) <= 1)
						dp[i + 1][j] = (dp[i][k] + dp[i + 1][j]) % 1'000'000'007;
				}
			}
			else if (nums[i + 1] != 0)
			{
				for(long long j = nums[i + 1] - 1; j <= nums[i + 1] + 1; j++)
				{
					if (j >= 1 && j <= m)
						dp[i + 1][nums[i + 1]] = (dp[i][j] + dp[i + 1][nums[i + 1]]) % 1'000'000'007;
				}
				break;
			}
 
		
		}
	}
	/*
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= m; j++)
		{
			if (dp[i][j] != 0)
				printf("dp[%d][%d]: %d\n", i, j, dp[i][j]);
		}
	}
	*/
	
	long long ways = 0;
 
	for(int k = 1; k <= m; k++)
	{
		ways = (ways + dp[n - 1][k]) % 1'000'000'007;
	}
 
	cout << ways << endl;
}