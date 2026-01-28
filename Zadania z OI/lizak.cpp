#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;

    cin >> n >> m;

    vector<int> sp (n + 1, 0);

    for(int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;

        int valToAdd = c == 'T' ? 2 : 1;

        if (i == 1)
        {
            sp[i] = valToAdd;
        }
        else
        {
            sp[i] = sp[i - 1] + valToAdd;
        }
    }

    for(int i = 0; i < m; i++)
    {
        int k;

        cin >> k;

        int left = 1;
        int right = 1;

        bool found = false;

        while(true)
        {
            int sum = sp[right] - sp[left - 1];
            //cout << "sum: " << sum << endl;
            if (sum == k)
            {
                cout << left << " " << right << "\n";
                found = true;
                break;
            }

            else if (sum < k)
            {
                right++;
            }

            else if (sum > k)
            {
                left++;
            }

            if (right == n + 1 || left == n + 1)
                break;
        }

        if (!found)
        {
            cout << "NIE\n";
        }
    }
}
