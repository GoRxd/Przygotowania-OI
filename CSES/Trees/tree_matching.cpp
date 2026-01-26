#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj (200001);
vector<bool> matched (200001);
int pairs = 0;

void Match(int currNode, int parent)
{
    for(auto& a: adj[currNode])
    {
        if (a == parent)
            continue;
        Match(a, currNode);
    }

    if (!matched[parent] && !matched[currNode] && parent != 0)
    {
        matched[parent] = true;
        matched[currNode] = true;
        pairs++;
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

    Match(1, 0);

    cout << pairs << endl;
}
