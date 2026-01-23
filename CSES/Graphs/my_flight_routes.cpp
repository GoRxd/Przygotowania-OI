#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, k;

    cin >> n >> m >> k;

    vector<vector<pair<ll, ll>>> adj(n + 1);
    vector<short> counter (n + 1, 0);

    for(int i = 0; i < m; i++)
    {
        ll a, b, c;

        cin >> a >> b >> c;

        adj[a].push_back(make_pair(c, b));
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push(make_pair(0, 1));
    counter[1]++;

    vector<ll> result;

    while(!pq.empty())
    {
        ll currCost = pq.top().first;
        ll currCity = pq.top().second;

        pq.pop();

        if (counter[currCity] > k)
            continue;

        if (currCity == n)
            result.push_back(currCost);

        counter[currCity]++;
        for(auto& a: adj[currCity])
        {
            pq.push(make_pair(currCost + a.first, a.second));

        }
    }

    for(int i = 0; i < k; i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}
