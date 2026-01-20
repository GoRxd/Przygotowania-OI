#include <bits/stdc++.h>

using namespace std;

struct Computer
{

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    vector<int> adj[n + 1];
    
    for(int i = 0; i < m; i++)
    {
        int compA, compB;

        cin >> compA >> compB;

        adj[compA].push_back(compB);
        adj[compB].push_back(compA);
    }

    bool visited[n + 1] {};
    int costs[n + 1] {};
    int cost = 1;

    queue<int> q;
    q.push(1);
    costs[1] = 1;
    visited[1] = true;


    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(auto& ng : adj[curr])
        {
            if (!visited[ng])
            {
                visited[ng] = true;
                costs[ng] = costs[curr] + 1;
                q.push(ng);
            }
        }
    }

    if (costs[n] == 0)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    int curr = n;
    cout << costs[n] << endl;

    vector<int> result;

    result.push_back(n);
    while(true)
    {
        if (costs[curr] == 1)
            break;
        for(auto& ng : adj[curr])
        {
            if (costs[ng] == costs[curr] - 1)
            {
                result.push_back(ng);
                curr = ng;
                break;
            }
        }
    }

    for(int i = costs[n] - 1; i >= 0; i--)
    {
        cout << result[i] << " ";
    }
}