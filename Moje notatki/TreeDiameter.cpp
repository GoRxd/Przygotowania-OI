#include <bits/stdc++.h>

using namespace std;

const int N = 8;

struct Node
{
    Node* parent;
    int val;
    vector<Node*> children;

    Node(int val)
    {
        parent = nullptr;
        this->val = val;
        this->children = {};
    }
};

vector<vector<int>> adj (N + 1);
vector<Node*> tree (N + 1);

pair<int, Node*> FurthestNodeFromNode(Node* node)
{
    Node* furthestNode = node;
    queue<pair<int, Node*>> q;

    q.push({0, node});
    vector<bool> visited (N + 1);

    visited[node->val] = true;

    int currMaxDist = 0;

    while(!q.empty())
    {
        Node* currNode = q.front().second;
        int currDist = q.front().first;
        q.pop();

        if (currDist > currMaxDist)
        {
            currMaxDist = currDist;
            furthestNode = currNode;
        }

        for(Node* child: currNode->children)
        {
            if (!visited[child->val])
            {
                q.push({currDist + 1, child});
                visited[child->val] = true;
            }
        }

        if (currNode->parent != nullptr)
        {
            if (!visited[currNode->parent->val])
            {
                q.push({currDist + 1, currNode->parent});
                visited[currNode->parent->val] = true;
            }
        }

    }

    return {currMaxDist, furthestNode};
}

int Diameter()
{
    Node* arbitraryNode = tree[1];

    pair<int, Node*> furthestNodeFromStart = FurthestNodeFromNode(arbitraryNode);
    pair<int, Node*> furthestNodeFromFurthestA = FurthestNodeFromNode(furthestNodeFromStart.second);
    cout << "Dist from " << tree[1]->val  << ": " << furthestNodeFromStart.first << " node: " << furthestNodeFromStart.second->val << endl;
    cout << "Dist from " << furthestNodeFromStart.second->val << ": " << furthestNodeFromFurthestA.first << " node: " << furthestNodeFromFurthestA.second->val << endl;

    return furthestNodeFromFurthestA.first;
}

vector<int> TreeCenters()
{
    if (N == 1)
        return {1};
    vector<int> degree (N + 1);

    vector<int> leaves;

    for(int i = 1; i <= N; i++)
    {
        degree[i] = adj[i].size();

        if (degree[i] == 1)
        {
            leaves.push_back(i);
        }
    }

    int remaining = N;

    while(remaining > 2)
    {
        vector<int> newLeaves;
        for(int& leaf: leaves)
        {
            degree[leaf] = 0;
            remaining--;

            for(int& leafAdj: adj[leaf])
            {
                degree[leafAdj]--;
                if (degree[leafAdj] == 1)
                    newLeaves.push_back(leafAdj);
            }
        }

        leaves = newLeaves;
    }

    return leaves;
}

void connect(int indexA, int indexB)
{
    adj[indexA].push_back(indexB);
    adj[indexB].push_back(indexA);
}

void ToTree(int rootNode)
{
    for(int i = 1; i <= N; i++)
    {
        tree[i] = new Node(i);
    }

    queue<int> q;
    vector<bool> visited (N + 1);

    q.push(rootNode);
    visited[rootNode] = true;

    while(!q.empty())
    {
        int curr = q.front();

        q.pop();

        for(auto& a: adj[curr])
        {
            if (!visited[a])
            {
                q.push(a);
                tree[a]->parent = tree[curr];
                tree[curr]->children.push_back(tree[a]);
                visited[a] = true;
            }
        }
    }
    for(int i = 1; i <= N; i++)
    {
        cout << i << ": ";

        for(auto& c: tree[i]->children)
        {
            cout << c->val << " ";
        }

        cout << "\n";
    }
}

int main()
{
    connect(1, 2);
    connect(1, 3);

    connect(2, 4);
    connect(2, 5);

    connect(3, 6);
    connect(3, 7);

    connect(7, 8);

    vector<int> treeCenters = TreeCenters();

    for(int& center: treeCenters)
    {
        cout << center << " ";
    }

    cout << "\n";

    ToTree(treeCenters[0]);

    int diameter = Diameter();

    cout << "diameter: " << diameter << endl;
}
