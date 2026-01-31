
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<pair<int, int>> wyspy (n);

    for(int i = 0; i < n; i++)
    {
        cin >> wyspy[i].first >> wyspy[i].second;
    }

    vector<vector<int>> adj (n);

    for(int i = 0; i < n; i++)
    {
        for(int k = 0; k < n; k++)
        {
            if (k == i)
                continue;
            if ((wyspy[k].first > wyspy[i].first && wyspy[k].second > wyspy[i].second) || (wyspy[k].first < wyspy[i].first && wyspy[k].second < wyspy[i].second))
            {
                adj[i].push_back(k);
            }
        }
    }

    for(int i = 0; i < n; i++) //dla kazdej wyspy do kazdej wyspy dystans
    {
        queue<pair<int, int>> q;

        q.push({i, 0});

        vector<bool> visited (n);
        vector<int> distances (n, INT_MAX);
        visited[i] = true;

        while(!q.empty())
        {
            int curr = q.front().first;
            int currDist = q.front().second;

            q.pop();

            for(auto& a: adj[curr])
            {
                if (!visited[a])
                {
                    q.push({a, currDist + 1});
                    distances[a] = min(distances[a], currDist + 1);
                    visited[a] = true;
                }
            }

        }
        unsigned long long suma = 0;

        for(int j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            suma += distances[j];
        }
        cout << suma << '\n';

    }
}
