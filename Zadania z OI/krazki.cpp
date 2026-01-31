#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;

    cin >> n >> m;

    ll najwezszyPunkt = INT_MAX;

    vector<ll> walce (n + 1);

    for(ll i = 1; i <= n; i++)
    {
        ll r;
        cin >> r;
        walce[i] = min(r, najwezszyPunkt);
        najwezszyPunkt = min(r, najwezszyPunkt);
    }

    ll aktualnaGlebokosc = n;
    //cout << aktualnaGlebokosc << endl;
    for(ll i = 0; i < m; i++)
    {
        ll k;
        cin >> k;
        //cout << "k: " << k << "\n";]
        for(ll j = aktualnaGlebokosc; j >= 1; j--)
        {

            if (walce[j] >= k)
            {
                if (i == m - 1)
                {
                    cout << j;
                    return 0;
                }
                aktualnaGlebokosc = j - 1;
                //cout << j << endl;
                break;
            }
            else if (j == 1)
            {
                cout << 0;
                return 0;
            }
        }
    }
}
