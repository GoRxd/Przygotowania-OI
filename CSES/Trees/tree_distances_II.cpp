#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<vector<int>> adj (200001);
vector<ll> subtree (200001, 0);
vector<ll> ans (200001, 0);

void dfs(int currNode, int parentNode, int depth)
{
    ans[1] += depth;
    subtree[currNode] = 1;
    for(auto& a: adj[currNode])
    {
        if (a != parentNode)
        {
            dfs(a, currNode, depth + 1);
            subtree[currNode] += subtree[a];
        }
    }
}

void dfs_dp(int currNode, int parent, int n)
{
    for(auto& a : adj[currNode])
    {
        if (a != parent)
        {
            ans[a] = ans[currNode] - subtree[a] + (n - subtree[a]);
            dfs_dp(a, currNode, n);
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

    dfs(1, 0, 0);

    dfs_dp(1, 0, n);

    for(int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
}
