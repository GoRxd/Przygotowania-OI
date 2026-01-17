/*
    https://leetcode.com/problems/perfect-squares/
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
        // dla n znalesc sume rowna n, ktora ma najkrotsza ilosc perfect squarow w sobie

        // 1 (-3) 4 (-5) 9 (-7) 16 (-9) 25 (-11) 36 49

        int* perfectSquares = new int[101];
	int n;

	cin >> n;

        int toAdd = 3;

        for(int i = 1; i <= 100; i++)
        {
            if (i == 1)
                perfectSquares[i] = 1;
            else
            {
                perfectSquares[i] = perfectSquares[i - 1] + toAdd;
                toAdd += 2;
            }
        }
		
	vector<int> dp(n + 1, 1e9);

	dp[0]=0;

	for(int i = 0; i <= n; i++)
	{
		for(int j = 1; j <= 100; j++)
		{
			if (i + perfectSquares[j] <= n)
				dp[i + perfectSquares[j]] = min(dp[i + perfectSquares[j]], dp[i] + 1);
		}
	}

	cout << dp[n] << endl;


	
}

