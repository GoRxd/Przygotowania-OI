#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;

    cin >> n >> m;
                    //cost, node
    vector<vector<pair<ll, ll>>> adj (n + 1);


    for(int i = 0; i < m; i++)
    {
        ll a, b, c;

        cin >> a >> b >> c;

        adj[a].push_back(make_pair(c, b));
    }

    vector<ll> distances (n + 1, 1e18);
    vector<ll> parents (n + 1);
    distances[1] = 0;
    parents[1] = 0;


    ll last_changed_node = -1;

    for(int i = 1; i <= n; i++)
    {
        last_changed_node = -1; // reset every round, to be able to check if changed on last round
        for(int j = 1; j <= n; j++)
        {
            for(auto& a: adj[j])
            {

                if (distances[j] + a.first < distances[a.second])
                {
                    distances[a.second] = distances[j] + a.first;
                    parents[a.second] = j;
                    last_changed_node = a.second;
                }
            }
        }
    }

    if (last_changed_node == -1)
    {
        cout << "NO";
    }
    else
    {
        for(int i = 1; i <= n; i++)
        {
            last_changed_node = parents[last_changed_node];
        }

        vector<ll> cycle;
        ll curr = last_changed_node;

        while(true)
        {
            cycle.push_back(curr);
            if (curr == last_changed_node && cycle.size() > 1) // bysmy nie porownywali 1 z 1 np
                break;
            curr = parents[curr];
        }

        reverse(cycle.begin(), cycle.end());

        cout << "YES\n";
        for(int i = 0; i < cycle.size(); i++)
        {
            cout << cycle[i] << " ";
        }
    }
}
