/*
	https://cses.fi/problemset/task/1637
*/
#include <bits/stdc++.h>

using namespace std;

void updateDigits(vector<int>& digits, int n)
{
	digits.clear();
	while(true)
	{
		digits.push_back(n % 10);
		n /= 10;

		if (n == 0)
			break;
	}
}

int main()
{
	int n;

	cin >> n;

	vector<long long> dp (n + 1, 1e9);
	vector<int> digits;

	dp[n] = 0;

	for(int i = n; i >= 0; i--)
	{
		if (dp[n] == 1e9)
			continue;
		updateDigits(digits, i);

		for(int j = 0; j < digits.size(); j++)
		{
			
			//cout << "dp[ " << i - digits[j] << "]" << endl;
			//cout << "dp[i - digits[j]]: " << dp[i - digits[j]] << " = " << min(dp[i - digits[j]], dp[i] + 1) << endl;
			dp[i - digits[j]] = min(dp[i - digits[j]], dp[i] + 1);
		}
	}

	cout << dp[0] << endl;

	return 0;
}
