#include <bits/stdc++.h>

using namespace std;

struct Node
{
    Node* parent;
    vector<Node*> children;
    int val;

    Node(int val)
    {
        this->val = val;
        parent = nullptr;
        children = {};
    }
};

void CalcSubordinates(Node* node, vector<int>& subordinates)
{
    for(auto& c: node->children)
    {
         CalcSubordinates(c, subordinates);
    }
    if (node->parent != nullptr)
        subordinates[node->parent->val] += subordinates[node->val] + 1;
}

int main()
{
    int n;
    cin >> n;

    vector<Node*> tree (n + 1);
    vector<int> subordinates (n + 1, 0);

    for(int i = 1; i <= n; i++)
    {
        tree[i] = new Node(i);
    }

    for(int i = 2; i <= n; i++)
    {
        int par;
        cin >> par;
        tree[i]->parent = tree[par];
        tree[par]->children.push_back(tree[i]);
    }

    CalcSubordinates(tree[1], subordinates);
    for(int i = 1; i <= n; i++)
    {
        cout << subordinates[i] << " ";
    }
}
