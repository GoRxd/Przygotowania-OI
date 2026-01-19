#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string first, second;
	cin >> first >> second;

	vector<vector<int>> dp (first.size() + 1, vector<int>(second.size() + 1, 1e9));

	dp[0][0] = 0;

	for(int i = 0; i <= first.size(); i++)
	{
		for(int j = 0; j <= second.size(); j++)
		{
			if (first[i] != second[j])
			{
				//dodawanie
				if (j + 1 <= second.size())
					dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);

				//usuwanie
				if (i + 1 <= first.size())
					dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);

				//zamiana
				if (i + 1 <= first.size() && j + 1 <= second.size())
					dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + 1);
			}
			else
			{
				//zostawiamy idziemy dalej
				if (i + 1 <= first.size() && j + 1 <= second.size())
					dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
			}
		}
	}

	cout << dp[first.size()][second.size()] << endl;
}
