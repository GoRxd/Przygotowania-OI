/*
	https://cses.fi/problemset/task/1192
*/
#include <bits/stdc++.h>
#include <queue>

using namespace std;

struct Pos
{
	int y;
	int x;
	Pos(int y, int x)
	{
		this->y = y;
		this->x = x;
	}
};

static void BFS(int y, int x, vector<vector<bool>>& visited, vector<vector<char>>& map)
{
	queue<Pos> q;

	q.push(Pos(y, x));
	visited[y][x] = true;

	while(!q.empty())
	{
		Pos curr = q.front();
		q.pop();

		if (curr.y + 1 < map.size() && curr.x >= 0 && curr.x < map[0].size()) //top
		{
			if (map[curr.y + 1][curr.x] != '#' && !visited[curr.y + 1][curr.x])
			{
				q.push(Pos(curr.y + 1, curr.x));
				visited[curr.y + 1][curr.x] = true;
			}
		}

		if (curr.y - 1 >= 0 && curr.x >= 0 && curr.x < map[0].size()) // bottom
		{
			if (map[curr.y - 1][curr.x] != '#' && !visited[curr.y - 1][curr.x])
			{
				q.push(Pos(curr.y - 1, curr.x));
				visited[curr.y - 1][curr.x] = true;
			}
		}

		if (curr.x + 1 < map[0].size() && curr.y < map.size() && curr.y >= 0)
		{
			if (map[curr.y][curr.x + 1] != '#' && !visited[curr.y][curr.x + 1])
			{
				q.push(Pos(curr.y, curr.x + 1));
				visited[curr.y][curr.x + 1] = true;
			}
		}

		if (curr.x - 1 >= 0 && curr.y < map.size() && curr.y >= 0)
		{
			if (map[curr.y][curr.x - 1] != '#' && !visited[curr.y][curr.x - 1])
			{
				q.push(Pos(curr.y, curr.x - 1));
				visited[curr.y][curr.x - 1] = true;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, rooms=0;

	cin >> n >> m;

	vector<vector<bool>> visited (n, vector<bool>(m));

	vector<vector<char>> map (n, vector<char>(m));

	for(int y = 0; y < n; y++)
	{
		for(int x = 0; x < m; x++)
		{
			cin >> map[y][x];
		}
	}

	for(int y = 0; y < n; y++)
	{
		for(int x = 0; x < m; x++)
		{
			if (!visited[y][x] && map[y][x] != '#')
			{
				BFS(y, x, visited, map);
				rooms++;
			}
		}
	}

	cout << rooms << endl;
}

