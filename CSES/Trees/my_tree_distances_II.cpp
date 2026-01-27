#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
    queue<tuple<ll, ll, ll, ll>> q;

    int n;
    cin >> n;

    vector<vector<int>> adj (n + 1);
    vector<ll> sums (n + 1, 0);

    for(int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
        q.push({0, i, i, i}); //sum, currentNode, prevNode, originalNode
    }

    q.push({0, n, n, n});

    while(!q.empty())
    {
        auto [sum, currentNode, previousNode, originalNode] = q.front();
        q.pop();

        for(auto& a: adj[currentNode])
        {
            if (a != previousNode)
            {
                sums[originalNode] += sum + 1;
                q.push({sum + 1, a, currentNode, originalNode});
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        cout << sums[i] << " ";
    }
}
