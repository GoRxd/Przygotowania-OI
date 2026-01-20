#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> parent(n + 1, 0);
    vector<bool> visited(n + 1, false);
    vector<int> head(n + 1, 0); 

    for(int i = 1; i <= n; i++)
    {
        if(visited[i]) continue;

        stack<int> s;
        s.push(i);
        visited[i] = true;
        parent[i] = -1;

        while(!s.empty())
        {
            int curr = s.top();
            
            if(head[curr] < adj[curr].size())
            {
                int nb = adj[curr][head[curr]];
                head[curr]++; 

                if(nb == parent[curr]) continue;

                if(visited[nb])
                {
                    // ZNALEŹLISMY CYKL!
                    vector<int> cycle;
                    int temp = curr;
                    while(temp != nb)
                    {
                        cycle.push_back(temp);
                        temp = parent[temp];
                    }
                    cycle.push_back(nb);
                    cycle.push_back(curr);

                    cout << cycle.size() << endl;
                    for(int city : cycle)
                    {
                        cout << city << " ";
                    }
                    return 0;
                }
                else
                {
                    visited[nb] = true;
                    parent[nb] = curr;
                    s.push(nb);
                }
            }
            else
            {
                s.pop();
            }
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}