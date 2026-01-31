
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;

    cin >> n >> m >> k;

    vector<pair<int, int>> komnaty (n + 1);

    for(int i = 1; i <= n; i++)
    {
        int l, p;
        cin >> l >> p;

        komnaty[i].first = l;
        komnaty[i].second = p;
    }

    string sciezka;
    cin >> sciezka;

    int obecnaKomnata = 1;

    for(int j = 0; j < k; j++)
    {
        for(int i = 0; i < sciezka.size(); i++)
        {
            if (sciezka[i] == 'L')
                obecnaKomnata = komnaty[obecnaKomnata].first;
            else if (sciezka[i] == 'P')
                obecnaKomnata = komnaty[obecnaKomnata].second;
        }
    }

    cout << obecnaKomnata << endl;
}
