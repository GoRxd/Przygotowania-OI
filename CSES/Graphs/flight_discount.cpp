#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
    ll n, m;

    cin >> n >> m;

    //adj[1] = {4, 5) (4 -> koszt, 5 -> sasiad)
    vector<vector<pair<ll, ll>>> adj(n + 1);
    vector<vector<ll>> distances (n + 1, vector<ll>(2, 1e18));

    for(int i = 0; i < m; i++)
    {
        ll a, b, c;

        cin >> a >> b >> c;

        adj[a].push_back(make_pair(c, b));
    }
    //{koszt, pokoj}

    priority_queue<tuple<ll, ll, bool>, vector<tuple<ll, ll, bool>>, greater<tuple<ll, ll, bool>>> pq;

    pq.push(make_tuple(0, 1, 0));
    distances[1][0] = 0;
    distances[1][1] = 0;

    while(!pq.empty())
    {
        auto [currCost, currRoom, state] = pq.top();

        pq.pop();

        if (currCost > distances[currRoom][state])
            continue;

        for(auto& a : adj[currRoom])
        {
            if (distances[currRoom][state] + a.first < distances[a.second][state])
            {
                distances[a.second][state] = distances[currRoom][state] + a.first;
                pq.push(make_tuple(distances[a.second][state], a.second, state));
            }
            if (state == 0)
            {
                if (distances[currRoom][0] + (a.first / 2) < distances[a.second][1])
                {
                    distances[a.second][1] = distances[currRoom][0] + (a.first / 2);
                    pq.push(make_tuple(distances[a.second][1], a.second, 1));
                }
            }

        }
    }

    cout << distances[n][1] << endl;
    return 0;
}
