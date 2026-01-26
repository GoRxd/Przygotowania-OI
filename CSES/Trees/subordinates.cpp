#include <bits/stdc++.h>

using namespace std;


struct Node
{
    Node* parent;
    int val;
    vector<Node*> children;

    Node(int val)
    {
        parent = nullptr;
        children = {};
        this->val = val;
    }
};

void CountSubordinates(vector<Node*>& tree, int n, vector<int>& v)
{
    stack<pair<int, Node*>> s;

    for(int i = 1; i <= n; i++)
    {
        if (tree[i]->children.size() == 0)
        {
            s.push({0, tree[i]});
            //cout << tree[i]->val << endl;
        }
    }

    while(!s.empty())
    {
        Node* currNode = s.top().second;
        s.pop();
        bool merged = false;
        while(true)
        {
            if (currNode->parent != nullptr)
            {
                if (v[currNode->parent->val] != 0 && !merged)
                {
                    v[currNode->parent->val] += v[currNode->val] + 1;
                    merged = true;
                }
                else
                {
                    v[currNode->parent->val] = v[currNode->val] + 1;
                }

                //cout << currNode->parent->val << endl;
                currNode = currNode->parent;
            }
            else
            {
                break;
            }
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<Node*> tree (n + 1);

    for(int i = 1; i <= n; i++)
    {
        tree[i] = new Node(i);
    }

    for(int i = 2; i <= n; i++)
    {
        int boss;

        cin >> boss;

        tree[boss]->children.push_back(tree[i]);
        tree[i]->parent = tree[boss];
    }


    vector<int> subordinates (n + 1, 0);
    CountSubordinates(tree, n, subordinates);
    cout << n - 1 << " ";
    for(int i = 2; i <= n; i++)
    {
        cout << subordinates[i] << " ";
    }


}
