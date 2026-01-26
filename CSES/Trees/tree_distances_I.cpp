#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj (200001);

pair<int, int> FurthestNodeFromNode(int node)
{
    int currFurthestNode = node;
    int currFurthestDist = 0;

    queue<pair<int, int>> q;
    vector<bool> visited (200001);

    q.push({currFurthestDist, currFurthestNode});

    visited[node] = true;

    while(!q.empty())
    {
        int currNode = q.front().second;
        int currDist = q.front().first;

        q.pop();

        if (currDist > currFurthestDist)
        {
            currFurthestDist = currDist;
            currFurthestNode = currNode;
        }

        for(auto& a: adj[currNode])
        {
            if (!visited[a])
            {
                q.push({currDist + 1, a});
                visited[a] = true;
            }
        }
    }

    return {currFurthestDist, currFurthestNode};
}

void FillDistances(int startNode, vector<int>& maxDistances, int n)
{
    queue<pair<int, int>> q;
    vector<bool> visited (n + 1);
    q.push({0, startNode});
    visited[startNode] = true;

    while(!q.empty())
    {
        auto [currDist, currNode] = q.front();

        q.pop();

        for(auto& a: adj[currNode])
        {
            if (!visited[a])
            {
                maxDistances[a] = max(currDist + 1, maxDistances[a]);
                q.push({currDist + 1, a});
                visited[a] = true;
            }
        }
    }
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

    pair<int, int> furthestA = FurthestNodeFromNode(1);
    pair<int, int> furthestB = FurthestNodeFromNode(furthestA.second);

    int diameter = furthestB.first;

    //cout << diameter << endl;

    vector<int> maxDistances (n + 1, 0);

    maxDistances[furthestA.second] = diameter;
    maxDistances[furthestB.second] = diameter;

    FillDistances(furthestA.second, maxDistances, n);
    FillDistances(furthestB.second, maxDistances, n);

    for(int i = 1; i <= n; i++)
    {
        cout << maxDistances[i] << " ";
    }

}
