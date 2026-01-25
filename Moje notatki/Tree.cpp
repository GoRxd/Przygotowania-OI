#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n = 8;
vector<vector<int>> adj(n + 1);


struct Node
{
    ll val;
    Node* parent;
    vector<Node*> children;

    Node(ll val, vector<Node*> children = {})
    {
        this->val = val;
        this->children = children;
        this->parent = nullptr;
    }
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
                visited[a] = true;
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

vector<int> TreeCenter2()
{
    vector<int> degree (n + 1);
    vector<int> leaves;

    for(int i = 1; i <= n; i++)
    {
        degree[i] = adj[i].size();

        if (degree[i] == 1)
        {
            leaves.push_back(i);
        }
    }

    int removed = n;

    while(removed > 2)
    {
        vector<int> newLeaves;
        for(auto& leaf : leaves)
        {
            degree[leaf] = 0;
            removed--;
            for(auto& a: adj[leaf])
            {
                degree[a]--;

                if (degree[a] == 1)
                {
                    newLeaves.push_back(a);
                }
            }
        }

        leaves = newLeaves;
    }

    return leaves;
}

vector<Node*> BuildTree(int centerNode)
{
    vector<Node*> tree (n + 1);

    for(int i = 1; i <= n; i++)
    {
        tree[i] = new Node(i);
    }

    queue<int> q;

    q.push(centerNode);
    vector<bool> visited (n + 1);
    visited[centerNode] = true;

    while(!q.empty())
    {
        int curr = q.front();

        q.pop();

        for(auto& a: adj[curr])
        {
            if (!visited[a])
            {
                tree[a]->parent = tree[curr];
                visited[a] = true;
                tree[curr]->children.push_back(tree[a]);
                q.push(a);
            }
        }
    }

    return tree;
}

void PrintTree(Node* currNode)
{
    if (currNode == nullptr)
        return;

    cout << currNode->val << ": ";

    for(auto& c: currNode->children)
    {
        cout << c->val << " ";
    }
    cout << "\n";

    for(auto& c: currNode->children)
    {
        PrintTree(c);
    }

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

    vector<int> centers = TreeCenter2();

    for(auto& c : centers)
    {
        cout << c << " ";
    }
    cout << "\n";

    vector<Node*> tree = BuildTree(centers[0]);

    PrintTree(tree[centers[0]]);


}
