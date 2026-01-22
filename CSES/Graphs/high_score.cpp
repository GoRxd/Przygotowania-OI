#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;

    cin >> n >> m;

                      //koszt | room
    vector<vector<pair<ll, ll>>> adj (n + 1);

    vector<ll> distances(n + 1, -1e18); // from room 1 to given room

    for(ll i = 0; i < m; i++)
    {
        ll a, b, x;

        cin >> a >> b >> x;

        adj[a].push_back(make_pair(x, b));
    }

    distances[1] = 0;

    for(int i = 1; i <= n - 1; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if (distances[j] == -1e18)
                continue;
            for(auto& a: adj[j])
            {
                if (distances[j] + a.first > distances[a.second])
                {
                    distances[a.second] = distances[j] + a.first;
                }
            }
        }

    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if (distances[j] == -1e18) continue;

            for(auto& a : adj[j])
            {
                if (distances[j] == 1e18)
                {
                    distances[a.second] = 1e18;
                }
                else if (distances[j] + a.first > distances[a.second])
                {
                    distances[a.second] = 1e18;
                }
            }
        }
    }


    if(distances[n] == 1e18) cout << -1 << endl;
    else cout << distances[n] << endl;
    return 0;
}
