#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;

    cin >> n >> m;

    vector<pair<int, int>> adj[n + 1]; // {sąsiad, waga}

    for(int i = 0; i < m; i++)
    {
        ll a, b, c;

        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<ll> distances (n + 1, 1e15);

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    distances[1] = 0;
    pq.push({0, 1}); // Syrjälä

    while(!pq.empty())
    {
        ll d = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (d > distances[curr])
            continue;

        for(auto& nb: adj[curr])
        {
            //cout << "curr: " << curr << " | nb: " << nb.first << endl;
            //cout << "distances[nb]: " << distances[nb.first] << " > " << distances[curr] + nb.second << endl;
            if (distances[nb.first] == 1e15 || distances[nb.first] > distances[curr] + nb.second)
            {
                distances[nb.first] = distances[curr] + nb.second;
                pq.push({distances[nb.first], nb.first});
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        cout << distances[i] << " ";
    }

    
}