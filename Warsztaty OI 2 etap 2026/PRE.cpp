#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q;

    cin >> n >> q;

    vector<ll> ciag(n + 1);

    for(ll i = 1; i <= n; i++)
    {
        cin >> ciag[i];
    }
    vector<ll> tablicaB (n);
    for(ll i = 0; i < q; i++)
    {
        ll left, right, rozmiarPamieci, cel;

        cin >> left >> right >> rozmiarPamieci >> cel;

        multiset<ll> pamiecRobota;

        auto liczbaCel = 0;
        ll rozmiarTablicyB = 0;

        for(ll j = left; j <= right; j++)
        {
            pamiecRobota.insert(ciag[j]);

            if (pamiecRobota.size() == rozmiarPamieci || j == right)
            {
                rozmiarTablicyB++;
                tablicaB[rozmiarTablicyB - 1] = *pamiecRobota.begin();
                //cout << pamiecRobota.size() << " " << j << " == " << right << " " << rozmiarTablicyB << endl;
                pamiecRobota.erase(pamiecRobota.begin());
                if (rozmiarTablicyB >= cel)
                {
                    pamiecRobota.clear();
                    break;
                }
            }
        }
        while (pamiecRobota.size() > 0)
        {
            tablicaB[rozmiarTablicyB] = *pamiecRobota.begin();
            rozmiarTablicyB++;
            pamiecRobota.erase(pamiecRobota.begin());

            if (rozmiarTablicyB >= cel)
                break;
        }

        cout << tablicaB[cel - 1] << "\n";
        tablicaB.clear();
    }
}
