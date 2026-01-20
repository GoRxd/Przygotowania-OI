#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;

    cin >> n >> m;

    vector<int> teams (n + 1, 0);
    vector<int> adj[n + 1];

    for(int i = 0; i < m; i++)
    {
        int pupilA, pupilB;

        cin >> pupilA >> pupilB;

        adj[pupilA].push_back(pupilB);
        adj[pupilB].push_back(pupilA);
    }


    for(int i = 1; i <= n; i++)
    {
        if (teams[i] != 0)
            continue;
        queue<int> q;

        q.push(i);
        teams[i] = 1; // ustawiamy pupila 1 jako team 1

        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            for(auto& nb: adj[curr])
            {
                if (teams[nb] == 0)
                {
                    if (teams[curr] == 1)
                        teams[nb] = 2;
                    else if (teams[curr] == 2)
                        teams[nb] = 1;

                    q.push(nb);
                }
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(auto& nb: adj[i])
        {
            if (teams[nb] == teams[i])
            {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }

    //jesli nie znalazlo to jeszcze raz iterujemy i wypisujemy

    for(int i = 1; i <= n; i++)
    {
        cout << teams[i] << " ";
    }

}