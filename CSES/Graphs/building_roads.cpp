#include <bits/stdc++.h>
 
using namespace std;
 
struct Road
{
	int cityA;
	int cityB;
 
	Road(int cityA, int cityB)
	{
		this->cityA = cityA;
		this->cityB = cityB;
	}
};
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int cities, roads;
 
	cin >> cities >> roads;
 
	vector<int> adj[cities + 1];
 
	for(int i = 0; i < roads; i++)
	{
		int city, connectedTo;
		cin >> city >> connectedTo;
 
		adj[city].push_back(connectedTo);
		adj[connectedTo].push_back(city); 
	}
 
	vector<Road> roadsToConstruct;
 
 
 
	vector<bool> visited (cities + 1);
 
	for(int i = 1; i <= cities; i++)
	{
		if (visited[i]) continue;
		stack<int> s;
		s.push(i);
 
		while(!s.empty())
		{
			int curr = s.top();
			visited[curr] = true;
			s.pop();
			for(int k = 0; k < adj[curr].size(); k++)
			{
				if (!visited[adj[curr][k]])
					s.push(adj[curr][k]);
			}
		}
		if (i > 1)
		{
			//musimy dodac polaczenie
			roadsToConstruct.push_back(Road(1, i));
 
			adj[1].push_back(i);
			adj[i].push_back(1);
		}
	}
 
	cout << roadsToConstruct.size() << endl;
 
	for(auto& r : roadsToConstruct)
	{
		cout << r.cityA << " " << r.cityB << "\n";
	}
}
