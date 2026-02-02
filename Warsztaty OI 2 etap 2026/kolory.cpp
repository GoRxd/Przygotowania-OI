#include <bits/stdc++.h>

using namespace std;

int main()
{
    short Z;

    cin >> Z;

    for(int i = 0; i < Z; i++)
    {
        long long n, m, q;
        cin >> n >> m >> q;

        vector<int> kolory (n + 1);

        for(int k = 1; k <= n; k++)
        {
            cin >> kolory[k];
        }

        for(int j = 0; j < q; j++)
        {
            long long a, b;

            cin >> a >> b;
            long long suma = 0;
            //dla pierwszego wystapienia a, obliczamy sume jego dystansow

            int start;

            for(int t = 1; t <= n; t++)
            {
                if (kolory[t] == a)
                {
                    start = t;
                    break;
                }

            }

            long long d = 1;
            long long ile_lewo = 0, ile_prawo = 0;
            long long left = start - 1, right = start + 1;

            while(true)
            {
                if (left >= 1 && kolory[left] == b)
                {
                    suma += d;
                    ile_lewo++;
                }
                if (right <= n && kolory[right] == b)
                {
                    suma += d;
                    ile_prawo++;
                }

                if (left <= 0 && right > n)
                    break;

                left--;
                right++;

                d++;
            }

            for(int t = start + 1; t <= n; t++) //dla kazdego a
            {
                if (kolory[t] == a)
                {
                    suma = suma + (ile_lewo * (t - start)) - (ile_prawo * (t - start));
                }
                else if (kolory[t] == b)
                {
                    ile_prawo = max(0ll, ile_prawo - 1);
                    ile_lewo++;
                }
            }

            cout << suma << "\n";
        }
    }
}
