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
 
    for(int i = 0; i < m; i++)
    {
        ll a, b, c;
 
        cin >> a >> b >> c;
 
        adj[a].push_back(make_pair(c, b));
    }
 
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
 
    pq.push(make_pair(0, 1)); // 0 -> cost, 1 -> city
 
    vector<priority_queue<ll>> routes (n + 1); //dystans od 1 do city
 
    routes[1].push(0);
 
    while(!pq.empty())
    {
        ll currCost = pq.top().first;
        ll currCity = pq.top().second;
        pq.pop();
 
        if (routes[currCity].size() == k && currCost > routes[currCity].top())
            continue;
 
        for(auto& a: adj[currCity])
        {
            if (routes[a.second].size() < k)
            {
                routes[a.second].push(currCost + a.first);
                pq.push(make_pair(currCost + a.first, a.second));
            }
            else if (currCost + a.first < routes[a.second].top())
            {
                routes[a.second].pop();
                routes[a.second].push(currCost + a.first);
                pq.push(make_pair(currCost + a.first, a.second));
            }
        }
    }
 
    vector<ll> result;
    while (!routes[n].empty()) {
        result.push_back(routes[n].top());
        routes[n].pop();
    }
 
    sort(result.begin(), result.end());
 
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
 
 
}
