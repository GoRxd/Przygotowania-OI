#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> komnaty(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> komnaty[i].first >> komnaty[i].second;
    }

    string sciezka;
    cin >> sciezka;

    int obecnaKomnata = 1;
    // odwiedzone[komnata][pozycja_w_stringu] = tura_w_ktorej_tu_bylismy
    vector<vector<long long>> odwiedzone(n + 1, vector<long long>(m, -1));

    long long tura = 0;
    long long max_krokow = k * m;

    while (tura < max_krokow)
    {
        int i = tura % m;

        if (odwiedzone[obecnaKomnata][i] != -1)
        {
            long long staraTura = odwiedzone[obecnaKomnata][i];
            long long dlugoscCyklu = tura - staraTura;
            long long pozostaloKrokow = max_krokow - tura;

            long long krokiPoSkoku = pozostaloKrokow % dlugoscCyklu;

            for (long long j = 0; j < krokiPoSkoku; j++)
            {
                int pos = (tura + j) % m;
                if (sciezka[pos] == 'L')
                    obecnaKomnata = komnaty[obecnaKomnata].first;
                else
                    obecnaKomnata = komnaty[obecnaKomnata].second;
            }

            cout << obecnaKomnata << endl;
            return 0;
        }

        odwiedzone[obecnaKomnata][i] = tura;

        if (sciezka[i] == 'L')
            obecnaKomnata = komnaty[obecnaKomnata].first;
        else
            obecnaKomnata = komnaty[obecnaKomnata].second;

        tura++;
    }

    cout << obecnaKomnata << endl;
    return 0;
}
