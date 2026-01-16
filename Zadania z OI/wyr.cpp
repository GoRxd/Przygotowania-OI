/*
	https://szkopul.edu.pl/problemset/problem/4ZyJsnINeZGNy0dfeSorm-8V/statement/
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, a, b, c;

	cin >> n >> a >> b >> c;
	
	vector<unsigned long long> dp (n + 1, 1e15);

	dp[0] = 0;
	dp[1] = a /*dla test casu dp[1] = 1*/;
	
	for(int i = 2; i <= n; i++)
	{
		dp[i] = min(dp[i], dp[i - 1] + b + a);
		unsigned long long test = 2;
		unsigned long long ile = 1;
		for(int j = 2; i * j <= n; j++)
		{
			dp[i * j] = min(dp[i * j], dp[i] + dp[j] + c);
		}
	}
	for(int i = 1; i <= n; i++)
	{
		cout << dp[i] << " ";
	}
}


