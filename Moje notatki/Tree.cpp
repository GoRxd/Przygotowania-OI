#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n = 8;
vector<vector<int>> adj(n + 1);


struct Node
{
    ll val;
    vector<Node*> children;
};

pair<int, int> furthestNodeFromNode(int node, vector<int>* p = nullptr)
{
    queue<pair<int, int>> q;
    q.push({1, node});

    int furthestNode = 0;
    int furthestDistance = 1;

    vector<bool> visited (n + 1, false);

    while(!q.empty())
    {
        int currDist = q.front().first;
        int currNode = q.front().second;

        q.pop();

        if (currDist > furthestDistance)
        {
            furthestDistance = currDist;
            furthestNode = currNode;
        }


        for(auto& a: adj[currNode])
        {
            if (!visited[a])
            {
                if (p != nullptr)
                    p->at(a) = currNode;
                q.push({currDist + 1, a});
                visited[currNode] = true;
            }

        }
    }

    return make_pair(furthestDistance, furthestNode);

}

vector<int> TreeCenter(int startNode)
{
            //currdist, node

    vector<int> parents (n + 1);
    //length, node
    pair<int, int> furthestFromStart = furthestNodeFromNode(startNode);

    cout << furthestFromStart.second << endl;
    pair<int, int> furthestB = furthestNodeFromNode(furthestFromStart.second, &parents);
    cout << furthestB.second << endl;

    int dist = 0;
    int center = furthestB.second;

    //for(int i = 2; i <= n; i++)
    //{
       //cout << i << " " << parents[i] << endl;
    //}

    vector<int> centers;
    while(dist != (furthestB.first / 2)) //distance
    {
        center = parents[center];
        dist++;
        if (dist == (furthestB.first / 2) - 1 && furthestB.first % 2 == 0)
        {
            centers.push_back(center);
        }
    }
    centers.push_back(center);
    return centers;
}

int main()
{


    adj[1] = {2, 3};

    adj[2] = {4, 5, 1};
    adj[4].push_back(2);
    adj[5].push_back(2);

    adj[3] = {6, 7, 1};
    adj[6].push_back(3);

    adj[7] = {8, 3};
    adj[8].push_back(7);

    for(auto& c : TreeCenter(1))
    {
        cout << c << " ";
    }
}
