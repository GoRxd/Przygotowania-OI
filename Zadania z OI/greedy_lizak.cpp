#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> przedzial;
vector<int> smak;

void Spamietaj(int l, int r, int suma)
{
    przedzial[suma] = {l, r};

    if (suma >= 3)
    {
        if (smak[l] == 2)
        {
            Spamietaj(l + 1, r, suma - 2);
        }
        else if (smak[r] == 2)
        {
            Spamietaj(l, r - 1, suma - 2);
        }
        else
        {
            Spamietaj(l + 1, r - 1, suma - 2); //bo w tym przypadku sa 2 waniliowe
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;

    cin >> n >> m;


    smak.resize(n + 1);
    int suma = 0;

    int pierwszaW = -1, ostatniaW = -1;

    vector<int> sp (n + 1, 0);

    for(int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;

        if (c == 'T')
            smak[i] = 2;
        else
        {
            smak[i] = 1;
            if (pierwszaW == -1)
                pierwszaW = i;

            ostatniaW = i;
        }

        suma += smak[i];
        sp[i] = sp[i - 1] + smak[i];
    }
    przedzial.resize(suma + 1);
    Spamietaj(1, n, suma);
    //przedzial[k] = (l, r);

    int sumaOdejmujacPierwszaW = -1;
    int sumaOdejmujacOstatniaW = -1;

    if (pierwszaW != -1)
    {
        sumaOdejmujacPierwszaW = sp[n] - sp[pierwszaW];
    }
    if (ostatniaW != -1)
    {
        sumaOdejmujacOstatniaW = sp[ostatniaW - 1];
    }
    if (sumaOdejmujacPierwszaW > sumaOdejmujacOstatniaW)
    {
        Spamietaj(pierwszaW + 1, n, sumaOdejmujacPierwszaW);
    }
    else if (sumaOdejmujacOstatniaW != -1)
    {
        Spamietaj(1, ostatniaW - 1, sumaOdejmujacOstatniaW);
    }

    for(int i = 0; i < m; i++)
    {
        int k;

        cin >> k;

        if (k > suma || przedzial[k].first == 0 && przedzial[k].second == 0)
            cout << "NIE\n";

        else
            cout << przedzial[k].first << " " << przedzial[k].second << "\n";
    }
}
