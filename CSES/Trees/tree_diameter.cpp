#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(200001);

pair<int, int> FurthestFromNode(int node)
{
    int currFurthestNode = node;
    int furthestDist = 0;

    queue<pair<int, int>> q;
    vector<bool> visited (200001);
    visited[node] = true;
    q.push({0, node});

    while(!q.empty())
    {
        int currNode = q.front().second;
        int currDist = q.front().first;

        q.pop();

        if (currDist > furthestDist)
        {
            furthestDist = currDist;
            currFurthestNode = currNode;
        }

        for(auto& a: adj[currNode])
        {
            if (!visited[a])
            {
                visited[a] = true;
                q.push({currDist + 1, a});
            }
        }
    }

    return {furthestDist, currFurthestNode};
}

int main()
{
    int n;

    cin >> n;

    for(int i = 1; i <= n - 1; i++)
    {
        int a, b;

        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    pair<int, int> p = FurthestFromNode(1);
    pair<int, int> p1 = FurthestFromNode(p.second);

    //cout << "furthest node from 1: " << p.second << "\n";
    //cout << "distance from furthest to 1: " << p.first << "\n";
    //cout << "furthest node from " << p.second << ": " << p1.second << "\n";
    //cout << "distance from furthest to " << p.second << ": " << p1.first << "\n";

    cout << p1.first << "\n";


}
