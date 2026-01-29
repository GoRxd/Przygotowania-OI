#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, cel;

    cin >> n >> cel;

    vector<long long> ciag (n + 1);

    long long sumaMin = 0;

    ciag[0] = -1;
    ciag[1] = 0;

    for(int i = 2; i <= n; i++)
    {
        ciag[i] = ciag[i - 1] - 1;
        sumaMin += ciag[i];
    }

    vector<int> kroki (n + 1, -1);

    if (n == 1 && cel == 0)
    {
        cout << 0;
        return 0;
    }
    else if (n == 1 && cel != 0)
    {
        cout << "NIE";
        return 0;
    }

    if (sumaMin <= cel)
    {
        for(int i = 2; i <= n; i++)
        {
            if (sumaMin < cel && sumaMin + (n - i + 1) * 2 <= cel)
            {
                ciag[i] = ciag[i - 1] + 1;
                sumaMin +=  (n - i + 1) * 2;
                kroki[i] = 1;
                //cout << sumaMin << endl;

            }
            if (sumaMin == cel)
            {
                for(int j = 1; j <= n; j++)
                {
                    if (abs(ciag[j] - ciag[j - 1]) != 1)
                    {
                        if (kroki[j] == 1)
                        {
                            ciag[j] = ciag[j - 1] + 1;
                        }
                        else
                        {
                            ciag[j] = ciag[j - 1] - 1;
                        }
                    }
                    cout << ciag[j] << "\n";

                }
                return 0;
            }
        }
    }

    cout << "NIE" << endl;
}
