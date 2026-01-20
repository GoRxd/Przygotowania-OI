/*
	https://cses.fi/problemset/task/1193
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

	Pos operator+(const Pos& other) const
	{
		return Pos(this->y + other.y, this->x + other.x);
	}

	bool operator==(const Pos& other) const
	{
		return this->x == other.x && this->y == other.y;
	}
};

static vector<vector<int>> BFS(Pos start, vector<vector<bool>>& visited, vector<vector<char>>& map)
{
	vector<vector<int>> distances (map.size(), vector<int>(map[0].size(), -1));
	queue<Pos> q;

	q.push(start);
	visited[start.y][start.x] = true;
	distances[start.y][start.x] = 0;

	Pos directions[4] = { Pos(1, 0), Pos(-1, 0), Pos(0, 1), Pos(0, -1) };

	while(!q.empty())
	{
		for(int i = 0; i < 4; i++)
		{
			Pos curr = q.front() + directions[i];

			if (curr.y >= 0 && curr.y < map.size() && curr.x >= 0 && curr.x < map[0].size())
			{
				if (map[curr.y][curr.x] != '#' && !visited[curr.y][curr.x])
				{
					q.push(curr);
					visited[curr.y][curr.x] = true;
					distances[curr.y][curr.x] = (distances[q.front().y][q.front().x] + 1);
				}
			}
		}
		q.pop();
	}

	return distances;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;

	cin >> n >> m;

	vector<vector<char>> map (n, vector<char>(m));
	vector<vector<bool>> visited (n, vector<bool>(m));


	Pos start(-1, -1);
	Pos end(-1, -1);

	for(int y = 0; y < n; y++)
	{
		for(int x = 0; x < m; x++)
		{
			cin >> map[y][x];

			if (map[y][x] == 'A')
			{
				start = Pos(y, x);
			}
			else if (map[y][x] == 'B')
			{
				end = Pos(y, x);
			}
		}
	}

	vector<vector<int>> distances = BFS(start, visited, map);
	/*
	for(int y = 0; y < n; y++)
	{
		for(int x = 0; x < m; x++)
		{
			if (distances[y][x] == -1)
				cout << "#";
			else
				cout << distances[y][x];
		}
		cout << endl;
	}
	*/

	string path="";
	Pos currPos = end;

	if (distances[currPos.y][currPos.x] == -1)
	{
		cout << "NO";
		return 0;
	}

	Pos directions[4] = {Pos(1, 0), Pos(-1, 0), Pos(0, 1), Pos(0, -1)};
	char posToChar[4] = {'U', 'D', 'L', 'R'};

	bool is_end = false;

	while(true)
	{
		for(int i = 0; i < 4; i++)
		{
			Pos next = currPos + directions[i];

			if (next.y >= 0 && next.y < map.size() && next.x >= 0 && next.x < map[0].size())
			{
				if (distances[next.y][next.x] == distances[currPos.y][currPos.x] - 1)
				{
					currPos = next;
					path += posToChar[i];
					if (distances[currPos.y][currPos.x] == 0)
						is_end = true;
					break;
				}
			}
		}
		
		if (is_end)
			break;
		
	}

	cout << "YES" << endl;
	cout << distances[end.y][end.x] << endl;

	for(int i = path.size() - 1; i >= 0; i--)
	{
		cout << path[i];
	}

}
