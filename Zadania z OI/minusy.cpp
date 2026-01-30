#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;

    cin >> n;

    char lastSign = '-';

    for(int i = 0; i < n - 1; i++)
    {
        char c;
        cin >> c;

        if (c != lastSign)
        {
            if (c == '+')
            {
                cout << "(-";

            }
            else
            {
                cout << ")-";
            }
        }
        else if (c == lastSign)
        {
            cout << "-";

        }

        if (i == n - 2 && c == '+')
            cout << ")";
        lastSign = c;
    }
}
