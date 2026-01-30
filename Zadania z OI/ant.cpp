#include <iostream>

using namespace std;

long long pierwsze[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

long long n;
long long najlepsza_liczba = 0;
long long max_dzielnikow = 0;

//algorytm znajdywania tych liczb antypierwszych:

void szukaj(int idx, long long aktualna, long long ile_dziel, int limit_wyklad) {

    if (ile_dziel > max_dzielnikow)
    {
        max_dzielnikow = ile_dziel;
        najlepsza_liczba = aktualna;
    }
    else if (ile_dziel == max_dzielnikow)
    {
        if (aktualna < najlepsza_liczba)
        {
            najlepsza_liczba = aktualna;
        }
    }

    if (idx == 10) return;

    long long p = aktualna;

    for (int i = 1; i <= limit_wyklad; i++)
    {
        if (n / pierwsze[idx] < p) break;

        p *= pierwsze[idx];

        szukaj(idx + 1, p, ile_dziel * (i + 1), i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n)) return 0;

    szukaj(0, 1, 1, 31);

    cout << najlepsza_liczba << endl;

    return 0;
}
