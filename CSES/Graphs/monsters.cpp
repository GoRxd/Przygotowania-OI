#include <bits/stdc++.h>
 
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
 
    Pos operator+(const Pos& other) const{
        return Pos(this->y + other.y, this->x + other.x);
    }
};
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int height, width;
 
    cin >> height >> width;
 
    vector<vector<char>> map (height, vector<char>(width));
    vector<vector<int>> distances(height, vector<int>(width, 1e9));
    vector<Pos> exits;
    Pos playerPos(-1, -1);
    queue<Pos> q;
 
    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            cin >> map[y][x];
 
            if (map[y][x] == 'M')
            {
                q.push(Pos(y, x)); // dodajemy monstera do kolejki
                distances[y][x] = 0;
            }
            if (map[y][x] == 'A')
            {
                playerPos = Pos(y, x);
            }
 
            if ((y == 0 || y == height - 1 || x == 0 || x == width - 1))
            {
                if (map[y][x] == '.')
                    exits.push_back(Pos(y, x));
                else if (map[y][x] == 'A')
                {
                    cout << "YES\n0";
                    return 0;
                }
            }
        }
    }
 
 
    Pos directions[4] = {Pos(1, 0), Pos(-1, 0), Pos(0, 1), Pos(0,-1)};
    char dirToChar[4] = {'U', 'D', 'L', 'R'};
    
    //najpierw puszczamy BFS-a dla kazdego monstera naraz
    while(!q.empty())
    {
        Pos curr = q.front();
 
        q.pop();
 
        for(int i = 0; i < 4; i++)
        {
            Pos currPos = curr + directions[i];
 
            if (currPos.y >= 0 && currPos.y < height && currPos.x >= 0 && currPos.x < width)
            {
                if (map[currPos.y][currPos.x] != '#')
                {
                    if (distances[currPos.y][currPos.x] > distances[curr.y][curr.x] + 1)
                    {
                        distances[currPos.y][currPos.x] = distances[curr.y][curr.x] + 1;
                        q.push(currPos);
                    }
 
                }
            }
        }
    }
 
    vector<int> monsterDistancesToExits (exits.size());
 
    for(int i = 0; i < exits.size(); i++)
    {
        monsterDistancesToExits[i] = distances[exits[i].y][exits[i].x];
    }
 
    vector<int> playerDistancesToExits (exits.size());
 
    //bfs playera
    q.push(playerPos);
    distances[playerPos.y][playerPos.x] = 0;
    while(!q.empty())
    {
        Pos curr = q.front();
 
        q.pop();
 
        for(int i = 0; i < 4; i++)
        {
            Pos currPos = curr + directions[i];
 
            if (currPos.y >= 0 && currPos.y < height && currPos.x >= 0 && currPos.x < width)
            {
                if (map[currPos.y][currPos.x] != '#')
                {
                    if (distances[currPos.y][currPos.x] > distances[curr.y][curr.x] + 1)
                    {
                        distances[currPos.y][currPos.x] = distances[curr.y][curr.x] + 1;
                        q.push(currPos);
                    }
 
                }
            }
        }
    }
    /*
    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            if (distances[y][x] == 1e9)
                cout << "B" << "|";
            else
                cout << distances[y][x] << "|";
        }
        cout << endl;
    }
    */
    for(int i = 0; i < exits.size(); i++)
    {
        if(distances[exits[i].y][exits[i].x] < monsterDistancesToExits[i]) // PLAYER DOTARL SZYBCIEJ
        {
            //backtracking, odtwarzanie sciezki
            string path = "";
            int currDist = distances[exits[i].y][exits[i].x];
            Pos pos = exits[i];
            while(true)
            {
                for(int j = 0; j < 4; j++)
                {
                    Pos currPos = pos + directions[j];
 
                    if (currPos.y >= 0 && currPos.y < height && currPos.x >= 0 && currPos.x < width)
                    {
                        //cout << currPos.y << " | " << currPos.x << " => " << distances[currPos.y][currPos.x] << endl;
                        if (distances[currPos.y][currPos.x] + 1 == currDist)
                        {   
                            currDist = distances[currPos.y][currPos.x];
                            //cout << currDist << endl;
                            pos = currPos;
                            path += dirToChar[j];
                        }
                    }
                }
                if (currDist == 0)
                    break;
            }
            cout << "YES" << endl;
            cout << path.size() << endl;
            for(int i = path.size() - 1; i >= 0; i--)
            {
                cout << path[i];
            }
            return 0;
        }
    }
 
    cout << "NO\n";
}