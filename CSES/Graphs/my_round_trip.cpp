#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 200005;
vector<bool> visited(MAXN, false);
vector<ll> parents(MAXN, -1);
vector<vector<ll>> adj(MAXN);

ll cycle_start = -1, cycle_end = -1;

bool DFS(ll curr, ll par)
{
    visited[curr] = true;
    parents[curr] = par;

    for(auto& a: adj[curr])
    {
        if(a == par) continue;

        if (visited[a])
        {
            cycle_start = a;
            cycle_end = curr;
            return true;
        }
        else
        {
            if (DFS(a, curr)) return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i] && DFS(i, -1))
        {
            break;
        }
    }

    if (cycle_start == -1)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        vector<ll> cycle;
        cycle.push_back(cycle_start);

        for (ll v = cycle_end; v != cycle_start; v = parents[v])
        {
            cycle.push_back(v);
        }
        cycle.push_back(cycle_start);

        cout << cycle.size() << endl;
        for(auto v : cycle) cout << v << " ";
        cout << endl;
    }

    return 0;
}
